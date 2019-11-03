#include<stdio.h>
#define MAX_SIZE 1000
int main(){
    char caArray[MAX_SIZE];
    char ch;
    int i=0;
    while(i<MAX_SIZE)
    {
        ch=rand()%127;
        if (isalnum(ch))
        {
            switch(ch)
            {    
                 case '0':
                 case '1':
                 case '2':
                 case '3':
                 case '4':
                 case '5':
                 case '6':
                 case '7':
                 case '8':
                 case '9': {continue;}
                 default :
                 {
                       caArray[i]=ch;
                       printf("%c", ch);
                       i++;
                       break;
                 }
            }

        }   

    }

    return 0;
}
