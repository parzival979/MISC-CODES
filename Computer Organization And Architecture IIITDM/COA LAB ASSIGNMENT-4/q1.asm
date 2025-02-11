section .data
	num dd 20 	; for storing num till where we need to print out fib numbers(less than 49 for 32 bit registers)
	p1 dd 0          ; pointer 1 which is initialised to zero (fib(0))
	p2 dd 1          ; pointer 2 which is initialised to 1 (fib(1))
	counter dd 0     ; for preserving ecx
	msg1 db "Enter the number range: "
	len1 equ $- msg1
	msg2 db "FIBONACCI SERIES: "
	len2 equ $- msg2 
	space db " "                                        ; space character
	space_len equ $- space                              ; length of space
	new_line db 0xA                            	    ; new line character
	new_len equ $-new_line                     	    ; length of newline
	

segment .bss
	temp resb 10					 ; for storing num for printing fibonacci numbers
	temp_len resd 5				         ; for storing length of num

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
	print_string msg1, len1
	mov eax, [num]
	print_int temp, temp_len
	print_string new_line, new_len

	print_string msg2, len2
	print_string new_line, new_len

	; print 0
	mov eax, [p1]
	print_int temp, temp_len
	print_string space, space_len

	; print 1
	mov eax, [p2]
	print_int temp, temp_len
	print_string space, space_len
	
	mov ecx, [num]		; ecx will be used as a counter
	sub ecx, 2		; as we're already printing 0 and 1
	
	mov edx, [p1]            ; move fib(n-1) which is pointer1 to edx
	mov ebx, [p2]		 ; move fib(n-2) which is pointer2 to ebx	

fib_loop:
        cmp ecx, 0           ; comparing ecx with 0
        je _exit             ; if we're done with the range(ecx = 0) then exit
        mov eax, edx         ; move p1 and store in eax
        add eax, ebx         ; add p1 and p2 and store in eax

        mov [p1], ebx            ; preserving values so that they dont't get lost while printing
        mov [p2], eax
        mov [counter], ecx

        print_int temp, temp_len
        print_string space, space_len

        ; restoring values
        mov edx, [p1]            
        mov ebx, [p2]
        mov ecx, [counter]


        dec ecx                ; decrement counter
        jmp fib_loop           ; continue with the loop until done

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


