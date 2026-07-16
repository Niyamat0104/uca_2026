#!/bin/bash

echo  "Task1"

awk -F',' '{print $1,$2}' employees.txt
echo

echo "Task2"

awk -F',' '$2=="Engineering" {print}' employees.txt
echo

echo "Task3"
awk -F',' '{printf "%s gross pay : $%d\n", $1,$3*$4}' employees.txt
echo

echo "Task4"
awk -F',' '{printf "%d (%d fields): %s\n",NR,NF,$0}' employees.txt
echo

echo "FinalTask"
awk -F',' '
BEGIN {
   total = 0 
}
$2 == "Engineering"{
   total += $3* $4
}
END {
   printf "Total ENgineering Payrool : $%d\n",total
}' employees.txt
