.data
val1: .double 0.001
newline: .asciiz "\n"
addstr: .asciiz "Addition: "
substr: .asciiz "Subtraction: "
negstr: .asciiz "Negation: "
mulstr: .asciiz "Multiplication: "
divstr: .asciiz "Division: "
divinstr: .asciiz "Division upon converting these to integers: "
reminstr: .asciiz "Remainder upon converting these to integers: "

.text
printstring:
li $v0, 4
syscall
jr $ra

main:
# Take float input, it's stored in f1
li $v0, 6
syscall
# Store in $f1
mov.s $f1, $f0

# Take float input, it's stored in f2
li $v0, 6
syscall
# Store in $f2
mov.s $f2, $f0

# add
add.s $f12, $f1, $f2
# print add
la $a0, addstr
jal printstring
# move it to f12 and print to screen
li $v0, 2
syscall
# print new line
la $a0, newline
jal printstring

# sub
sub.s $f12, $f1, $f2
# print
la $a0, substr
jal printstring
# move it to f12 and print to screen
li $v0, 2
syscall
# print new line
la $a0, newline
jal printstring

# negate
neg.s $f12, $f1
# print
la $a0, negstr
jal printstring
# move it to f12 and print to screen
li $v0, 2
syscall
# print new line
la $a0, newline
jal printstring

# multiply
mul.s $f12, $f1, $f2
# print
la $a0, mulstr
jal printstring
# print number
li $v0, 2
syscall
# print new line
la $a0, newline
jal printstring

# division
div.s $f12, $f1, $f2
# print
la $a0, divstr
jal printstring
# print number
li $v0, 2
syscall
# print new line
la $a0, newline
jal printstring

# Convert float to word
cvt.w.s $f3, $f1
cvt.w.s $f4, $f2
# Move to main processor
mfc1 $t0, $f3
mfc1 $t1, $f4
# Divide
div $t0, $t1
# Store reminder in t3
mfhi $t3
# Store quotient in t4
mflo $t4
# Print string
la $a0, divinstr
jal printstring
# print quotient
move $a0, $t4
li $v0, 1
syscall
#print newline
la $a0, newline
jal printstring
# Print string
la $a0, reminstr
jal printstring
# print quotient
move $a0, $t3
li $v0, 1
syscall

# exit
li $v0, 10
syscall