#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char query[100];

void checkSyntax()
{
    char delim[] = " ";
    char *p = strtok(query,delim);
    switch(p[0])
    {
        case 'c':
        {
            p = strtok(NULL,delim);
            switch(p[0])
            {
                case 'd':
                {
                    p = strtok(NULL,delim);
                    printf("%s created\n",p);
                    break;
                }
                default:
                {
                    printf("Syntax error\n");
                }
            }
            break;
        }
        default:
        {
            printf("Syntax error\n");
        }
    }
}

void findKeywords()
{

}

void storeKeywords()
{

}

void processQuery()
{

}

void run()
{
    // Step 2
    checkSyntax();
    findKeywords();

    // Step 3
    storeKeywords();

    // Step 4
    processQuery();
}

void cli()
{
    int loop = 1;
    while (loop)
    {
        printf("minor> ");
        // step 1
        gets(query);
        if(strcmp(query,"exit") == 0)
            loop=0;
        else if(strcmp(query,"clear") == 0)
            system("cls");
        /*else if(strcmp(query,"help") == 0)
            help();*/
        else
            run();
    }
}

int main()
{
    system("clear");
    cli();
}
