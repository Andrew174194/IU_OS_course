#!/bin/bash 
printf 'This string was before ex2.c program\n\n'  > ex2.txt
cat /proc/cpuinfo | ./ex2 -a ex2.txt