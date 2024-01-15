.data
new_line: .asciiz "\n"
arr1: .word 9, 5, 0, 2, 8, 3, 3, 1, 1, 1

.text
main:
# Print string for new line
la $a0, new_line
li $v0, 4
syscall

# Load address of array in $t0
la $t0, arr1
# Load the number 4 in $t1
li $t1, 4
# Take a counter for the loop
li $t2, 0
# Take a final point for the loop
li $t3, 40

# create a loop which exits if $t2 = $t3
print_phone: beq $t2, $t3, exit
lw $a0, 0($t0)
li $v0, 1
add $t0, $t0, $t1
add $t2, $t2, $t1
syscall
j print_phone

# Exit
exit:
li $v0, 10
syscall