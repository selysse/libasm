section		.text
	global	_ft_strcpy

_ft_strcpy:							
	push	rbp
	mov		rbp, rsp
	xor		rcx, rcx				

copy:
	cmp		[rsi + rcx], byte 0
	je		exit
	mov		dl, [rsi + rcx]
	mov		[rdi + rcx], dl
	inc		rcx
	jmp		copy
	
exit:
	mov		[rdi + rcx], byte 0
	mov		rax, rdi
	pop		rbp
	ret
