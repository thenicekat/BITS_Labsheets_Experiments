.data

.text
main:
# Take input
li $v0, 5
syscall

move $t0, $v0
addi $t3, $t0, 0
addi $t1, $0, 0 # SUM = 0
addi $t2, $0, 1 # CURR = 1


loop: ble $t0, $0, exit
add $t1, $t1, $t2 # SUM = SUM + CURR
addi $t2, $t2, 1 # CURR = CURR + 1
addi $t0, $t0, -1
j loop

exit:
# divide by n
div $t1, $t3
mflo $a0
li $v0, 1
syscall

# exit
li $v0, 10
syscall