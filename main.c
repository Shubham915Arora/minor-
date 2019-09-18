#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include<create.h>
#include<regex.h>
char query[100];
const char *s1="create table [a-zA-Z][a-zA-Z0-9_]+?(([a-zA-Z][a-zA-Z0-9_]+(int|string|double),??)+);$";
const char *s2="insert into [a-zA-Z][a-zA-Z0-9_]+values?(([a-zA-Z][a-zA-Z0-9.]+?,??)+);$";
const char *s3="create database [a-zA-Z][a-zA-Z0-9_]+;$";
const char *s4="select from [a-zA-Z][a-zA-Z0-9_]+;$ ";
const char *s5="drop table [a-zA-Z][a-zA-Z0-9_]+;$";
const char *s6="drop [a-zA-Z][a-zA-Z0-9_]+;$";
const char *s7 ="use [a-zA-Z][a-zA-Z0-9_]+;$";
const char *s8="show databases;$";
const char *s9="show tables;$";
const char *s10="select ([a-zA-Z][a-zA-Z0-9_]+?,??)+from[a-zA-Z][a-zA-Z0-9_]+;$ ";

int match(const char *string , const char *pattern )
{
    regex_t re ;
    if (regcomp(&re, pattern, REG_EXTENDED|REG_NOSUB)!=0)return 0;
    int status =regexec(&re,string ,0 ,NULL,0);
    regfree(&re);
    if(status!=0)return 0;
    return 1;

}


int checkSyntax()
{
    if(match(&query[0],s1)==1){
         
         return 1;
    }
    else if(match(&query[0],s2)==1)
        return 1;
    else if(match(&query[0],s3)==1){
        printf("\n Pattern match ");
        return 1;
    }
    else if(match(&query[0],s4)==1)
        return 1;
    else if(match(&query[0],s5)==1)
        return 1;
    else if(match(&query[0],s6)==1)
        return 1;
    else if(match(&query[0],s7)==1)
        return 1;
    else if(match(&query[0],s8)==1)
        return 1;
    else if(match(&query[0],s9)==1)
        return 1;
    else if(match(&query[0],s10)==1)
        return 1;
    else 
      { printf("Syntax Error");
       return 0;}
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
    if(checkSyntax()==1){
    findKeywords();

    // Step 3
    storeKeywords();

    // Step 4
    processQuery();}
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
            system("clear");
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
