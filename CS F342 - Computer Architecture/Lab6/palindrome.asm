.data
thestr: .space 6
lstch: .asciiz "\nThe last character is: "
isPal: .asciiz "\nIt's a palindrome"
isNotPal: .asciiz "\nIt's not a palindrome"
newLine: .asciiz "\n"

.text
main:
lb $t4, newLine

# Take input of 6 chars
li $v0, 8
la $a0, thestr
li $a1, 6
syscall

# Try to find the length of the string
# We store base in $t2 and go until $t2 is equal to newline or \n
# It goes to next once it touches \0 or \n so to find the final character
# we should subtract 2

add $t2, $a0, $zero
slen:
	lb $t3, ($t2)
	addi $t2, $t2, 1	
	beq $t2, $t4, next # If current byte is \n
	bne $t3, $zero, slen
next:
	addi $t2, $t2, -2

la $a0, lstch
li $v0, 4
syscall

add $a0, $t2, $0
li $v0, 4
syscall

add $t1, $a0, $zero

# When you reach here, we have starting in $t1 and ending in $t2
testing_loop:
	bge $t1, $t2, is_palin
	lb $t3, 0($t1)
	lb $t4, 0($t2)
	bne $t3, $t4, is_not_palin
	addi $t1, $t1, 1
	addi $t2, $t2, -1
	j testing_loop

is_palin:
	la $a0, isPal
	li $v0, 4
	syscall
	j exit

is_not_palin:
	la $a0, isNotPal
	li $v0, 4
	syscall
	j exit

exit:
li $v0, 10
syscall