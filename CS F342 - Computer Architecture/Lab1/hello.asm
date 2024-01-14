.data
myMsg: .asciiz "Hello, Enter a number: "

.text
main:
li $a0, 10
li $v0, 1 # code 1 corresponds to print int
syscall

li $v0, 10 # code 10 corresponds to exit
syscall 