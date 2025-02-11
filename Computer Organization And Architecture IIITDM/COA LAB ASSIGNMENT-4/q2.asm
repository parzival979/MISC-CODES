section .data
  num dd 8128	
  msg db "Given Number is "			                      ; string to be printed
  len equ $ - msg 			                              ; length of the string
  msg1 db "The Number given is a Perfect Number", 0xA                 ; string to be printed
  len1 equ $ - msg1				                      ; length of the string
  msg2 db "The Number given is not a Perfect Number", 0xA             ; string to be printed
  len2 equ $ - msg2				                      ; length of the string
  new_line db 0xA                            	        ; new line character
  new_len equ $ - new_line                     	        ; length of newline	

segment .bss
  sum resd 10              ; for storing sum
  temp resb 10	           ; for storing num for print using int2str
  temp_len resd 1	   ; for storing length of num


; A macro for printing string accepting 2 arguments (%1 , % 2) which are string and length of string respectively
%macro print_string 2 
  mov   eax, 4		  ; The system call for write (sys_write)
  mov   ebx, 1		  ; File descriptor 1 - standard output
  mov   ecx, %1		  ; move offset of 1st argument to ecx
  mov   edx, %2		  ; move length of 1st argument(2nd argument) to edx
  int   0x80		  ; call kernel
%endmacro

; A macro for printing integer accepting 2 arguments (%1 , % 2) which are string and length of output string respectively
%macro print_int 2
  mov edi, %1                ; Argument: Address of the target string
  call int2str               ; Get the digits of EAX and store it as ASCII
  sub edi, %1                ; EDI (pointer to the terminating NULL) - pointer to temp = length of the string
  mov [%2], edi
  print_string %1, [%2]
%endmacro

section .text

global _start

_start:
  print_string msg, len

  mov eax, [num]	            ; moving number to eax for printing
  print_int temp, temp_len  
  print_string new_line, new_len

  mov eax, 1            ; initialise sum to 1
  mov [sum], eax
  xor edx, edx          ; set edx to zero
  mov eax, [num]        ; move num to eax
  mov ebx,2 		; move 2 to ebx
  div ebx		; eax is divide by ebx which is 2
  mov ecx, eax		; we'll be checking factors from (largest factor)num/2 to 2(least factor)
  jmp build_sum

add_to_sum :
  mov ebx, [sum]       ; move sum to ebx
  add ebx, ecx         ; add factor to ebx
  mov [sum], ebx       ; mov back the result sum to sum
  dec ecx              ; decrement ecx and check for the next divisor
	
build_sum:
  cmp ecx, 1		; checking if we have reached 1
  je check_perfect      ; if yes then check of sum is equal to num
  xor edx,edx 		; setting edx to 0 
  mov eax, [num]	; moving number to eax
  div ecx 		; dividing number(eax) with ecx
  cmp edx,0             ; if remainder is 0 then it's a factor
  je add_to_sum         ; add it to sum
  dec ecx		; decrement the divisor and going to the next factor(in decreasing order)
  jmp build_sum         ; continue with the loop

	
check_perfect:
    mov eax, [num]      ; mov num to eax
    cmp eax, [sum]      ; compare num and sum
    je is_perfect       ; if equal and then jump to is_perfect else go to not_perfect
    
not_perfect:
    print_string msg2, len2
    jmp _exit

is_perfect:
    print_string msg1, len1
    jmp _exit

_exit :
  mov eax, 1                  ; The system call for exit (sys_exit)
  mov ebx,0                   ; exit with error code 0
  int 0x80                    ; call kernel
	

int2str:    			; Converts an positive integer in EAX to a string pointed to by EDI
  xor ecx, ecx
  mov ebx, 10
  .LL1:                   ; First loop: Save the remainders
  xor edx, edx            ; Clear EDX for div
  div ebx                 ; EDX:EAX/EBX -> EAX Remainder EDX
  push dx                 ; Save remainder
  inc ecx                 ; Increment push counter
  test eax, eax           ; Anything left to divide?
  jnz .LL1                ; Yes: loop once more
  .LL2:                   ; Second loop: Retrieve the remainders
  pop dx                  ; In DL is the value
  or dl, '0'              ; To ASCII
  mov [edi], dl           ; Save it to the string
  inc edi                 ; Increment the pointer to the string
  loop .LL2               ; Loop ECX times

  mov byte [edi], 0       ; Termination character
  ret                     ; RET: EDI points to the terminating NULL
