
section .data


global ft_strcpy

section .text

ft_strcpy :
	push	rbp
	mov		rbp, rsp

	mov		rax, rdi

	cmp		rdi, 0
	je		exit

	copy:
		cmp byte	[rsi], 0
		je			exit		 ;if fin de chaine on exit
		mov	byte	rdi, [rsi] ; copie le caractere dans dest
		inc			rsi
		inc			rdi
		jmp			copy

	exit :
		mov		rsp, rbp
		pop		rbp
		ret	
