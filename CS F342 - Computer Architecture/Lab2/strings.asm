.data
myMsg: .asciiz "You have entered the following data: "

.text
main:

# Take Input
li $v0, 5
syscall

# store in t0
move $t0, $v0

# Print string
la $a0, myMsg
li $v0, 4
syscall

# Print input
move $a0, $t0
li $v0, 1
syscall

# Exit
li $v0, 10
syscall