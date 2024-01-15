.data
input: .asciiz "Please enter any number: "
output: .asciiz " is a factor of the given input\n"
newline: .asciiz "\n"

.text
main:

#Print input
la $a0, input
li $v0, 4
syscall

#Take input
li $v0, 5
syscall
#Store it in t0
move $t0, $v0

li $t1, 2

loop:
#If i > input, exit else loop
bgt $t1, $t0, exit
#Check if it's factor
div $t0, $t1
#Check reminder
mfhi $t3
bne $t3, $0, notafactor
beq $t3, $t0, factor

factor:
addi $a0, $t1, 0
li $v0, 1
syscall

la $a0, output
li $v0, 4
syscall

notafactor:
# increment i
addi $t1, $t1, 1
j loop

exit:
li $v0, 10
syscall