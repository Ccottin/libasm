
section .data

global ft_strcmp

section .text
	
	ft_strcmp:
		push	rbp
		mov		rbp, rsp

		mov		rax, 0

		cmp		rsi, 0					; verifiction des arguments
		je		exit
		cmp		rdi, 0
		je		exit

		loop:
			mov	al, [rdi]
			mov	bl, [rsi]
			sub	rax, rbx				;soustrait la valeur de [s2] a [s1]
			cmp	rax, 0					;verifie la valeur de rax
			je	increment
			jmp	exit


		increment:
			cmp	byte [rdi], 0
			je	exit					;si le char est 0 on exit
			cmp	byte [rsi], 0
			je	exit					;si le char est 0 on exit	
			inc	rdi
			inc	rsi
			jmp	loop

		exit:
			mov	rsp, rbp
			pop rbp
			ret
