.data
memory: .word 12345678
string1: .asciiz "The input entered is: "
newLine: .asciiz "\n"
hexMap: .word '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
store: .space 80

.text
main:
la $t0, memory
lw $t1, 0($t0)

la $t4, store

li $t5, 0xF

la $a0, string1
li $v0, 4
syscall 

addi $a0, $t1, 0
li $v0, 1
syscall

la $a0, newLine
li $v0, 4
syscall 

li $t6, 0

loop:
ble $t1, $0, leave
and $t2, $t1, $t5

la $t3, hexMap
addi $a0, $t3, 0
sll $t2, $t2, 2
add $a0, $a0, $t2
sw $a0, 0($t4)
addi $t6, $t6, 1
addi $t4, $t4, 4

nextStep:
srl $t1, $t1, 4
j loop

leave:

la $a0, newLine
li $v0, 4
syscall 

la $t4, store
la $t5, store

addi $t6, $t6, -1
sll $t6, $t6, 2
add $t5, $t6, $t5

loop2:
bgt $t4, $t5, exit
addi $a0, $t5, 0
li $v0, 4
lw $a0, 0($t5)
addi $t5, $t5, -4
syscall
j loop2

exit:
li $v0, 10
syscall