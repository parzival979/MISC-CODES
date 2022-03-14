;Printing the word,consonants,vowels and characters


; print string
   %macro write_string 2 
      mov   eax, 4
      mov   ebx, 1
      mov   ecx, %1
      mov   edx, %2
      int   0x80
   %endmacro

section .data
    msg1 db "words: "
    len1 equ $-msg1

    msg2 db "characters: "
    len2 equ $-msg2

    msg3 db "vowels: "
    len3 equ $-msg3

    msg4 db "consonants: "
    len4 equ $-msg4

    newline db 0xa, 0xc
    linelen equ $-newline

    string db "assembly codes are way too big"
    len equ $-string

    words dq 0
    chars dq 0
    vowels dq 0
    consonants dq 0

section .text
	global _start

_start:
	mov ecx, len 	; characters (non-space)
	mov ebx, 0		; vowel
	mov edx, 0		; words
	mov esi, 0		; consonants

process_space:
	inc edx
	dec ecx
	inc esi

compute:
	mov al, [string+esi]

	cmp al, ' '
	je process_space

	cmp al, 'a'
	je vowel
	cmp al, 'e'
	je vowel
	cmp al, 'i'
	je vowel
	cmp al, 'o'
	je vowel
	cmp al, 'u'
	je vowel

	jmp not_vowel

	vowel:
		inc ebx

	not_vowel:
		inc esi

	loop compute

	; we have the vowels
	mov [vowels], ebx
	
	; get number of consonants
	mov ecx, len
	sub ecx, edx	; subtract the number of spaces
	sub ecx, ebx	; subtract the number of vowels
	mov [consonants], ecx

	; get number of words
	inc edx 	; process the last word
	mov [words], edx

	; get number of charachters (non-space)
	mov eax, [vowels]
	mov ebx, [consonants]
	add eax, ebx
	mov [chars], eax

	write_string msg1, len1
	mov eax, [words]
	call print_int
	write_string newline, linelen

	write_string msg2, len2
	mov eax, [chars]
	call print_int
	write_string newline, linelen

	write_string msg3, len3
	mov eax, [vowels]
	call print_int
	write_string newline, linelen

	write_string msg4, len4
	mov eax, [consonants]
	call print_int
	write_string newline, linelen

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
 
