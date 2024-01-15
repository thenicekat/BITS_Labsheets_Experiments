.data
val1: .float 0.001

.text
main:
# Take float value from variable
l.s $f12, val1
li $v0, 2
syscall

# Take float input, it's stored in f0
li $v0, 6
syscall

# move it to f12 and print to screen
mov.s $f12, $f0
li $v0, 2
syscall

# exit
li $v0, 10
syscall