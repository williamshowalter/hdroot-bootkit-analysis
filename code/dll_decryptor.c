#include "stdio.h"
#include "stdlib.h"

/* 
    arg1: input file
    arg2: output file
    arg3: key
*/

enum ARGS { ARG_SELF, ARG_INPUT, ARG_OUTPUT, ARG_KEY };
const int BUFFER_SIZE = 1024;
unsigned int KEY;

void convert (char * buffer, unsigned long long size) {
    unsigned long long i;
    for (i = 0; i < (size / sizeof(int)); i++) {
        int temp_i = ((int*) buffer)[i] ^ KEY;
        ((int*) buffer)[i] = temp_i;
    }
}

int main (int argc, char * argv[]) {
    char* c_buffer;
    FILE * fd_source, * fd_dest;
    unsigned long long dll_length;
    
    if (argc != 4) {
        printf ("Decryptor Aruments:\n\targ1: intput file\n\targ2: output file\n\targ3: hex key\n");
        return 1;
    }
    
    c_buffer = (char*) malloc(BUFFER_SIZE);

    
    KEY = (unsigned int)strtoul(argv[ARG_KEY], NULL, 16);
    printf ("%#010x\n",KEY);

	fd_source = fopen(argv[ARG_INPUT], "rb");
	fd_dest = fopen(argv[ARG_OUTPUT], "wb");
    
    fseek(fd_source, 0L, SEEK_END);
    dll_length = ftell(fd_source);
    fseek(fd_source, 0L, SEEK_SET);
    
    while (dll_length > BUFFER_SIZE) {
        dll_length -= BUFFER_SIZE;
        fread(c_buffer, 1, BUFFER_SIZE, fd_source);
        convert(c_buffer, BUFFER_SIZE);
        fwrite(c_buffer, 1, BUFFER_SIZE, fd_dest);
    }
    
    fread(c_buffer, 1, dll_length, fd_source);
    convert(c_buffer, dll_length);
    fwrite(c_buffer, 1, dll_length, fd_dest);
    
    fclose(fd_source);
    fclose(fd_dest);
    free (c_buffer);
    c_buffer = 0;
    
    return 0;
}