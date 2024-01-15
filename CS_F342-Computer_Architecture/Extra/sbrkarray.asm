.data
inp: .asciiz "Enter number of elements to store: "
num: .asciiz "Enter number: "
multi: .asciiz "Enter the number you want to multiply all numbers with: "
newline: .asciiz "\n"

.text
main:
# Print the string
li $v0, 4
la $a0, inp
syscall

# Take integer input
li $v0, 5
syscall

# Allocate space using sbrk
move $a0, $v0
sll $a0, $a0, 2
li $v0, 9
syscall

# store base address in a2
# store number of elements in a1
move $a1, $a0
move $a2, $v0

# loop through and store these numbers
li $t0, 0
input_loop:
    # Print the string
    li $v0, 4
    la $a0, num
    syscall

    # Take integer input
    li $v0, 5
    syscall

    add $t1, $t0, 0
    add $t1, $t1, $a2
    sw $v0, ($t1)

    addi $t0, $t0, 4
bne $t0, $a1, input_loop

# Print the string
li $v0, 4
la $a0, multi
syscall

# Take integer input
li $v0, 5
syscall
move $t3, $v0

li $t0, 0
output_loop:
    # print symbol
    li $a0, 16
    li $v0, 11
    syscall

    add $t1, $t0, 0
    add $t1, $t1, $a2

    # get the number into $t2
    lw $t2, ($t1)
    mul $t2, $t2, $t3

    # print the number
    move $a0, $t2
    li $v0, 1
    syscall

    addi $t0, $t0, 4
bne $t0, $a1, output_loop

# exit
li $v0, 10
syscall