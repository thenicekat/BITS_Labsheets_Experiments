.data
val1: .double 0.001

.text
main:
# Take float value from variable
l.d $f12, val1
li $v0, 3
syscall

# Take float input, it's stored in f0
li $v0, 7
syscall

# move it to f12 and print to screen
mov.d $f12, $f0
li $v0, 3
syscall

# exit
li $v0, 10
syscall