section		.text
	global	_ft_strcmp

_ft_strcmp:				
	push	rbp
	mov		rbp, rsp
	xor		rcx, rcx					

loop:
	mov		dl, [rdi + rcx]				
	mov		dh, [rsi + rcx]				
	cmp		dl, 0
	je		exit
	cmp		dh, 0
	je		exit
	cmp		dh, dl
	jne		exit
	inc		rcx
	jmp		loop
	
exit:
	movzx	eax, dl
	movzx	ecx, dh
	sub		eax, ecx
	pop		rbp
	ret
