#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isJPEG(int buffer[512]);

int main(int argc, char *argv[]) {

    if (argc != 2) {
        return 1;
    }

    FILE *f = fopen(argv[1], "r"); // Open card.raw file

    if (f == NULL) {
        return 2;
    }

    int *buffer = malloc(512);
    while (fread(buffer, sizeof(buffer), 1, f) == 1) {
        isJPEG(buffer);

    }


    free(buffer);
    fclose(f);
    return 0;
}

/*

    1 - Open file
    2 - Iterate through file (512 byte blocks)
    3 - Store this block into a temporary "buffer" array
    4 - Check the first 4 bytes of buffer to determine if JPEG
        a - If not JPEG, continue iteration until JPEG
        b - Once JPEG found, continue
    5 - Create JPEG and write to it
    6 - Continue to add 512 byte blocks to JPEG, checking for isJPEG
    7 - Once new JPEG found, close current file, create new one, and write to it

*/


bool isJPEG(int buffer[512]) {
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) {
        return true;
    }
    return false;
}
