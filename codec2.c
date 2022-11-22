#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


char * toBinary(char letter)
{
    int decimal = (int) letter;
    //https://indepth.dev/posts/1019/the-simple-math-behind-decimal-binary-conversion-algorithms
    char * binary;
    for (int i = 0; decimal > 0; i++)
    {
        binary[i] = (char)(decimal % 2);
        printf("%c\n", binary[i]);
        decimal = decimal / 2;
    }
    return binary;
}

char * NEG(char letter)
{
    char * binaryNumber = toBinary(letter);
    //NEG calcluation means doing not to the binary number and then addinf 1
    char * NEGnum;
    //not(binaryNum) - turning every 1 to 0 and every 0 to 1
    for (int i = 0; i < strlen(binaryNumber); i++)
    {
        if (binaryNumber[i] == '0')
        {
            NEGnum[i] = 1;
        }
        else
        {
            NEGnum[i] = 0;
        }  
    }
    //adding 1 to the binary number
    int i = strlen(NEGnum) - 1;
    if (NEGnum[i] == '0')
    {
        NEGnum[i] = 1;
    }
    else
    {
        while (NEGnum[i] != '0')
        {
            NEGnum[i] = 0;
            i--;
        }
        NEGnum[i] = 1;
    }
    return NEGnum;
}

int encode(char * src, char * dst, int len)
{
    int k = 0;
    char ch;
    char * negNum;
    for (int i = 0; i < strlen(src); i++)
    {
        ch = src[i];
        negNum = NEG(ch);
        for (int j = 0; j < strlen(negNum); j++)
        {
            dst[k] = negNum[j];
            k++;
        }
    }
    return 1;
}

char * DINEG(char * negNumber)
{
    //this function gets a NEG calcluate and conver it to a regular decimal that is she missing one and then doing not.


}

int NEGtoBinary(char * numToDineg)
{
    char * diNeg = DINEG(numToDineg);
    //i is for the power of th 2 while calcluating the binary number
    //k reprisent our prograss on the binary number diNeg
    //decimal holds the final results of the decimal number
    //dec holds the value of the 1 or 0 each iteration
    int i = strlen(diNeg) - 1, k = 0, decimal = 0, dec;
    while (i >= 0)
    {
        dec = (int)diNeg[k] - 48;
        decimal += (dec * pow(2, i));
        k++;
        i--;
    }
    return decimal;
}

int decode(char * src, char * dst, int len)
{
    char ch;
    for (int i = 0; i < len; i++)
    {
        
    }
    
}

int main(int argc, char const *argv[])
{
    // char ch = 'A';
    // int decimal = toAscii(ch);
    // char * binary;
    // for (int i = 0; decimal > 0; i++)
    // {
    //     binary[i] = (char)(decimal % 2);
    //     printf("%c\n", binary[i]);
    //     decimal = decimal / 2;
    // }
    // printf("%s\n", binary);
    return 0;
}