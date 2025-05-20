#include<stdio.h>

void toh(int n,char a,char c,char b){// source to destination using helper
    // base case 
    if(n == 0){
        return;
    }
   toh(n-1,a,b,c);
   printf("move %dth from %c to %c\n",n,a,c);
   toh(n-1,b,c,a);
}

void main(){
    printf("The combination of tower of hanoai are :-\n");
    toh(3,'A','C','B');
}