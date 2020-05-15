#!/bin/bash
# Justin Ngo
# jmn4fms
# 3/3/20
# averagetime.sh

echo "enter the exponent for counter.cpp:"
read input
quit="quit"
if [ $quit == $input ]
    then
    exit
fi
#Compile
clang++ counter.cpp
loop=1
sum=0
count=5

#run program 5 times
while [ $loop -lt 6 ]
do
run_time=`./a.out $input | tail -1`
#run time printed
echo "Running iteration" $loop"..."
echo "time taken:" $run_time "ms"
total=$((total+run_time))
loop=$[$loop+1]
done
#prints sum
echo "5 iterations took" $total "ms"
#print average time
echo "Average time was" $((total/count)) "ms"
