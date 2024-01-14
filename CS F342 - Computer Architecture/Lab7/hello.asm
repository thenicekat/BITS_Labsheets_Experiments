.data
line: .asciiz "\n"
print_str: .asciiz "Hello World!"

.text
main:

li $a0, 10
la $a1, print_str
la $a2, line


# Here we print 20 first
jal increase_the_value

# Here we print
jal print_value

li $v0, 10
syscall


increase_the_value:
	# 4 bytes for each value
	# First we take 2 places
	# Since it's calling print value we need to keep track of initial value also
	# We put a0 at sp
	# we put ra in sp + 4
	addi $sp, $sp, -8 
	sw $a0, ($sp)
	sw $ra, 4($sp)
	
	# We increase value by 10
	addi $a0, $a0, 10
	
	# We call print value with a0 = 10
	jal print_value
	
	lw $a0, ($sp)
	lw $ra, 4($sp)
	addi $sp, $sp, 8
	jr $ra

print_value:
	addi $sp, $sp, -4
	sw $a0,($sp)
	move $a0, $a1
	
	li $v0, 4
	syscall

	lw $a0,($sp)
	
	li $v0, 1
	syscall

	move$a0, $a2

	li $v0, 4
	syscall

	lw $a0, ($sp)
	addi $sp, $sp, 4

	jr $ra