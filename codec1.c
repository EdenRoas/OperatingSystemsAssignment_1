#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int encode(char * src, char * dst, int len)
{
    for (int i = 0; i < len; i++)
    {   
        if (isalpha(src[i]) && islower(src[i]))
        {
        dst[i] = toupper(src[i]);
        }
        if (isalpha(src[i]) && isupper(src[i])){
        dst[i] = tolower(src[i]);
        }
    }
    return 1;
}

int decode(char * src, char * dst, int len)
{
    
    return encode(src, dst, len);
}

int main(int argc, char *argv[])
{
    int len = strlen(argv[1]);
    char msgToEncode[len];
    char msgToDecode[len];
    encode(argv[1], msgToEncode, len);
    for (size_t i = 0; i < len; i++)
    {
        printf("%c", msgToEncode[i]);
    }
    printf("\n");
    decode(msgToEncode, msgToDecode, len);
    for (size_t i = 0; i < len; i++)
    {
        printf("%c", msgToDecode[i]);
    }
    printf("\n");
    return 0;
}