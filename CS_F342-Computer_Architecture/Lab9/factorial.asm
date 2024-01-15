.data
inpmsg: .asciiz "Enter the index: "
output: .asciiz "Output is: "

.text
main:
la $a0, inpmsg
li $v0, 4
syscall

li $v0, 5
syscall

move $a0, $v0
jal facfind

move $a0, $v0
li $v0, 1
syscall

li $v0, 10
syscall

facfind:
    addi $sp, $sp, -12
    sw $ra, 0($sp)
    sw $s0, 4($sp)
    sw $s1, 8($sp)

    move $s0, $a0
    blt $a0, 2, facbase

    addi $a0, $s0, -1
    jal facfind
    move $s1, $v0

    mul $v0, $s0, $s1
    j facret

facbase:
    li $v0, 1

facret:
    lw $ra, 0($sp)
    lw $s0, 4($sp)
    lw $s1, 8($sp)
    addi $sp, $sp, 12
    jr $ra