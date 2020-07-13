SECTION .data
msg1     db "Hello, World", 0xa, 0x0
len1     equ $ - msg1

msg2     db "Namig Guseinov", 0xa, 0x0
len2     equ $ - msg2

error_msg db "Error", 0xa, 0x0

input_msg db "Input: ", 0x0

file_name db "test", 0x0

SECTION .bss
char     resb 1
chr      resd 1
string   resd 1
count    resd 1
buffer   resb 128
buffer2	 resb 128


str1 	 resd 1
str2 	 resd 1
res 	 resd 1

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
strlen_null:    cmp [esi], byte 0x0
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
putendl:
				call putstr
				mov al, 0xa
				mov [char], al
				call putchar
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
                 mov edx, 128
                 int 0x80
                 ret 

strrev:         
				xor eax, eax
                xor ecx, ecx
                mov ebx, [string]
strrev_null:    mov al, [ebx + ecx]
                cmp al, byte 0x0
                jz strrev_rev
                push ax
                inc ecx
                jmp short strrev_null
strrev_rev:     cmp ecx, dword 0x0 
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

char_toupper:  	
				xor eax, eax
				mov al, [char]
				cmp al, byte 'z'
				ja toupper_done
				cmp al, byte 'a'	
				jb toupper_done
				sub al, byte 32
				mov [char], al	
toupper_done:	ret

strupper: 		
				xor ecx, ecx
				xor eax, eax
				mov ebx, [string]
strupper_null:	mov al, [ebx + ecx]
				cmp al, byte 0xa
				jz strupper_done
				mov [char], al
				call char_toupper
				mov al, [char]
				mov [ebx + ecx], al
				inc ecx
				jmp strupper_null
strupper_done:	ret

char_tolower:  	
				xor eax, eax
				mov al, [char]
				cmp al, byte 'Z'
				ja tolower_done
				cmp al, byte 'A'	
				jb tolower_done
				add al, byte 32
				mov [char], al	
tolower_done:	ret

strlower: 		
				xor ecx, ecx
				xor eax, eax
				mov ebx, [string]
strlower_null:	mov al, [ebx + ecx]
				cmp al, byte 0xa
				jz strlower_done
				mov [char], al
				call char_tolower
				mov al, [char]
				mov [ebx + ecx], al
				inc ecx
				jmp strlower_null
strlower_done:	ret

putstr_fd:			
				mov eax, input_msg
				mov [string], eax

				call putstr
				call getstr

				mov eax, buffer
				mov [string], eax

				call strlen
				mov eax, [count]
				mov byte [buffer + eax - 1], 0x0 

				; OPEN
				mov eax, 5
				mov ebx, buffer
				mov ecx, 2
				int 0x80

				mov [res], eax

				mov eax, input_msg
				mov [string], eax

				call putstr
				call getstr

				mov eax, buffer
				mov [string], eax
				call strlen

				; WRITE
				mov eax, 4
				mov ebx, [res]
				mov ecx, buffer
				mov edx, [count]
				int 0x80

				; CLOSE
				mov eax, 6
				mov ebx, [res]
				int 0x80
				ret

				

_start:       

				;mov eax, test_msg
				;mov [string], eax
				;call putstr

				;mov eax, input_msg
				;mov [string], eax
				;call putstr
				;call getstr
				;mov eax, buffer
				;mov [string], eax
				;call strupper
				;call putstr 

				call putstr_fd

        		mov eax, 1      
        		mov ebx, 0     
        		int 0x80      
