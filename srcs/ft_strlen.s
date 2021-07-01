section 	.text
	global _ft_strlen

_ft_strlen:
	xor		rax, rax 
	cmp		rdi, 0 
	je		exit 
	jmp		loop 

loop:
	cmp		BYTE[rdi + rax], 0 
	je		exit 
	inc		rax 
	jmp		loop 

exit:
	ret
