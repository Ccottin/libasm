
extern	ft_strlen

section	.data
	str: DB 'Hello World!', 10

global	_start

section	.text

	_start :
	push	rbp
	mov		rbp, rsp

	mov		rdi, str
	call	ft_strlen
	push	rax ; mettre le retour au sommet de la pile

	mov		rax, 4 ; syscall write
	mov		rbx, 1 ; stdout
	mov		rcx, rsp ;copier le sommet de la pile dans rcx
	mov		rdx, 2 ;pour l instant c est deux faut trouver mieux
	int		0x80 ;on passe le tout au kernel

	mov		rax, 1 ; syscall quit
	mov		rbx, 0 ; code d' erreur
	int		0x80

	mov		rsp, rbp
	pop		rbp
	ret
