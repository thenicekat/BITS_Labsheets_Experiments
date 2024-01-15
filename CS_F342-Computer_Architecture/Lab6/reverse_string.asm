.data
input: .space 6
output: .space 6
inputstr: .asciiz "\nThe input string is: "
outputstr: .asciiz "\nThe output is : "


.text
main:
li $v0, 8
la $a0, input
li $a1, 6
syscall


# t1 = output end
# t2 = input end
la $t0, input
la $t1, output
li $t2, 5
add $t1, $t2, $t1
add $t2, $t2, $t0
addi $t1, $t1, -1


loop:
    bgt $t0, $t2, exit
    lb $t3, 0($t0)
    sb $t3, 0($t1)
    addi $t0, $t0, 1
    addi $t1, $t1, -1
    j loop

exit:
    la $a0, inputstr
    li $v0, 4
    syscall

    la $a0, input
    li $v0, 4
    syscall

    la $a0, outputstr
    li $v0, 4
    syscall

    la $a0, output
    li $v0, 4
    syscall

    li $v0, 10
    syscall