.data
msg: .asciiz "Number: "
new_line: .asciiz "\n"

.text
main:
# Take input first
li $v0, 5
syscall

# Store input in $t0
move $t0, $0
move $t0, $v0

# Store the value of 1 in $t1
addi $t1, $0, 1

# Loop part
loop: ble $t0, $0, notEqual
sub $t0, $t0, $t1

la $a0, msg
li $v0, 4
syscall

move $a0, $t0
li $v0, 1
syscall

la $a0, new_line
li $v0, 4
syscall

j loop

notEqual:

# Exit
li $v0, 10
syscall