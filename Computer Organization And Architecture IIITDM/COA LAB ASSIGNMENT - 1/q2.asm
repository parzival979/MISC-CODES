; Q2) Choose a random number 20 ≤ R ≤ 100, write ALP by using loops for printing the numbers (i.e. from 1 to
; R) and display the result as the output.

section .data
;declaring the required data
	num dd 25
	start dd 1
	strResult db "000"
    rlen equ $ - strResult
    nl db 0xa
	
section .text
	global _start

_start:
mov ebx,[num]
inc ebx
mov [num],ebx

loop:
	mov eax, [start]	
    ; print the number
	call print

	mov eax, [start] 	; store the number in eax
	inc eax			; increment the number
	mov [start], eax	; mov the number back into start
	cmp eax,[num]	
	jne loop 		; if eax != num loop

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