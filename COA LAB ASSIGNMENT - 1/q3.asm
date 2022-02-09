; Write ALP by using recursion for finding a factorial
; of number between 5 and 30 and display the result
section .data
	num dd 12
	strResult db "000000000"
    rlen equ $ - strResult
    nl db 0xa
	
section .text
	global _start

_start:

;moving the required number for multiplication
mov ebx, [num]     
mov eax, 1    

loop:
;algorithm to find factorial using looping
    mul ebx          
    dec ebx          
    cmp ebx,0        
    je print         
    jmp loop


	;exit
	mov eax, 1
	mov ebx, 0
	int 0x80

print:
    mov ecx, 10
    xor ebx, ebx      ; digit counter

divide:
    xor edx, edx
    div ecx         ; eax = edx:eax/ecx, edx = remainder
    push dx         ; single digit
    inc bx          ; digit counter
    test eax, eax   ; is eax 0
    jnz divide      ; no, continue

    ;; length adjust
    xor esi, esi
    mov si, rlen
    sub si, bx

    ;; eax is now zero
    mov cx, bx      ; bx is num if digits

next_digit:
    pop ax
    add al, '0'
    mov [strResult+esi], al
    inc esi
    loop next_digit

    mov eax, 4
    mov ebx, 1
    mov ecx, strResult
    mov edx, rlen
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov ecx, nl
    mov edx, 1
    int 0x80

    mov ecx, rlen
zero_strResult:
    mov byte [strResult+ecx-1], "0"
    loop zero_strResult
    ret	