; Given a positive number, write ALP for verifying whether 
; it is a prime number or not, and display the result as the output.


section .data
	msg1 db "The given number is prime!", 0xa, 0xd
	len1 equ $ - msg1

	msg2 db "The given number is not prime", 0xa, 0xd
	len2 equ $ - msg2

section .text
	global _start

_start:
	mov ecx, 7

	; get esi (num/2)
	mov eax, ecx
	mov bx, 2
	div bx
	mov esi, eax

div_loop:
	mov eax, ecx
	xor edx, edx
	cmp esi, 1
	je verdict_prime
	mov ebx, esi
	div ebx
	dec esi
	cmp edx, 0
	jne div_loop

verdict_not_prime:
	mov eax, 4
    	mov ebx, 1
    	mov ecx, msg2
   	mov edx, len2
    	int 0x80
    	jmp exit

verdict_prime:
    	mov eax, 4
    	mov ebx, 1
    	mov ecx, msg1
    	mov edx, len1
    	int 0x80
    	jmp exit

exit:
	mov eax, 1
	mov ebx, 0
	int 0x80
	
;------------------------------------------
; Integer printing function (itoa)
print_int:
    push    eax             ; preserve eax on the stack to be restored after function runs
    push    ecx             ; preserve ecx on the stack to be restored after function runs
    push    edx             ; preserve edx on the stack to be restored after function runs
    push    esi             ; preserve esi on the stack to be restored after function runs
    mov     ecx, 0          ; counter of how many place holders we need to print in the end
 
divideLoop:
    inc     ecx             ; count each byte to print - number of characters
    mov     edx, 0          ; empty edx
    mov     esi, 10         ; mov 10 into esi
    idiv    esi             ; divide eax by esi
    add     edx, 48         ; convert edx to it's ascii representation - edx holds the remainder after a divide instruction
    push    edx             ; push edx (string representation of an intger) onto the stack
    cmp     eax, 0          ; can the integer be divided anymore?
    jnz     divideLoop      ; jump if not zero to the label divideLoop
 
printLoop:
    dec     ecx             ; count down each byte that we put on the stack
    mov     eax, esp        ; mov the stack pointer into eax for printing
    call    print_str       ; call our string print function
    pop     eax             ; remove last character from the stack to move esp forward
    cmp     ecx, 0          
    jnz     printLoop       ; jump is not zero to the label printLoop
 
    pop     esi             ; restore esi from the value we pushed onto the stack at the start
    pop     edx             ; restore edx from the value we pushed onto the stack at the start
    pop     ecx             ; restore ecx from the value we pushed onto the stack at the start
    pop     eax             ; restore eax from the value we pushed onto the stack at the start
    ret
 

str_len:
    push    ebx             ; preserve ebx on the stack to be restored after function runs
    mov     ebx, eax        ; move eax into ebx
 
nextchar:
    cmp     byte [eax], 0   ; compare the byte pointed to by EAX at this address against zero (Zero is an end of string delimiter)
    jz      finished        ; jump (if the zero flagged has been set) to the point in the code labeled 'finished'
    inc     eax             ; increment the address in EAX by one byte (if the zero flagged has NOT been set)
    jmp     nextchar        ; jump to the point in the code labeled 'nextchar'
 
finished:
    sub     eax, ebx        ; subtract the address in EBX from the address in EAX
    pop     ebx             ; Restore the original value of ebx before our function was called
    ret
 
 
print_str:
    push    edx             
    push    ecx             
    push    ebx             
    push    eax             
    call    str_len         ; call the str_len length function to get length of passed message
 
    mov     edx, eax        ; store the string's lenth in edx for printing
    pop     eax             ; Restore the original value of eax before our function was called
 
    mov     ecx, eax        
    mov     ebx, 1          ; STDOUT
    mov     eax, 4          ; SYS_WRITE
    int     80h             
 
    pop     ebx             
    pop     ecx             
    pop     edx            
    ret
 
