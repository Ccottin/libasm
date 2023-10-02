
section .data


global ft_strcpy

section .text

ft_strcpy :
	push	rbp
	mov		rbp, rsp

	mov		rax, rdi

	cmp		rsi, 0
	je		exit			; if src vide on exit

	copy:
		cmp byte	[rsi], 0
		je			exit			; if fin de chaine on exit
		mov			rbx, [rsi]		; copie le caractere dans temp
		mov			[rdi], rbx		; copie temp dans dest
		inc			rsi
		inc			rdi
		jmp			copy

	exit :
		mov		rsp, rbp
		pop		rbp
		ret	
