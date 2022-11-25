#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int encodeDecodeCodec1(char * src, char * dst, int len)
{
    for (int i = 0; i < len; i++)
    {   
        if (isalpha(src[i]) && islower(src[i]))
        {
            dst[i] = toupper(src[i]);
        }
        if (isalpha(src[i]) && isupper(src[i]))
        {
            dst[i] = tolower(src[i]);
        }
        else
        {
            dst[i] = src[i];
        }
    }
    return 1;
}