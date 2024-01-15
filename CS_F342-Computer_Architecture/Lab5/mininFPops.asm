.data
float1 : .asciiz "Enter first float:"
float2 : .asciiz "Enter second float:"
newLine : .asciiz "\n"
equal : .asciiz "both numbers are equal"
minimum : .asciiz "The minimum no. is : "
maximum : .asciiz "\nThe maximum no. is : "

.text
main:
# Take input 1 into f1
la $a0, float1
li $v0,4
syscall
li $v0,6
syscall
mov.s $f1,$f0

# Take input2 into f2
la $a0, float2
li $v0,4
syscall
li $v0,6
syscall
mov.s $f2,$f0

# Now we compare them
c.lt.s $f1, $f2
bc1f f2lessthanf1

f1lessthanf2:
la $a0, minimum
li $v0,4
syscall
mov.s $f12, $f1
li $v0, 2
syscall
la $a0, maximum
li $v0,4
syscall
mov.s $f12, $f2
li $v0, 2
syscall
j exit

f2lessthanf1:
la $a0, minimum
li $v0,4
syscall
mov.s $f12, $f2
li $v0, 2
syscall
la $a0, maximum
li $v0,4
syscall
mov.s $f12, $f1
li $v0, 2
syscall
j exit

exit:
li $v0, 10
syscall