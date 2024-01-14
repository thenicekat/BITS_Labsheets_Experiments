.data
aword: .word 3
bword: .word 4

.text
main:
# Take float from user and is stored in $f0
li $v0, 6
syscall

lw $t1, aword
lw $t2, bword
mtc1 $t1, $f1
mtc1 $t2, $f2

# CONVERT WORD TO SINGLE PRECISION
cvt.s.w $f1, $f1
cvt.s.w $f2, $f2

# PERFORM A*x
mul.s $f0, $f1, $f0

# ADD B
add.s $f0, $f2, $f0

# PRINT
mov.s $f12, $f0
li $v0, 2
syscall

# EXIT
li $v0, 10
syscall