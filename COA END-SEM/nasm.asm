;An assembly line program to convert a decimal number to octal
;by SRAVANTH CHOWDARY POTLURI CS20B1006

; A macro for printing string accepting 2 arguments (%1 , % 2) which are string and length of string respectively
%macro print_string 2 
  mov   eax, 4        
  mov   ebx, 1        
  mov   ecx, %1       
  mov   edx, %2       
  int   0x80          
%endmacro

; A macro for printing integer accepting 2 arguments (%1 , % 2) which are string and length of output string respectively
%macro print_int 2
  mov edi, %1                
  call int2str               
  sub edi, %1                
  mov [%2], edi
  print_string %1, [%2]
%endmacro



section .data
  num dd 85
  counter dd 0
  msg db "The Input Number to convert to octal is: "                                  
  len equ $ - msg                                         
  msg1 db "The given Number in Octal is: ", 0xA                      
  len1 equ $ - msg1                                   
  new_line db 0xA                                                     
  new_len equ $ - new_line                                            
  
  
segment .bss
  temp resb 10           
  temp_len resd 1





section .text

global _start

_start:
  print_string msg, len
  mov eax, [num]             ; moving number to eax for printing
  print_int temp, temp_len
  print_string new_line, new_len
  print_string msg1, len1

  mov eax, [num]          ; move num to eax
  xor ecx, ecx            ; set ecx to zero which will contain stack size
  mov ebx, 8              ; move 8 to ebx which will be used for dividing

octal:
  xor edx, edx      ; set edx to zero
  div ebx           ; divide eax by 8
  push edx          ; push remainder (0-7) to stack
  inc ecx           ; increment ecx
  cmp eax, 0        ; check if anything left to divide
  jne octal        ; if something left then continue the process

print_octal:
  cmp ecx, 0            ; compare ecx and 0
  je _exit              ; if equal then nothing to print so exit
  pop eax               ; pop the value to eax
  add eax, '0'          ; convert it to ASCII 
  mov [temp], eax       ; move the char to temp
  mov [counter], ecx    ; move ecx to counter
  print_string temp, 1  ; print string
  mov ecx, [counter]    ; restore ecx
  dec ecx               ; decrement ecx
  jmp print_octal      ; continue with the printing if ecx is not zero

_exit :
  mov eax, 1                  
  mov ebx,0                   
  int 0x80                    
  
  
int2str:                ; Converts an positive integer in EAX to a string pointed to by EDI
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
