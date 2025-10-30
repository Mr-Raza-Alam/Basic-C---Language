#!/bin/bash

#fibonacci series

# T1=0
# T2=1

# read -p "Enter no. of fibonacci series required : " n
# echo -n "$T1 $T2 "
# for((i=3; i<=$n; i++))
#  do
#    Tnext=$((T1+T2))
#    echo -n "$Tnext "
#    T1=$T2
#    T2=$Tnext
# done

# find greatest element in an array

# num=(5 6 12 15 35 56 2 29)

# max=-1
# for n in "${num[@]}"
#  do
#    if [ $n -ge $max ]; then
#     max=$n
#    fi
#  done

#  echo "Greatest element of array num [ ${num[@]} ] = $max"

 # unique element if frequency of array's element is even

#  declare -A freq # associative array for frequency count
#  num=(4 4 2 2 1 5 2 3 4 2 5 4 1 5 6 5 3)

#  uni=0
#  for n in "${num[@]}"
#   do
#     # uni=$((uni^n))
#     ((freq[$n]++))
  # done
# echo "Unique element in the array num [ ${num[@]} ] = $uni"
# echo "Frequency of each element of array num [ ${num[@]} ] is "

# for key in "${!freq[@]}"
#  do 
#   echo "$key appears ${freq[$key]} times"
#  done

# factorial unsing function

# fact() {
#   n=1
#   for((i=$1; i>0; i--))
#    do
#      n=$(($n*$i))
#    done
#    echo $n
# }

# read -p "Enter a number : " x

# echo "$x! = $(fact $x)"


# sort the given array 

# arr=(4 2 13 6 15 7 2 9)
# echo "Before sorting the array arr = [ ${arr[*]} ]"
# n="${#arr[@]}"

# for((i=0; i<$n-1; i++))
#  do
#     for((j=$i+1; j<$n; j++))
#      do
#        if (( arr[$i]>arr[$j] )); then
#           tmp=${arr[$i]}
#           arr[$i]=${arr[$j]}
#           arr[$j]=$tmp
#         fi
#       done
#   done
# echo "After sorting the array arr = [ ${arr[@]} ]"

# reverse and pallindrome

# read -p "Enter a number : " n

# h=$n
# rev=0

# while (( h>0 ))
#  do
#   rev=$(($rev * 10+$h % 10))
#   h=$((h/10))
#  done
# echo "Given number : $n and its reverse number = $rev"

# if (($n == $rev)); then
#  echo "$n is a Pallindrome number"
# else
#  echo "$n is not a Pallindrome number"
# fi
 

 # leap year on hold

read -p "Enter a year : " yr

if (( ($yr % 400 == 0) || ($yr%4 == 0) && ($yr%100 != 0)  )); then 
  echo "$yr is a leap year"
  else
   echo "$yr is a normal year"
fi

#prime number
# read -p "Enter a num : " num 

# isPrime() {
#     local n=$1
#     if (( n <= 1 )); then
#         echo 0
#         return
#     fi
#     if (( n == 2 )); then
#         echo 1
#         return
#     fi
#    for((i=3; $i*$i<=n; i++))
#     do
#       if (( n % i ==0 )); then
#         echo 0
#         return      
#       fi
#      done 
#      echo 1
# }

# if (( $(isPrime $num) == 1)); then
#   echo "$num is a Prime number"
# else
#   echo "$num is a Composite number"
# fi
 


