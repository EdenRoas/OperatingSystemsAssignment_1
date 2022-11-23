#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int encode(char * src, char *dst, int len)
{
    char str[5];
    int ascival;
    for (int i = 0; i < len; i++)
    {
        ascival = (int)src[i];
        ascival = (((-1)*ascival) + 1);
        sprintf(str, "%d", ascival); //https://stackoverflow.com/questions/8257714/how-to-convert-an-int-to-string-in-c
        strcat(dst, str);//https://www.educative.io/blog/concatenate-string-c
    }
    return 1;
}

int decode(char * src, char * dst, int len)
{   
    char * str = malloc(sizeof(char) * 5);
    str[0] = '-';
    int j = 1, conv, i = 1, indexd = 0;
    while(i < len)
    {   
        
        if(src[i] == '-' )
        {
            j=1;
            conv = atoi(str); //https://www.educative.io/answers/how-to-convert-a-string-to-an-integer-in-c
            conv = (((-1) * conv) + 1);
            dst[indexd] = (char)conv;
            indexd++;
            str[3] = '\0';
            
        }
        else
        {
            str[j] = src[i];
            j++;
        }
        i++;
        if (i == len){
            conv = atoi(str); //https://www.educative.io/answers/how-to-convert-a-string-to-an-integer-in-c
            conv = (((-1) * conv) + 1);
            dst[indexd] = (char)conv;
            indexd++;
        }
         
    }
   
    dst[indexd] = '\0';
    return 1;
}

int main(int argc, char *argv[])
{
    int len = strlen(argv[1]);
    char * msgToEncode = malloc(len * 5);
    char msgToDecode[len];
    encode(argv[1], msgToEncode, len);
    for (int i = 0; i < strlen(msgToEncode); i++)
    {
        printf("%c", msgToEncode[i]);
    }
    //printf("%d\n" , str);
    printf("\n");
    decode(msgToEncode,msgToDecode,strlen(msgToEncode));
    for (int i = 0; i < strlen(msgToDecode); i++)
    {
        printf("%c", msgToDecode[i]);
    }
    printf("\n");
    return 0;
}