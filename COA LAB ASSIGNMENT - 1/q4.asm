; Choose a positive value 5 ≤ P ≤ 20, write ALP by defining a P-element array containing P random values
; and do the sum of these values in the array and display the result as the output.


section .data
	global arr
	len db 6
	msg db "Sum of the array is: "
	mlen equ $ - msg
arr:				; declare the array
	dd 10
	dd 12
	dd 14
	dd 15
	dd 17
	dd 12
	
	strResult db "000"
    rlen equ $ - strResult
    nl db 0xa

section .text
	global _start

_start:
	; print the message
	mov   eax,4
	mov   ebx,1
	mov   ecx, msg
 	mov   edx, mlen
	int   0x80

	; prepare for the loop
	mov esi, 6		; pointer
	xor eax, eax	; eax will store the sum

sum_it:
	mov ebx,DWORD [arr+esi*4-4] ; move the data from current index to ebx
	add eax, ebx	; add the data to sum
	dec esi			; move the esi back
	test esi, esi
	jnz sum_it		; move up if esi != 0

	;; loop translates to following c code

	; int esi = 6;
	; int eax = 0;
	; while(esi!=0) {
	; 	ebx = arr[esi-1]
	; 	eax += ebx;
	; 	esi--;
	; }

	; print the number stored in esi with help of print section in util.asm
	call print

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