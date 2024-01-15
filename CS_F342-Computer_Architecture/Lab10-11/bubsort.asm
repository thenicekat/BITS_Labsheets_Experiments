.data
list: .word 17, 5, 92, 87, 41, 10, 23, 55, 72, 36
space: .asciiz " "

.text
main:
li $s7,10 #size of the list(sz)

#Write the loop, swap code here
# s2 is the temporary variable
li $s2, 0
# $s3 = Stop = sz-1
addi $s3,$s7,-1 

loop1:
	li $s0, 0
	loop2:
		# LIST[NEXT]
		addi $t3, $s0, 1
		sll $t3, $t3, 2
		la $t0, list
		add $t0, $t0, $t3
		lw $t5, 0($t0)
		
		# LIST[CURR]
		addi $t3, $s0, 0
		sll $t3, $t3, 2
		la $t1, list
		add $t1, $t1, $t3
		lw $t6, 0($t1)
		
		bgt $t6, $t5, swap
		j noswap
		
		swap:
		move $s2, $t6
		move $t6, $t5
		move $t5, $s2
		sw $t6, 0($t1)
		sw $t5, 0($t0)
		
		noswap:	
	addi $s0, $s0, 1
	blt $s0, $s3, loop2
addi $s3, $s3, -1
bgt $s3, $0, loop1

#print the array
exit: 
la $t0,list
#as a counter while printing the list
li $t2,0 

#load current word in $a0 and print the current word
print:
lw $a0,($t0) 
li $v0,1
syscall 

#print space in b/w words
la $a0,space
li $v0,4
syscall 

#point to next word and counter++
addi $t0,$t0,4 
addi $t2,$t2,1
blt $t2,$s7,print 

li $v0,10 #exit MIPS progam
syscall