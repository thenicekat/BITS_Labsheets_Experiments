.data
prompt: .asciiz "Enter Input: "
result: .asciiz "Result: "

.text
main:
# PRINT PROMPT
li $v0, 4
la $a0, prompt
syscall

# TAKE INPUT
li $v0, 5
syscall

# FIND FIBONACCI
move $a0, $v0
jal fib
move $s0, $v0

# PRINT RESULT TEXT
li $v0, 4
la $a0, result
syscall

# PRINT INTEGER
li $v0, 1
move $a0, $s0
syscall

# EXIT
li $v0, 10
syscall

fib:
    subu $sp, $sp, 16 # frame size = 32, just because...
    sw $ra, 0($sp) # preserve the Return Address.
    sw $s0, 4($sp) # preserve $s0.
    sw $s1, 8($sp) # preserve $s1.
    sw $s2, 12($sp) # preserve $s2.

    move $s0, $a0 # get n from caller.
    blt $s0, 2, fib_base_case # if n < 2, then do base case.

    sub $a0, $s0, 1 # compute fib (n - 1)
    jal fib #
    move $s1, $v0 # s1 = fib (n - 1).

    sub $a0, $s0, 2 # compute fib (n - 2)
    jal fib
    move $s2, $v0 # $s2 = fib (n - 2).

    add $v0, $s1, $s2 # $v0 = fib (n - 1) + fib (n - 2).
    j fib_return

fib_base_case: # in the base case, return 1.
    li $v0, 1

fib_return:
    lw $ra, 0($sp) # restore the Return Address.
    lw $s0, 4($sp) # restore $s0.
    lw $s1, 8($sp) # restore $s1.
    lw $s2, 12($sp) # restore $s2.
    addu $sp, $sp, 16 # restore the Stack Pointer.
    jr $ra # return.