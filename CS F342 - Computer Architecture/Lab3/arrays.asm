.data
input_message: .asciiz "Please enter an index: "
input_message2: .asciiz "Please enter a number: "
prev: .asciiz "Current Number is: "
next: .asciiz "New Number is: "
elems: .word 10 20 30 40 50

.text
main:
# Ask for input
la $a0, input_message
li $v0, 4
syscall

# Take input
li $v0, 5
syscall

# store input in $t0
move $t0, $v0

# multiply index by 4
sll $t0, $t0, 2

# find the number
la $t1, elems
add $t1, $t1, $t0

# Print text and current number
la $a0, prev
li $v0, 4
syscall

lw $a0, 0($t1)
li $v0, 1
syscall

# print second input
la $a0, input_message2
li $v0, 4
syscall

# take integer input
li $v0, 5
syscall

# store the new value
sw $v0, 0($t1)

# Print text and new number
la $a0, next
li $v0, 4
syscall

lw $a0, 0($t1)
li $v0, 1
syscall

# exit
li $v0, 10
syscall