#include<stdio.h>
#include<stdbool.h>

struct stEntry
{
    char pcName[20];    // ! *  при использовании ссылочных типов вывод данных захватывает другое поля структуры
    char pcPhoneNumber[10];
};

int main()
{
    bool bSelectActionLoopContinue=true;
    int iSelectedAction;
    FILE *pFile;
    char ch;

    ///////////////////


    //////////////


    printf("PHONEBOOK\n");
    while(bSelectActionLoopContinue==true)
    {
        printf("\nMAIN MENU. Action: \'1\' - Load all entries; \'2\' - Insert new entry; \'3\' - Find entry; \'4\' - Exit.\n");
        scanf("%d", &iSelectedAction);

        switch(iSelectedAction)
        {
            case 1:
                {
                    printf("Action 1 selected. Load process started...\n");
                    pFile=fopen("phonebook.txt","rt");
                    if (pFile==NULL)
                    {
                        fclose(pFile);
                        printf("Error opening Phonebook!\n...End of Load process\n");
                    }
                    else
                    {
                        while(!feof(pFile))
                        {
                            ch=fgetc(pFile);
                            printf("%c",ch);
                        }
                        fclose(pFile);
                    }

                    printf("Loading succeeded! ...End of Load process\n");
                    break;
                };
            case 2:
                {
                    printf("Action 2 selected. Insertion process started...\n");
                    struct stEntry newEntry;
                    printf("Enter new Name: ");
                    scanf("%s", &newEntry.pcName);
                    printf("Enter new Number: ");
                    scanf("%s", &newEntry.pcPhoneNumber);
                    printf("New Entry: %s, %s\n", &newEntry.pcName, &newEntry.pcPhoneNumber );

                    pFile=fopen("phonebook.txt","a");
                    if (pFile==NULL)
                    {
                        printf("Error opening Phonebook! ...End of Insertion process\n");
                        fclose(pFile);
                    }
                    else
                    {
                        fprintf(pFile, "%s %s\n",&newEntry.pcName, &newEntry.pcPhoneNumber );
                        fclose(pFile);
                        printf("Insertion succeeded!\n...End of Insertion process\n");
                    }

                    break;
                };
            case 3:
                {
                    struct stEntry Entry;
                    char pcNameToFind[20];
                    char pcNumberToFind[10];

                    printf("Action 3 selected. Finding process started...\n");
                    printf("Enter Name to find Telephone Number: ");
                    scanf("%s",pcNameToFind);
                    pFile=fopen("phonebook.txt","rt");
                    if(pFile==NULL)
                    {
                        printf("Error opening Phonebook! ...End of Finding process\n");
                        fclose(pFile);
                    }
                    else
                    {
                        //int i=0;
                        while(feof(pFile))
                        {
                            //i++;
                            fscanf(pFile, "%s %s", Entry.pcName, Entry.pcPhoneNumber);
                            //printf("%d %s %s\n", i, Entry.pcName, Entry.pcPhoneNumber);

                            if( !strcmp(Entry.pcName, pcNameToFind))
                            {
                                printf("%s %s\n", Entry.pcName, Entry.pcPhoneNumber);
                            }
                        }
                        printf("Finding succeeded! ...End of Finding process\n");
                        fclose(pFile);
                        break;
                    }
                }

            case 4:
                {
                    printf("You selected Exit action.\n");
                    bSelectActionLoopContinue=false;
                    break;
                };
            default:
                {
                    printf("Select action again!\n");
                    break;
                };
        };//switch


        //bSelectActionLoopContinue=false;


    }; // End of while(bMainLoopFlag==true)
    printf("Bey!");
    getchar();


    return 0;
}
