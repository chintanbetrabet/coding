.model tiny
.486
.data
alph1 DB 100dup
count equ 5
capson macro 
	cmp al,'a'
	JL X1
	cmp al,'z'
	JG X1
	sub al,20h
	X1: endm
.code 
.startup
	lea si,alpha1
	mov cx,count
	x2:
	mov al,[si]
	capson
	inc si
	dec cx
	Jnz x2;
end
.exit 