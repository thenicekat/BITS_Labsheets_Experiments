.data
myMsg: .asciiz "Hello, Enter a number: "

.text
main:
la $a0, myMsg
li $v0, 4
syscall

li $v0, 5
syscall

add $a0, $0, $v0
li $v0, 1
syscall

li $v0, 10
syscall