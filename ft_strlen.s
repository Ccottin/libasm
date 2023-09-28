
section .data
	

global	ft_strlen

section	.text

ft_strlen :
	push	rbp
	mov		rbp, rsp

	mov		rax, 0		;initialiser la valeur du retour a 0
	cmp		rdi, 0			;verifier aue l adresse ne point pas sur null
	je		exit
	count:
		cmp byte [rdi], 0	;compare la valeur a l adresse rdi avec 0
		je	exit			;Jump if Equal au bloc exit
		inc	rax				;rax++
		inc	rdi				;adresse rdi++
		jmp	count
	
	exit :
		mov		rsp, rbp
		pop		rbp
		ret
