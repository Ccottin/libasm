global	ft_write
extern __errno_location

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
		neg		rax
		mov		rbx, rax
		call	__errno_location
		mov		[rax], rbx
		mov		rax, -1

	exit:
		mov			rsp, rbp
		pop			rbp
		ret
