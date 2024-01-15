## https://codeforces.com/problemset/problem/1873/B

.data
arr: .space 100
inputString: .asciiz "Please enter a number: "
outputString: .asciiz "The output is: "
minString: .asciiz "The minimum number is: "
newLine: .asciiz "\n"

.text
main:
# Take integer input
li $v0, 5
syscall

# Store it in $t0 and store address of arr in $t1
# Then iteratively take input
move $t0, $v0
la $t1, arr
la $t2, arr
add $t2, $t2, $t0

addi $t4, $0, 1
addi $t5, $0, 10

# Now t2 stores end of array an t1 the start of array
# And $t0 contains 0, so we try to put the minimum number in this
takeInput:
    beq $t1, $t2, noMoreInput
    # li $v0, 4
    # la $a0, inputString
    # syscall

    li $v0, 5
    syscall
    
    bge $v0, $t5, notLessThan
    addi $t5, $v0, 0

    notLessThan:
    sb $v0, 0($t1)
    addi $t1, $t1, 1
    j takeInput

noMoreInput:
la $t2, arr

# Now here $t2 will hold start and $t1 will hold end
# $t5 contains minimum
addi $t3, $0, 1

# li $v0, 4
# la $a0, minString
# syscall

# addi $a0, $t5, 0
# li $v0, 1
# syscall

loop:
    ble $t1, $t2, done
    lb $t0, 0($t2)
    addi $t2, $t2, 1

    beq $t5, $t0, multiplyPlus
    mul $t3, $t3, $t0
    j loop

    multiplyPlus:
    add $t0, $t0, $t4
    addi $t4, $0, 0
    mul $t3, $t3, $t0
    j loop

done:
    # li $v0, 4
    # la $a0, outputString
    # syscall

    addi $a0, $t3, 0
    li $v0, 1
    syscall

li $v0, 10
syscall