.data
sum_string: .asciiz "The sum of the numbers is: "
diff_string: .asciiz "The difference of the numbers is: "

.text
main:

# Take Input
li $v0, 5
syscall

# store in t0
move $t0, $v0

# Take Input
li $v0, 5
syscall

# store in t1
move $t1, $v0

# Compute sum
add $t2, $t0, $t1
sub $t3, $t0, $t1

# Print string for sum
la $a0, sum_string
li $v0, 4
syscall

# Print sum
move $a0, $t2
li $v0, 1
syscall


# Print string for diff
la $a0, diff_string
li $v0, 4
syscall

# Print diff
move $a0, $t3
li $v0, 1
syscall

# Exit
li $v0, 10
syscall