global	ft_atoi_base
extern	ft_strlen

section .data
	forbidden_char : db 0x9, 0xa, 0xb, 0xc, 0xd, 20, 0


section .text


;;il est tard et cette loop me fait vraiment mal au crane!
;note pour plus tard = l idee, cest que quand l adresse du char 
;est egalement celle de ton index, tu jumpes
;pour l instant c toucasse ;B et le makefile aussi
check_base_1:
		
	push	rbp
	mov		rbp, rsp
	mov		rax, 1
	jmp		loop

incrloop:
	inc		rdi
loop:
	cmp		byte [rdi], 0	; si on est arrive a l'octet nul
	je		exit
	mov		bl, [rdi]		; stocker le char a comparer
	mov		r10, rdi		; mettre la chaine a comparer au premier char
	
	check_char:				; loop sur le char dans lb
		cmp rdi, r10
		je	ici
		cmp	bl, [r10]		; checker avec le charactere a l adresse r10
		je	handle_error	; si ils sont equals, error
		ici :
		inc	r10				; adresse suivante dans r10
		cmp	byte [r10], 0		; si c'est la fin de la chaine r10
		je	incrloop		; on incremente puis on revient a loop
		jmp	check_char		;sinon on continue

check_base_2:
		
	push	rbp
	mov		rbp, rsp
	mov		rax, 1
	jmp		loop

incrloop:
	inc		rdi
loop:
	cmp		byte [rdi], 0	; si on est arrive a l'octet nul
	je		exit
	mov		bl, [rdi]		; stocker le char a comparer
	mov		r10, rsi		; mettre la chaine a comparer au premier char
	
	check_char:				; loop sur le char dans lb
		cmp	bl, [r10]		; checker avec le charactere a l adresse r10
		je	handle_error	; si ils sont equals, error
		inc	r10				; adresse suivante dans r10
		cmp	byte [r10], 0		; si c'est la fin de la chaine r10
		je	incrloop		; on incremente puis on revient a loop
		jmp	check_char		;sinon on continue


ft_atoi_base:

	push	rbp
	mov		rbp, rsp
	cmp		rdi, 0
	je		handle_error
	mov		r8, rsi			; stocker la base 
	mov		r9, rdi			; stocker la valeur a convertir
	mov		rdi, rsi		; verifier la taille de la base
	call	ft_strlen
	cmp		rax, 1
	jle		handle_error
	
	call	check_base_1	; verifier si il n y a pas de doublon
	cmp		rax, 0			; si le check_base renvoie 0
	je		handle_error	; on exit
	mov		rsi, forbidden_char ;verifier les char interdits
	mov		rdi, r8
	call	check_base_2
	cmp		rax, 0			; si le check_base renvoie 0
	je		handle_error	; on exit
	
exit:
	mov		rsp, rbp
	pop		rbp
	ret

handle_error:
	mov		rax, 0
	jmp		exit
