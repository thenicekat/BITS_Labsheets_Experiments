.data
input: .space 20
removed: .asciiz "Letters Removed: "
size: .word 24
vowels: .asciiz "aeiou"
endline: .asciiz "\n"

.text
main:
# TAKE INPUT FROM USER
la $a0, input
li $v0, 8
li $a1, 20
syscall

# TAKE INPUT AND CALL THE FUNCTION
la $a0, input
jal count_number_of_vowels

# PRINT THE STRING WHICH SAYS REMOVED
move $a1, $v0
li $v0, 4
la $a0, removed
syscall

# PRINT THE COUNT
move $a0, $a1
li $v0, 1
syscall

# PRINT MODIFIED STRING
li $v0, 4
la $a0, endline
syscall
la $a0, input
syscall

# EXIT
li $v0, 10
syscall
# ===============================================================================================
# PROCEDURE TO COUNT THE VOWELS
count_number_of_vowels:
	li $v0, 0
	la $a0, input
	
	check_letter:
		# WE LOAD THE CURRENT LETTER
		lb $a1, ($a0) 
		# IF IT'S 0 WE GO TO EXIT
		beq $a1, $zero, exit
        
		# WE LOAD $T1 WITH VOWELS
		la $t1, vowels
		check_vowel:
			# ITERATE THROUGH ALL THE VOWELS
			lb $t2, ($t1)
			# IF THE VOWELS STRING IS OVER END THE VOWEL LOOP
			beq $t2, $0, end_vowel_loop
			# IF IT'S A VOWEL REMOVE THAT LETTER
			beq $t2, $a1, remove_letter
			# CHECK NEXT VOWEL
			addi $t1, $t1, 1		
		j check_vowel
		
		# V0 KEEPS TRACK OF HOW MANY WE REMOVE
		remove_letter:
			addi $v0, $v0, 1
			move $t3, $a0
			move $t4, $a0
			addi $t4, $t4, 1
			
			# WE SHIFT ALL THE CHARACTERS ONE BACKSIDE
			remove_loop:
				lb $t5, ($t4)
				lb $t6, ($t3)
				beq $t6, $0, end_remove_loop
				sb $t5, ($t3)
				addi $t4, $t4, 1
				addi $t3, $t3, 1
			j remove_loop
			
			# THIS END REMOVE LOOP IS USED TO DECREMENT CHARACTER SO THAT WE DON"T REPEAT
			end_remove_loop: addi $a0, $a0, -1
			
		end_vowel_loop: addi $a0, $a0, 1
	j check_letter
	
	exit:
		jr $ra