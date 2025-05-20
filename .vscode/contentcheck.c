#include<stdio.h>
#include<string.h>
#include<stdbool.h>

 void main(){
    bool flag = false;
   char content_1[20],content_2[20];
    printf("Enter your 1st content : ");
    scanf("%s",content_1);
    printf("Enter your 2nd content : ");
    scanf("%s",content_2);
   printf("content-1 is %s &\n",content_1);
   printf("The length of content_1 = %d\n",strlen(content_1));
   printf("content-2 is %s &\n",content_2);
   printf("The length of content_2 = %d\n",strlen(content_2));

   if(strlen(content_1) == strlen(content_2) ){
    printf("Since the size of both contents are same.Now it is going to check each character  \nWait for while!\n");
     for(int i = 0; i<strlen(content_1); i++){
         if(content_1[i] == content_2[i]){
            flag = true;
         }
         else if(content_1[i] != content_2[i]) {
            printf("No,both the content are different\n");
            break;
         }
     }
     if(flag == true) printf("Yes,both the contents are same\n");
   }
   else{
      printf("Both the contents are different b/c of the size are different\n");
   }
 }