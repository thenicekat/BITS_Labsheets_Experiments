.data
prompt: .asciiz "Enter Number of Students: "
name: .asciiz "Enter Name: "
roll: .asciiz "Enter ID: "
cg: .asciiz "Enter CGPA: "
pointers: .space 400
newline: .asciiz "\n"

.text
main:
# PRINT PROMPT
li $v0, 4
la $a0, prompt
syscall

# TAKE INPUT
li $v0, 5
syscall

# LOOP THROUGH THE NUMBER OF STUDENTS
# s0 stores student counter
# t0 temporary variable that starts with 0
# t1 stores address of current space
# t2 points to address of current pointer in pointers

move $s0, $v0
addi $t0, $0, 0

loop:
# ALLOCATE SPACE
li $v0, 9
li $a0, 40
syscall
move $t1, $v0

# GET POINTERS ARRAY AND STORE ADDRESS AT POINTERS[4*$t0]
la $t2, pointers
addi $t3, $0, 4
mul $t3, $t0, $t3
add $t2, $t2, $t3
sw $t1, 0($t2)

# ASK NAME
li $v0, 4
la $a0, name
syscall

# READ NAME
addi $a0, $t1, 0
li $v0, 8
li $a1, 20
syscall

# ASK ROLL
li $v0, 4
la $a0, roll
syscall

# READ ROLL
addi $a0, $t1, 20
li $v0, 8
li $a1, 10
syscall

# ASK CGPA
li $v0, 4
la $a0, cg
syscall

# READ CGPA
li $v0, 8
addi $a0, $t1, 30
li $a1, 10
syscall

# INCREMENT t0 AND MOVE ON
addi $t0, $t0, 1
bgt $s0, $t0, loop
#==========================================================================================
addi $t0, $0, 0

printloop:
# GET POINTERS ARRAY AND STORE ADDRESS AT POINTERS[4*$t0]
la $t2, pointers
addi $t3, $0, 4
mul $t3, $t0, $t3
add $t2, $t2, $t3
lw $t1, 0($t2)

# PRINT NAME
li $v0, 4
move $a0, $t1
syscall

# PRINT ROLL
addi $a0, $t1, 20
li $v0, 4
syscall

# PRINT CGPA
addi $a0, $t1, 30
li $v0, 4
syscall

# PRINT NEW LINE
li $v0, 4
la $a0, newline
syscall

# INCREMENT t4 AND MOVE ON
addi $t0, $t0, 1
bgt $s0, $t0, printloop

# EXIT
li $v0, 10
syscall