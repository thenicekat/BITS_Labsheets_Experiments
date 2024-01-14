#! /bin/bash 

num=1
while [ $num -le 100 ]; do
    if [ $((num % 2)) == 0 ]; then
	   echo $num
    fi
	let num=num+1
done