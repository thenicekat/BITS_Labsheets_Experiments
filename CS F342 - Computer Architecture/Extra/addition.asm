.data
addit: .asciiz "Enter two float numbers you want to add: "
ans: .asciiz "The answer is: "

.text
main:
la $a0, addit
li $v0, 4
syscall

li $v0, 6
syscall
mov.s $f2, $f0
li $v0, 6
syscall
mov.s $f4, $f0

jal add2nums
move $t0, $v0

la $a0, ans
li $v0, 4
syscall

move $a0, $t0
li $v0, 2
syscall

li $v0, 10
syscall


add2nums:
addi $t0, $0, 0
mtc1 $t0, $f0
add.s $f0, $f4, $f2
mov.s $f12, $f0

cvt.w.s $f12, $f12
mfc1 $t0, $f12
move $v0, $t0
jr $ra