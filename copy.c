#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void regularCopy(char * src, char * dst)
{
    char * pathSrcFile = realpath(src, NULL); //gettin full path of the file we want to copy
    //gettint the byte size of the file we want to copy
    struct stat sizeFile1;  
    stat(pathSrcFile, &sizeFile1);
    int size1 = sizeFile1.st_size;
    char * file1 = malloc(size1); //creating a string to put the content of the file when we read it
    int f1 = open(pathSrcFile, O_RDONLY); //open the file we want to copy just for read using his full path
    //checking if the file got opend
    if(f1 == -1)
    {
        printf("couldn't open source file\n");
        exit(1);
    }
    read(f1, file1, size1); //read from the file and putting what we read to the string file1
    //open the destination file and write to it
    int f2 = open (dst, O_RDWR | O_CREAT | O_TRUNC, S_IRWXU); //open the file to where we want to copy for writing and if it dose not exist create it
    //checking if the file got opend
    if(f2 == -1)
    {
        printf("couldn't open destination file\n");
        exit(1);
    }
    //writing to the file the content of the file we wanted to copy
    if(write(f2, file1, size1) == size1)
    {
        printf("file is copied.\n");
    }
    close(f1);
    close(f2);
}

int isLink(char * file)
{
    //the idea for the code is from the site: https://stackoverflow.com/questions/3984948/how-to-figure-out-if-a-file-is-a-link
    //and the site: http://codewiki.wikidot.com/c:system-calls:lstat
    struct stat buf;
    int x;
    //checks if the file is link or not 1 says is link 0 says not link
    x = lstat (file, &buf);
    if (S_ISLNK(buf.st_mode)) return 1;
    else return 0;
}

int isContainL(int argc, char *argv[])
{
    //this function checks if the link contain -l
    //using this sites:
    //https://www.gnu.org/software/libc/manual/html_node/Example-of-Getopt.html
    //https://pubs.opengroup.org/onlinepubs/009696799/functions/getopt.html
    //https://www.geeksforgeeks.org/getopt-function-in-c-to-parse-command-line-arguments/
   int c = getopt(argc, argv, "l:");
   if(c == 'l') return 1;
   else return 0;
}

void copyLink(char * src, char * dst)
{
    //for this function we used this site: https://pubs.opengroup.org/onlinepubs/009696699/functions/symlink.html
    //and this site: https://www.ibm.com/docs/en/zos/2.4.0?topic=functions-symlink-create-symbolic-link-path-name#rtsym
   
    if (symlink(src, dst) != 0)
    {
        perror("symlink() error");
        unlink(src);
    }
    else
    {
        printf("link is copied.\n");
        unlink(dst);
    }
}

void copyConten(char * src, char * dst)
{
    //in this function we used this sites: https://www.informit.com/articles/article.aspx?p=23618&seqNum=12
    //https://pubs.opengroup.org/onlinepubs/009696699/functions/readlink.html
    int f2 = open (dst, O_RDWR | O_CREAT | O_TRUNC, S_IRWXU); //open the file to where we want to copy for writing and if it dose not exist create it
    //checking if the file got opend
    if(f2 == -1)
    {
        printf("couldn't open destination file\n");
        exit(1);
    }
    // int sizeBuf = 1024;
    int len;
    int sizeFile = 256;
    char * dstFile = malloc(sizeFile); //creating a string to put the content of the file when we read it
    if ((len = readlink(src, dstFile, sizeFile)) != -1)
        dstFile[len] = '\0';
}

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Usage : copy <file1><file2>\n");
        exit(0);
    }

    int isFileLink = isLink(argv[1]);
    if(isFileLink == 1)
    {
        int isLFile = isContainL(argc, argv);
        printf("%s, %s \n", argv[1], argv[2]);
        if(isLFile == 1) copyLink(argv[1], argv[2]); //if the link contain -l then we copy the content of the link
        //else regularCopy(argv[1], argv[2]); //if the link does not contain -l then we copy the file linked by the symbolic link
        else copyConten(argv[1], argv[2]); //if the link does not contain -l then we copy the file linked by the symbolic link
    }
    else
    {
        regularCopy(argv[1], argv[2]);
    }
    return 0;
}