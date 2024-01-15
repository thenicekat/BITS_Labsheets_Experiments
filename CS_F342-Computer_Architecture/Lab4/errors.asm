.data
aword: .word 3
bword: .word 4
norstr: .asciiz "Multiplying in Normal: "
flostr: .asciiz "Multiplying in Single Precision: "
doustr: .asciiz "Multiplying in Double Precision: "
newline: .asciiz "\n"
errstr: .asciiz "Error: "

.text
main:
lw $t1, aword
lw $t2, bword

# MULTIPLY
mul $t3, $t1, $t2
# PRINT
la $a0, norstr
li $v0, 4
syscall
add $a0, $t3, $0
li $v0, 1
syscall
la $a0, newline
li $v0, 4
syscall

# MOVE TO CO PROCESSOR 1
mtc1 $t1, $f1
mtc1 $t2, $f2

# CONVERT WORD TO SINGLE PRECISION
cvt.s.w $f1, $f1
cvt.s.w $f2, $f2

mtc1 $0, $f14

# MULTIPLY SINGLE PRECISION
mul.s $f4, $f1, $f2
# PRINT
la $a0, flostr
li $v0, 4
syscall
add.s $f12, $f4, $f14
li $v0, 2
syscall
la $a0, newline
li $v0, 4
syscall

# CONVERT SINGLE PRECISION TO DOUBLE PRECISION
cvt.d.s $f1, $f1
cvt.d.s $f2, $f2

# MULTIPLY DOUBLE PRECISION
mul.d $f6, $f1, $f2
# PRINT
la $a0, doustr
li $v0, 4
syscall
add.d $f12, $f6, $f14
li $v0, 3
syscall
la $a0, newline
li $v0, 4
syscall

# PRINT
mov.s $f12, $f0
li $v0, 2
syscall

# EXIT
li $v0, 10
syscall