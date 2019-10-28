#include<stdio.h>

int main(){
   int number=0;
   char str;
   printf("Enter number between 0 and 9: ");
   scanf("%d", &number);
   printf("\nYou have entered: %d", number);
   
   printf("\nYour number is: %d\n", number);

   switch(number)
   {
      case 1: {printf("O\n"); break;}
      case 2: {printf("T\n"); break;}
      case 3: {printf("T\n"); break;}
      case 4: {printf("F\n"); break;}
      case 5: {printf("F\n"); break;}
      case 6: {printf("S\n"); break;}
      case 7: {printf("S\n"); break;}
      case 8: {printf("E\n"); break;}
      case 9: {printf("N\n"); break;}
      case 0: {printf("Z\n"); break;}
       default: {printf("Out of range 0..9!"); break;}
    };

}