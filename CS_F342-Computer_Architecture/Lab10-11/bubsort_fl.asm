.data
arr: .float 0.34023, 0.933079, 0.632925, 0.827597, 0.029821, 0.774891, 0.39910, 0.477, 0.0069, 0.0068
before: .asciiz "Elements before sorting: "
after: .asciiz "Elements after sorting: "

.text
main:
# Store the number of elements in t0
li $t0, 10
subu $t1, $t0, 1

# Print the string before
la $a0, before
li $v0, 4
syscall
# Print the floats
la $a1, arr
li $t2, 0
jal print_arr

# Print New Line
la $a0, 10
li $v0, 11
syscall

# initialize t2 with 0
li $t2, 0
# a0 acts as base address for all these
la $a0, arr

bubble_sort_outer:
	# t3 stores t2 + 1
	addi $t3, $t2, 1

	# you search for a number bigger
	bubble_sort_inner:
		# You store a in f2
		li $a1, 0
		sll $a1, $t2, 2
		add $a1, $a1, $a0
		l.s $f2, ($a1)
		# You store b in f4
		li $a1, 0
		sll $a1, $t3, 2
		add $a1, $a1, $a0
		l.s $f4, ($a1)

		# if f2 less than f4 no swap
		c.le.s $f2, $f4
		bc1t noswap

		# You put b in f4
		li $a1, 0
		sll $a1, $t2, 2
		add $a1, $a1, $a0
		s.s $f4, ($a1)
		# You put a in f2
		li $a1, 0
		sll $a1, $t3, 2
		add $a1, $a1, $a0
		s.s $f2, ($a1)

		# no swap branch
		noswap:
			addi $t3, $t3, 1
			blt $t3, $t0, bubble_sort_inner
		
	addi $t2, $t2, 1
	blt $t2, $t1, bubble_sort_outer

# Print the string after
la $a0, after
li $v0, 4
syscall
# Print array
la $a1, arr
li $t2, 0
jal print_arr	

# Exit
li $v0, 10
syscall

# Print function
print_arr:
	# Load into f12 from a1
	l.s $f12, ($a1)
	li $v0, 2
	syscall
	# Print character with ascii 16
	la $a0, 16
	li $v0 11
	syscall
	# recursively move forward
	addi $t2, $t2, 1
	addi $a1, $a1, 4
	blt $t2, $t0, print_arr
	jr $ra 