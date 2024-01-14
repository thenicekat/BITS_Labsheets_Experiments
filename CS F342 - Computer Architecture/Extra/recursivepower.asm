.data
inp: .asciiz "Enter a number: "
inp2: .asciiz "Enter a power: "
oup: .asciiz "Enter output: "

.text
main:
la $a0, inp
li $v0, 4
syscall

li $v0, 5
syscall

move $t0, $v0

la $a0, inp2
li $v0, 4
syscall

li $v0, 5
syscall

move $t1, $v0

move $a0, $t0
move $a1, $t1
jal findpower
move $t0, $v0

la $a0, oup
li $v0, 4
syscall

move $a0, $t0
li $v0, 1
syscall

li $v0, 10
syscall

findpower:
    addi $sp, $sp, -16
    sw $ra, 0($sp)
    sw $s0, 4($sp)
    sw $s1, 8($sp)
    sw $s2, 12($sp)

    move $s0, $a0
    move $s1, $a1
    ble $a1, 0, findpower_base

    addi $a0, $a0, 0
    addi $a1, $s1, -1
    jal findpower
    move $s2, $v0

    mul $v0, $s0, $s2
    j findpower_ret

findpower_base:
    li $v0, 1

findpower_ret:
    lw $ra, 0($sp)
    lw $s0, 4($sp)
    lw $s1, 8($sp)
    lw $s2, 12($sp)
    addi $sp, $sp, 16
    jr $ra


