#!/bin/bash
# print current date and time

# echo "Today's date and time : $(date)"

# now user input and operation 

# read -p "Enter 1st number : " a
# read -p "Enter 2nd number : " b

# echo "Arithmatic operation"
# echo "$a + $b = $(($a + $b))"
# echo "$a - $b = $(($a - $b))"
# echo "$a * $b = $(($a * $b))"
# echo "$a / $b = $(($a / $b))"
# echo "Bitwise operation"
# echo "$a & $b = $(($a & $b))"
# echo "$a | $b = $(($a | $b))"
# echo "$a ^ $b = $(($a ^ $b))"
# echo "$a >> $b = $(($a >> $b))"
# echo "$a << $b = $(($a << $b))"

# decision making statement

# read -p "Enter 1st number : " a
# read -p "Enter 2nd number : " b

# if (( $a > $b  )); then
#  echo "$a > $b"
# elif (( ($a&1) == 0 )); then
#   echo "$a is an even number"
# elif (( ($b&1) == 1 )); then
#   echo "$b is an odd number"
# elif (( $b > $a )); then
#   echo "$a < $b"
# else
#  echo "$a = $b"
# fi

 # Loop 
#  read -p "Enter a number :" num
#  echo "Table of $num is given below"
#  for ((i=1; i<=10; i++))
#   do 
#     echo "$num x $i = $(($num * $i))"
#   done

# function

# sum() {
#     echo "Script name : $0"
#     echo "Total no. of argument : $#"
#     echo "All argument list : $@"
#     echo $(( $1 + $2))
# }
# read -p "Enter x :" x
# read -p "Enter y :" y

# s=$(sum $x $y)
# echo $s

# Array and its operations 

num=(12 13 15 16 35)
Lang=("C-lang" "C++" "C#" "Java" "Go" "Python")
# echo "list of number : ${num[@]}"
# echo "list of computer language : ${Lang[*]}"
# echo "first 3 languages : ${Lang[@]:0:3}"
echo "first 3 languages : ${Lang[@]:3}"
echo "Length of array num : ${#num[@]}"
echo "Length of array Language : ${#Lang[@]}"
echo "Indices of array num : ${!num[@]}"

