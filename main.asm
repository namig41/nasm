SECTION .data
msg1     db "Hello, World", 0xa, 0x0
len1     equ $ - msg1

msg2     db "Namig Guseinov", 0xa, 0x0
len2     equ $ - msg2

error_msg db "I am here", 0xa, 0x0

input_msg db "Input: ", 0x0

SECTION .bss
char     resb 1
chr      resd 1
string   resd 1
count    resd 1
buffer   resb 100

str1 	resd 1
str2 	resd 1
res 	resd 1

SECTION  .text
global _start           

strset:
                mov eax, [string]
                mov bl, byte [char]
strset_null:    cmp [eax], byte 0x0
                jz strset_done
                mov [eax], bl
                inc eax
                jmp short strset_null
strset_done:    ret

strchr:
                mov eax, [string]
                mov bl, [char]
strchr_null:    cmp [eax], byte 0x0
                jz strchr_done
                cmp [eax], bl
                jz strchr_done
                inc eax
                jmp short strchr_null
strchr_done:    mov [chr], eax
                ret

strlen:
                xor eax, eax 
                mov esi, [string]
strlen_null:    cmp [esi], byte 0
                jz strlen_done 
                inc eax
                inc esi
                jmp short strlen_null 
strlen_done:    mov [count], dword eax
                ret

putchar: 
                mov eax, 4
                mov ebx, 1
                mov ecx, char
                mov edx, 1
                int 0x80
                ret

putstr:         
                 call strlen
                 mov eax, 4
                 mov ebx, 1
                 mov ecx, [string]
                 mov edx, [count]
                 int 0x80
                 ret

getchar:
                 mov eax, 3
                 mov ebx, 0
                 mov ecx, char 
                 mov edx, 1 
                 int 0x80
                 ret 

getstr:
                 mov eax, 3
                 mov ebx, 0
                 mov ecx, buffer
                 mov edx, 100 
                 int 0x80
                 ret 

strrev:         xor eax, eax
                mov ebx, [string]
                xor ecx, ecx
strrev_null:    mov al, [ebx + ecx]
                cmp al, byte 0
                jz strrev_rev
                push ax
                inc ecx
                jmp short strrev_null
strrev_rev:     cmp ecx, dword 0 
                jz strrev_done 
                pop ax
                mov [ebx], al
                inc ebx
                loop strrev_rev
strrev_done:    ret

strcmp:			xor ecx, ecx
strcmp_loop: 	mov al, [str1 + ecx]
				mov bl, [str2 + ecx]
cmp_char:		cmp al, bl
				jne strcmp_done 
				loop strcmp_loop
strcmp_done:	add dword [res], eax
				add dword [res], eax
				ret

; strcpy:

_start:       
       ; call getstr
       ; mov eax, buffer
       ; mov [string], eax 
       ; call putstr

       ; mov eax, msg1
       ; mov [string], dword eax
       ; mov [char], byte '1'
       ; call putstr
       ; call strchr
       ; mov eax, [chr]
       ; mov [string], eax
       ; call putstr 

       ; mov eax, msg1
       ; mov [string], eax
       ; call putstr
       ; call strrev
       ; call putstr
       ; mov [char], byte 0xa
       ; call putchar

	 	mov eax, input_msg
		mov [string], eax
		call putstr
		call getstr
		mov eax, buffer
		mov [str1], eax

		mov eax, input_msg
		mov [string], eax
		call putstr
		call getstr
		mov eax, buffer
		mov [str2], eax 

		mov eax, [str1]
		mov [string], eax
		call putstr
		mov eax, [str2]
		mov [string], eax
		call putstr

        mov eax, 1      
        mov ebx, 0     
        int 0x80      
