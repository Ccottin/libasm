global	ft_read
extern __errno_location

section	.text
	
	ft_read:
		push	rbp
		mov		rbp, rsp

		mov		rax, 0			;syscall for read
		syscall					;all arguments are already set, sowe can do the syscall	
		cmp		rax, 0
		jl		set_errno		;jump if less
		jmp		exit

	set_errno:
		neg		rax				;the return value of syscall is negative value for errno,
		mov		rbx, rax		;so we reverse the sign
		call	__errno_location	;function to stock the adress of errno in rax
		mov		[rax], rbx		;	
		mov		rax, -1

	exit:
		mov			rsp, rbp
		pop			rbp
		ret
