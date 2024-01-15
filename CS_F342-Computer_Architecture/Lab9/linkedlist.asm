.data
inp: .asciiz "Enter numbers to insert into linked list (0 to exit): "
pcurr: .asciiz "\nThe current node value and next address are resp: "
linkedlist: .word 0 0
space: .asciiz " "

.text
main:
la $a0, inp
li $v0, 4
syscall

la $a1, linkedlist
insert_loop: 
    li $v0, 5
    syscall
    # Check if 0
    beqz $v0, end_insertion
    # Allocate the value and put next pointer to null
    sw $v0, 0($a1)
    sw $0, 4($a1)
    # create new node
    li $a0, 8
    li $v0, 9
    syscall
    # Change pointer to point to new node
    sw $v0, 4($a1)
    # Reset them to 0
    move $a1, $v0
    sw $0, 0($a1)
    sw $0, 4($a1)
    # Continue iterating
    j insert_loop



end_insertion:
    la $a0, linkedlist
    jal print_ll

li $v0, 10
syscall

print_ll:
    move $s0, $a0

    la $a0, pcurr
    li $v0, 4
    syscall

    move $t0, $s0
    lw $a0, 0($t0)
    li $v0, 1
    syscall

    la $a0, space
    li $v0, 4
    syscall

    move $t0, $s0
    lw $a0, 4($t0)

    beqz $a0, print_ll_exit

    li $v0, 1
    syscall

    j print_ll

print_ll_exit:
    jr $ra