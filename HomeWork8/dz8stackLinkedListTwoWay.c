#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

typedef struct sStack
{
    int iData;
    struct sStack *next;
    struct sStack *prev;
} tsStack;

void pushStack(tsStack **head, const int iValue)
{
    tsStack *tmp=(tsStack*)malloc(sizeof(tsStack));
    if(tmp==NULL)
    {
        printf("Stack overflow!");
    }
    else
    {
        tmp->iData=iValue;
        tmp->prev=(*head);
        tmp->next=NULL;
        (*head)->next=tmp;
        (*head)=tmp;
    }
}

void printStack(tsStack *tail)
{
    printf("Stack > ");
    do
    {
        if( (tail->iData)!= 0) printf(" %d |",tail->iData);
        tail = tail->next;
    }while(tail);
    printf("\n");
}

int popStack(tsStack **head)
{
    if( (*head)->prev )
    {
        int iValue;
        tsStack *out=*head;
        *head=(*head)->prev;
        (*head)->next=NULL;
        iValue=out->iData;
        free(out);
        return iValue;
    }
    else
    {
        printf("\npopStack(): Stack is empty!");
        return 0;
    }


}
int shiftStack(tsStack **tail)
{
    if ((*tail)->next && ((*tail)->iData)==0 )
    {//delete first 0-node!
        tsStack *out=*tail;
        (*tail)=(*tail)->next;
        (*tail)->prev=NULL;
        free(out);
    }

    if((*tail)->next)
    {// operate intermediate nodes
        int iValue;
        tsStack *out=*tail;
        *tail=(*tail)->next;
        (*tail)->prev=NULL;
        iValue=out->iData;
        free(out);
        return iValue;
    }

    if ( !((*tail)->next) && ((*tail)->iData)!=0)
    {//operate last node
        int iValue=(*tail)->iData;
        (*tail)->iData=0;
        (*tail)->prev=NULL;
        free(*tail);
        return iValue;
    }

    else
    {
        printf("\nshiftStack(): Queue is empty!");
        return 0;
    }

}
int peekStack(tsStack *head)
{
    if(head || (head->iData)!=0 )
        return head->iData;
    else printf("peekStack(): Stack is empty!");
}

int main()
{
    bool bMainLoopContinue=true;
    int iValue;
    int iAction;
    tsStack *head=(tsStack*)malloc(sizeof(struct sStack));
    tsStack *tail=head;

    head->iData=0;
    head->next=NULL;
    head->prev=NULL;

    printf("Welcome to Simple Task Manager!\n");

    while(bMainLoopContinue)
    {
        printf("\nPress 1 to PUSH SET of tasks into Task-List automatically.\n");
        printf("Press 2 to PUSH one task into Task-List manually.\n");
        printf("Press 3 to POP one task from Task-List.\n");
        printf("Press 4 to PEEK task from Task-List.\n");
        printf("Press 5 to SHIFT one task from Task-List.\n");
        printf("Press 6 to PRINT Task-List.\n");
        printf("Press 7 to select STACK-order execution of Task-List.\n");
        printf("Press 8 to select QUEUE-order execution of Task-List.\n");
        printf("Press 0 to EXIT game (default).\n");
        printf("Action is: ");
        int res;
        do
        {
            fflush(stdin);
            res=scanf("%d", &iAction);
            if(!res) printf("Invalid input! Try again.\nAction is: ");
        }while(!res);
        switch(iAction)
        {
            case 0: //EXIT
            {
                printf("\nAction 0 selected.\nBey!");
                bMainLoopContinue=false;
                break;
            }
            case 1:
            {
                printf("\nAction 1 selected.\nEnter integer number of tasks: ");
                int res;
                int iValue;
                do{
                    fflush(stdin);
                    res=scanf("%d",&iValue);
                    if(!res) printf("Invalid input! Try again: ");
                }while(!res);
                srand(time(NULL));
                int i;
                for(i=0;i<iValue;i++)
                {
                    pushStack(&head, rand()%100 );
                }
                printf("\nList of %d tasks if formed.\n",iValue);
                break;
            }
            case 2: //PUSH
            {
                int iValue;
                printf("\nAction 2 selected.\nEnter digital data: ");
                int res;
                do
                {
                    fflush(stdin);
                    res=scanf("%d",&iValue);
                    if(!res) printf("\nInvalid input! Try again: ");
                }while(!res);
                pushStack(&head, iValue);

                break;
            }
            case 3: //POP
            {
                int iValue;
                printf("\nAction 3 selected.");
                iValue=popStack(&head);
                if (iValue!=0) printf("\nPopped task is %d\n", iValue);
                else printf("\ncase 3: Stack is empty!\n");
                printStack(tail);
                break;
            }
            case 4: //PEEK
            {
                int iValue;
                printf("\nAction 4 selected.");
                iValue=peekStack(head);
                if(iValue==0) printf("\ncase 4: Stack is empty!\n");
                else printf("\nPeeked task is %d\n", iValue);
                break;
            }
            case 5: //SHIFT
            {
                int iValue;
                printf("\nAction 5 selected.");
                iValue=shiftStack(&tail);
                if (iValue!=0) printf("\nShifted task is %d\n", iValue);
                else printf("\ncase 5: Queue is empty!\n");
                printStack(tail);
                break;
            }
            case 6: //PRINT
            {
                printf("\nAction 6 selected.\n");
                printStack(tail);
                break;
            }
            case 7: //STACK-order
            {
                printf("\nAction 7 selected.\n");
                if ( !(head->prev) ) printf("case 7: Task-List is empty!\n");
                while( (head->prev)  )
                {
                    printf("Popped task is %d\n", popStack(&head));
                    printStack(tail);
                }
                break;
            }
            case 8: //QUEUE-order
            {
                printf("\nAction 8 selected.\n");
                while( (tail->next)  )
                {
                    printf("Shifted task is %d\n", shiftStack(&tail));
                    printStack(tail);
                }
                if(!(tail->next) && (tail->iData)!=0 )
                {
                    printf("Shifted task is %d\n", shiftStack(&tail));
                }
                if(!(tail->next)) printf("case 8: Task-List is empty!\n");
                break;
            }


        }
    }
    return 0;
}
