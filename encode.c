#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "codec.h"

int main(int argc, char *argv[])
{
    //using those links: https://man7.org/linux/man-pages/man3/dlsym.3.html
    //https://man7.org/linux/man-pages/man3/dlopen.3.html
    char libCodec[12];
    if(strcmp(argv[1], "codec1") == 0)
    {
        strcpy(libCodec,"./codec1.so");
    }
    if(strcmp(argv[1], "codec2") == 0)
    {
       strcpy(libCodec,"./codec2.so");
    }
    void * handle = dlopen(libCodec, RTLD_NOW | RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }
    //getting the address where function is loaded into memory
    int (*functionPointer)(char * src, char * dst, int len);
         
    //prepering a place to insert the output of the function
    char * dst = malloc(strlen(argv[2]) * sizeof(char));

    //checking which function we need to operate
    if(strcmp(argv[1], "codec1") == 0)
    {
        functionPointer = dlsym(handle, "encodeDecode1");
        functionPointer(argv[2], dst, strlen(argv[2]));
    }

    if(strcmp(argv[1], "codec2") == 0)
    {
        functionPointer = dlsym(handle, "encode");
        functionPointer(argv[2], dst, strlen(argv[2]));
    }

    printf("%s\n", dst);

    free(dst);
    if (dlclose(handle)!=0) //returns 0 on success
    {
        printf("error\n");
    }
    return 0;

}
