; Q1) Choose five numbers between 100 and 999. Write ALP by using conditional instructions for finding the largest
; of these five numbers and display the result as the output.


section .data
	num1 dd 143
	num2 dd 193
	num3 dd 100
	num4 dd 99
	num5 dd 444
 
	msg db "The max of 5 is: "
	mlen equ $ - msg
 
	strResult db "000"
    rlen equ $ - strResult
    nl db 0xa
 
section .text
	global _start
 
_start:
	mov   eax,4
	mov   ebx,1
	mov   ecx, msg
 	mov   edx, mlen
	int   0x80
 
 
	mov eax, [num1]
	cmp eax, [num2]
	jg compare_third	; num1 < num2
	mov eax, [num2]		; num2 > num1
 
compare_third:
	cmp eax, [num3]
	jg compare_forth	; num2 < num3
	mov eax, [num3]		; num3 < num2
 
compare_forth:
	cmp eax, [num4]
	jg compare_fifth	; num2 < num3
	mov eax, [num4]		; num3 < num2
 
 
compare_fifth:
	cmp eax, [num5]
	jg exit				; num2 < num3
	mov eax, [num5]		; num3 < num2
 
exit:	
	call print
 
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
