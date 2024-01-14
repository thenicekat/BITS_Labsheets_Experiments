.data
inp: .asciiz "Enter input: "
out: .asciiz "Enter output: "

.text
main:
la $a0, inp
li $v0, 4
syscall

li $v0, 5
syscall

move $a0, $v0
jal findsum
move $s0, $v0

la $a0, out
li $v0, 4
syscall

move $a0, $s0
li $v0, 1
syscall

li $v0, 10
syscall

findsum:
    addi $sp, $sp, -12
    sw $ra, 0($sp)
    sw $s0, 4($sp)
    sw $s1, 8($sp)

    move $s0, $a0
    ble $a0, 0, findsum_base

    addi $a0, $s0, -1
    jal findsum
    move $s1, $v0

    add $v0, $s0, $s1
    j findsum_ret 

findsum_base:
    li $v0, 0

findsum_ret:
    lw $ra, 0($sp)
    lw $s0, 4($sp)
    lw $s1, 8($sp)
    addi $sp, $sp, 12
    jr $ra