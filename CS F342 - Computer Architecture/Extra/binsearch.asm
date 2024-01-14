.data
elems: .word 10 20 30 40 50
nf: .asciiz "Number Not Found in the array"
f: .asciiz "Number Found in the array"
newline: .asciiz "\n"

.text
main:
li $v0, 5
syscall

# t5 stores the number we are searching for
move $t5, $v0 
add $a0, $t5, $0
li $v0, 1
syscall

# Declare a high variable
li $t0, 5

# Declare a low variable
addi $t1, $0, 0

binsearch:
# if($t1-low > $t0-high) printNotFound
bgt $t1, $t0, printNotFound 

# mid = high + low
add $t2, $t1, $t0 

# mid = mid*2 cause address will need to be multiplied by 4 regardless
srl $t2, $t2, 1 
sll $t2, $t2, 2

# load the number into t3
la $t4, elems
add $t4, $t4, $t2
lw $t3, 0($t4) 

# Show the number at current index
add $a0, $t3, $0
li $v0, 1
syscall
la $a0, newline
li $v0, 4
syscall

bgt $t3, $t5, currgreaterthanreqd
blt $t3, $t5, currlessthanreqd
j printFound

currgreaterthanreqd:
addi $t0, $t0, -1
j binsearch

currlessthanreqd:
addi $t1, $t1, 1
j binsearch

printNotFound:
la $a0, nf
li $v0, 4
syscall
j exit

printFound:
la $a0, f
li $v0, 4
syscall
j exit

# exit
exit:
li $v0, 10
syscall