.data
inputLength: .asciiz "Enter the length of the array: "
inputArray: .asciiz "Enter the array elements: 0(start) "
true: .asciiz "The given input follows the increasing-decreasing pattern"
false: .asciiz "The given input does not follow the increasing-decreasing pattern"
array: .space 100

.text
main:
la $a0, inputLength
li $v0, 4
syscall

li $v0, 5
syscall

la $a0, inputArray
li $v0, 4
syscall

addi $t0, $0, 0     # t0 = 0
move $t1, $v0       # t1 = n
la $t2, array       # t2 = array_start
la $t3, array
add $t3, $t3, $t1  # t3 = array_end

# Store the state 1 means next should be greater 
# previous number is stored in $t5
li $t4, 1
li $t5, 0

loop:
    bgt $t2, $t3, exit
    
    li $v0, 5
    syscall

    move $t5, $v0

    bne $t4, $0, numbershouldbegreater

    numbershouldbesmaller:
    bge $t5, $t6, wrongexit
    addi $t6, $t5, 0
    addi $t4, $0, 1
    j loop

    numbershouldbegreater:
    ble $t5, $t6, wrongexit
    addi $t6, $t5, 0
    addi $t4, $0, 0
    j loop

j correctexit

wrongexit:
li $v0, 4
la $a0, false
syscall
j exit

correctexit:
li $v0, 4
la $a0, true
syscall
j exit

exit:
li $v0, 10
syscall
