#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
void create_database(char* dirname )
{ 
    int check; 
    
  
    check = mkdir(dirname); 
  
    // check if directory is created or not 
    if (!check) 
        printf("Database created\n"); 
    else { 
        printf("Unable to create Database \n"); 
        exit(1); 
    } 
  
    getch(); 
  
    system("dir/p"); 
    getch(); 
} 