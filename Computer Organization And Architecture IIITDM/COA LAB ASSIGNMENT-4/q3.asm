section .data
  num dd 999 
  counter dd 0
  msg db "Given Number is "			                      ; string to be printed
  len equ $ - msg 			                              ; length of the string
  msg1 db "The given Number in Binary is: ", 0xA                      ; string to be printed
  len1 equ $ - msg1				                      ; length of the string
  new_line db 0xA                            	                      ; new line character
  new_len equ $ - new_line                     	                      ; length of newline	

segment .bss
  temp resb 10			 ; for storing num for print using int2str
  temp_len resd 1


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
  mov eax, [num]	         ; moving number to eax for printing
  print_int temp, temp_len
  print_string new_line, new_len
  print_string msg1, len1

  mov eax, [num]          ; move num to eax
  xor ecx, ecx            ; set ecx to zero which will contain stack size
  mov ebx, 2              ; move 2 to ebx which will be used for dividing

binary:
  xor edx, edx      ; set edx to zero
  div ebx           ; divide eax by 2
  push edx          ; push remainder (0/1) to stack
  inc ecx           ; increment ecx
  cmp eax, 0        ; check if anything left to divide
  jne binary        ; if something left then continue the process

print_binary:
  cmp ecx, 0            ; compare ecx and 0
  je _exit              ; if equal then nothing to print so exit
  pop eax               ; pop the value to eax
  add eax, '0'          ; convert it to ASCII (0/1)
  mov [temp], eax       ; move the char to temp
  mov [counter], ecx    ; move ecx to counter
  print_string temp, 1  ; print string
  mov ecx, [counter]    ; restore ecx
  dec ecx               ; decrement ecx
  jmp print_binary      ; continue with the printing if ecx is not zero

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
  ret 

