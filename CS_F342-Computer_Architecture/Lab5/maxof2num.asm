.data
input1: .asciiz "Enter the first number: "
input2: .asciiz "Enter the second number: "
gt: .asciiz "The greater number is: "
newline: .asciiz "\n"

.text
main:
# Take input1
la $a0, input1
li $v0, 4
syscall
li $v0, 5
syscall

# Move it to t0
move $t0, $v0

# Take input2
la $a0, input2
li $v0, 4
syscall
li $v0, 5
syscall

# Move it to t1
move $t1, $v0

bgt $t0, $t1, zerogreater
bgt $t1, $t0, onegreater

zerogreater:
la $a0, gt
li $v0, 4
syscall
add $a0, $0, $t0
li $v0, 1
syscall
j exit

onegreater:
la $a0, gt
li $v0, 4
syscall
add $a0, $0, $t1
li $v0, 1
syscall
j exit

exit:
li $v0, 10
syscall