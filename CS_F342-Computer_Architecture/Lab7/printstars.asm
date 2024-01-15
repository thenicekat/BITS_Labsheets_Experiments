.data
star: .asciiz "*"
newline: .asciiz "\n"

.text
main:
li $v0, 5
syscall

move $t0, $0
move $t1, $v0

loop:
	blt $t1, $t0, exit
	move $a0, $t0
	jal print_stars
	move $a0, $t0
	jal print_stars
	addi $t0, $t0, 1
	j loop

exit:
	li $v0, 10
	syscall
	
print_stars:
	move $t3, $a0
	move $t4, $0
	
	printloop:
		beq $t4, $t3, exitPrint
		li $v0, 4
		la $a0, star
		syscall
		addi $t4, $t4, 1
		j printloop
	
	exitPrint:
		li $v0, 4
		la $a0, newline
		syscall
		jr $ra