.data
arrayOfNumbers: .word 9, 5, 0, 2, 8, 3, 3, 1, 1
length: .byte 9
maxArr: .asciiz "\nThe maximum of this array is: "
minArr: .asciiz "\nThe minimum of this array is: "

.text
main:
la $t0, arrayOfNumbers      # t0 = arrayOfNumbers
lb $t1, length              # t1 = length
sll $t1, $t1, 2             # t1 *= 4
add $t1, $t1, $t0           # t1 = length + arrayOfNumbers

loop:
    beq $t0, $t1, exit      # if t0 = t1 exit
    lw $t3, ($t0)           # t3 = object at $t0
    addi $t0, $t0, 4        # t0 = t0 + 4
    bgt $t3, $t4, foundmax  # if t3 > t4 go to found max
    j loop
    foundmax:
        move $t4, $t3
        j loop

exit:
    la $a0, maxArr
    li $v0, 4
    syscall
    add $a0, $0, $t4
    li $v0, 1
    syscall
    li $v0, 10
    syscall