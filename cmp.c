#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void main(int argc, char * argv[])
{
    if(argc != 3)
    {
        printf("Usage : cmp <file1><file2>\n");
        exit(0);
    }
    
    //gettin full path of 2 files
    char * pathFile1 = realpath(argv[1], NULL); 
    char * pathFile2 = realpath(argv[2], NULL); 

    // Find files size in bytes
    struct stat sizeFile1;  
    stat(pathFile1, &sizeFile1);
    struct stat sizeFile2;  
    stat(pathFile2, &sizeFile2);
    int size1 = sizeFile1.st_size;
    int size2 = sizeFile2.st_size;

    //creating a string to put the content of the files
    char * file1 = malloc(size1);
    char * file2 = malloc(size2);
    
    //open the files
    int f1 = open(pathFile1, O_RDONLY);
    int f2 = open(pathFile2, O_RDONLY);

    //checking if the files got opend
    if(f1 == -1 || f2 == -1)
    {
        printf("couldn't open one of the files\n");
        exit(1);
    }

    read(f1, file1, size1);//read from the file and putting what we read to the string file1
    read(f2, file2, size2);//read from the file and putting what we read to the string file2

    int index = 0;
    int c1 = 0;
    int c2 = 1;    

    int flag = 1;
    while (1)
    {
        c1 = file1[index];//gets a char from file 1
        c2 = file2[index];//gets a char from file 2
        //check if the two chars from both files are not the same then change the flag to false and exit the loop
        if(c1 != c2)
        {
            flag = 0;
            break;
        }
        if (index == strlen(file1) && index==strlen(file2)){
            break;
        }
        //if one of the files ended and the second one didn't turn the flag to false and exitthe loop
        if(index == strlen(file1) || index == strlen(file2))
        {
            flag = 0;
            break;
        }
        index++;
    }
    if(flag)
    {
        printf("identical\n");
    }
    else
    {
        printf("not identical\n");
    }

    close(f1);
    close(f2);
}