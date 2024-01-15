.data
cf: .asciiz "\nCurrent Char: "
found: .asciiz "\nCharacter Found"
notfound: .asciiz "\nCharacter Not Found"
char_tosearch: .byte 'f'
char_array: .byte 'd', 'i', 'v', 'y', 'a', 'l', 0

.text
main:
lb $t2, char_tosearch
la $t0, char_array

loop:
    lb $t1, ($t0)

    la $a0, cf
    li $v0, 4
    syscall

    add $a0, $0, $t0
    li $v0, 4
    syscall

    beq $t1, $zero, notfou
    beq $t1, $t2, fou
    addi $t0, $t0, 1
    j loop

j notfou

fou:
la $a0, found
li $v0, 4
syscall
j exit

notfou:
la $a0, notfound
li $v0, 4
syscall
j exit

exit:
li $v0, 10
syscall