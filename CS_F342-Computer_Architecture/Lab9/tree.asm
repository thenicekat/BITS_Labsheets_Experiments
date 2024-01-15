.data

root: .word 0x0 0x0 0x0             # predefining root node as NULL
input: .asciiz "Enter numbers to insert into binary tree (0 to stop): \n"
output: .asciiz "Inorder traversal of the binary search tree: "

.text

main:
    la $a0, input
    li $v0, 0x4
    syscall
    li $v0, 0x5
    syscall                         # enter first number
    beqz $v0, end_of_loop1
    la $a0, root                    # load root address into $a0 for inserting values into BST
    sw $v0, ($a0)
	
    loop1:
        li $v0, 0x5                 # enter subsequent numbers
        syscall
        beqz $v0, end_of_loop1      # jump out of current loop if 0 is entered
        jal insert                  # call subroutine to insert into BST
        j loop1

    end_of_loop1:
        la $a0, output
        li $v0, 0x4
        syscall
        la $a0, root                # load address of root node for inorder function, $a0 will always contain address of tree/subtree to call inorder traversal
        jal inorder                 # call inorder function
        li $v0, 0xa
        syscall

insert:
    move $t0, $v0
    li $a0, 0xc
    li $v0, 0x9
    syscall                         # allocate space for 12/4 = 3 integers (one for value, one for left pointer address, one for right pointer address)
    sw $t0, ($v0)                   # store input value into newly created node
    sw $0, 0x4($v0)                 # set left pointer of node to NULL
    sw $0, 0x8($v0)                 # set right pointer of node to NULL
    la $a0, root
    loop2:
        beqz $a0, end_of_loop2      # while pointer is not pointing to NULL node
        lw $t1, ($a0)               # obtain value from pointer
        bgt $t0, $t1, move_right    # compare it with input value, if lesser then move pointer to right, else move pointer to left
            addi $a1, $a0, 0x4      # to not lose track of current pointer address
            lw $a0, 0x4($a0)        # +4 to move it by 1 word (to the left pointer)
            j done1
        move_right:
            addi $a1, $a0, 0x8      # to not lose track of current pointer address
            lw $a0, 0x8($a0)        # +8 to move it by 2 words (to the right pointer)
        done1:
            j loop2
    end_of_loop2:
        sw $v0, ($a1)               # set left/right pointer to point to newly created node
    jr $ra

inorder:
    beqz $a0, end_of_inorder        # check if NULL node or not
    subu $sp, $sp, 0x8              # decrease stack pointer by 8/4 = 2 words to accomodate two integers (current pointer address and code return address)
    sw $a0, ($sp)                   # save (push) arguments into the stack
    sw $ra, 0x4($sp)
    lw $a0, 0x4($a0)                # obtain address of left node
    jal inorder                     # call inorder traversal on left subtree
    lw $ra, 0x4($sp)                # restore arguments from stack after function call
    lw $a0, ($sp)
    addi $sp, $sp, 0x8              # restore stack pointer

    move $t0, $a0                   # temporarily save pointer address into a separate register
    lw $a0, ($a0)                   # obtain integer from current node
    li $v0, 0x1
    syscall                         # print current integer
    li $a0, 0x20
    li $v0, 0xb
    syscall                         # print whitespace
    move $a0, $t0                   # restore pointer address
    
    subu $sp, $sp, 0x8              # decrease stack pointer by 8/4 = 2 words to accomodate two integers (current pointer address and code return address)
    sw $a0, ($sp)                   # save (push) arguments into the stack
    sw $ra, 0x4($sp)
    lw $a0, 0x8($a0)                # obtain address of right node
    jal inorder                     # call inorder traversal on right subtree
    lw $ra, 0x4($sp)                # restore arguments from stack after function call
    lw $a0, ($sp)
    addi $sp, $sp, 0x8              # restore stack pointer
    end_of_inorder:
        jr $ra
