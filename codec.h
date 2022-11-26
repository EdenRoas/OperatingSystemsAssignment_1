#include "codec2.c"
#include "codec1.c"

//this lines from the link: https://www.quora.com/How-do-you-fix-a-redefinition-error-in-C-programming
#ifndef _OS_CODEC_H
#define _OS_CODEC_H_

int codec1_encode(char * src, char * dst, int len)
{
    return encodeDecode1(src, dst, len);
};

int codec1_decode(char * src, char * dst, int len)
{
    return encodeDecode1(src, dst, len);
};

int codec2_encode(char * src, char * dst, int len)
{
    return encode(src, dst, len);
};

int codec2_decode(char * src, char * dst, int len)
{
    return decode(src, dst, len);
};

#endif /* _OS_CODEC_H_ */