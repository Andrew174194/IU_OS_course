#!/bin/bash

file="./ex2.txt"
lock="${file}.lock"

# create result file if it doesn't exist
if [ ! -f $file ]
then
    echo 1 > $file
fi

for i in `seq 1 10`
do

    # this loop prevents race condition
    # repeats until ln is success
    until ln -s $file $lock 2>/dev/null
    do
        sleep 0.5
    done

    # critical region starts
    lnum=`tail -1 $file`
    nnum=`echo "1 + $lnum"|bc`
    echo ${nnum} >> $file
    sleep 0.5       # not necessary
    rm $lock
    # critical region ends

done

# The race condition can happens at any time, not necessary in the first iterations.
# However, usually, it happens almost immidialty after processes start.