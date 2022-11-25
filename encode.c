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
    printf("%s\n", libCodec);
    void * handle = dlopen(libCodec, RTLD_NOW);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }
    
    //getting the address where function is loaded into memory
    void (*functionPointer)(char * src, char * dst, int len);
    
    //prepering a place to insert the output of the function
    char * dst;

    //checking which function we need to operate
    if(strcmp(argv[1], "codec1") == 0)
    {
        dst = malloc(strlen(argv[2]) * sizeof(char));
        functionPointer = dlsym(handle, "codec1_encode");
        functionPointer(argv[2], dst, strlen(argv[2]));
    }

    if(strcmp(argv[1], "codec2") == 0)
    {
        dst = malloc(strlen(argv[2]) * sizeof(char) * 5);
        functionPointer = dlsym(handle, "codec2_encode");
        functionPointer(argv[2], dst, strlen(argv[2]));
    }

    dlclose(handle);

    return 0;

}
