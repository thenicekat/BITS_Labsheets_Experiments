.data
qtext: .asciiz "\nThe Quotient is: "
rtext: .asciiz "\nThe Reminder is: "
ptext: .asciiz "\nThe Product is: "

.text
main:
# Take input
li $v0, 5
syscall

# store input in $t0
move $t0, $v0

# Take input
li $v0, 5
syscall

# store input in $t1
move $t1, $v0

# Division time :)
div $t0, $t1

# High stores reminder
la $a0, rtext
li $v0, 4
syscall

mfhi $t3
move $a0, $t3
li $v0, 1
syscall

# Low stores quotient
la $a0, qtext
li $v0, 4
syscall

mflo $t3
move $a0, $t3
li $v0, 1
syscall

# Multiply
la $a0, ptext
li $v0, 4
syscall

mult $t0, $t1

mfhi $t3
move $a0, $t3
li $v0, 1
syscall

mflo $t3
move $a0, $t3
li $v0, 1
syscall

# exit
li $v0, 10
syscall