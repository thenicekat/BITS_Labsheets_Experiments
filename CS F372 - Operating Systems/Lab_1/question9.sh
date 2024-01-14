#! /bin/bash

num=0
totalTime=0
until [ $num -gt 100 ]; do
	out=`/usr/bin/time -f "%e" ./fac.out $num`
	totalTime=$((totalTime+out))
	num=$((num+1))
done
echo $totalTime

