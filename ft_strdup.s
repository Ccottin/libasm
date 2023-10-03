global	ft_strdup
extern	ft_strlen
extern	ft_strcpy
extern	malloc
extern	__errno_location

section .text

	ft_strdup :
		push	rbp
		mov		rbp, rsp

		mov		r8, rdi		;stocker la chaine a copier
		call	ft_strlen	;recuperer la taille de la chaine
		inc		rax			;octet null
		b0:
		mov		rdi, rax	;passer la taille en argument
		call	malloc		;allocation
		cmp		rax, 0		;gestion d erreur de malloc
		jl		set_errno	;jump if less
		mov		rdi, rax	;passer l adresse de malloc en premier arg
		mov		rsi, r8		;passer src en deuxieme arg	
		b1 :
		call	ft_strcpy	;copier la chaine 
		b2 :
	exit :
		mov		rsp, rbp
		pop		rbp
		ret

		
	set_errno:
		neg		rax				;the return value of syscall is negative value for errno,
		mov		rbx, rax		;so we reverse the sign
		call	__errno_location	;function to stock the adress of errno in rax
		mov		[rax], rbx		;
		mov		rax, -1
		jmp		exit

