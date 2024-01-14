.data
input: .space 60

.text
main:
# Take input
li $v0, 5
syscall

# Store space in buffer
la $a0, input
# store input in $a1 to truncate
move $a1, $v0

# Take String input
li $v0, 8
syscall

la $a0, input
li $v0, 4
syscall

# exit
li $v0, 10
syscall