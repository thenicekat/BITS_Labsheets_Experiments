.data
inp: .asciiz "The input you entered is: "

.text
main:

li $v0, 6
syscall

cvt.w.s $f0, $f0
mfc1 $t0, $f0

li $v0, 4
la $a0, inp
syscall

addi $a0, $t0, 0
li $v0, 1
syscall

li $v0, 10
syscall

