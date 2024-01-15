.data

.text
main:
# Take double input, it's stored in f0
li $v0, 7
syscall

# Convert double to float
cvt.s.d $f12, $f0

# move it to f12 and print to screen
li $v0, 2
syscall

# exit
li $v0, 10
syscall