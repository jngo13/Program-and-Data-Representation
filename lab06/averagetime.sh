#!/bin/bash
# Justin Ngo
# jmn4fms
# 3/3/20
# averagetime.sh

echo "Name of dictionary file: "
read dictionary
echo "Name of grid file: "
read grid

#run the program and calculate time, only keep the last line, and save that output to a variable.
time1=`./a.out $dictionary $grid | tail -1`
time2=`./a.out $dictionary $grid | tail -1`
time3=`./a.out $dictionary $grid | tail -1`
time4=`./a.out $dictionary $grid | tail -1`
time5=`./a.out $dictionary $grid | tail -1`

echo $time1
echo $time2
echo $time3
echo $time4
echo $time5

echo ""

total=$time1
total=$((total+$time2))
total=$((total+$time3))
total=$((total+$time4))
total=$((total+$time5))

count=5

echo "Average time (milliseconds): "
echo $((total/count))
