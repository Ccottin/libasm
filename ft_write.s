section	.data
	extern ___error

global	ft_write

section	.text
	
	ft_write:
		push	rbp
		mov		rbp, rsp

		mov		rax, 1			;syscall for write
		syscall					;all arguments are already set, sowe can do the syscall	
		cmp		rax, 0
		jl		set_errno
		jmp		exit

	set_errno:
		mov		[___error], rax	
		neg		qword [___error]
		mov		rax, -1

	exit:
		mov			rsp, rbp
		pop			rbp
		ret
