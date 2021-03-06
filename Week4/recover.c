#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef uint8_t BYTE;

bool isJPEG(BYTE *buffer);
FILE* createNewFile(int fileCount);

int main(int argc, char *argv[]) {

    if (argc != 2) {
        return 1;
    }

    FILE *f = fopen(argv[1], "r"); // Open card.raw file

    if (f == NULL) {
        return 2;
    }

    BYTE *buffer = malloc(512);
    FILE *img = NULL;
    int fileCount = 0;
    bool firstFileFound = false;

    while (fread(buffer, sizeof(buffer), 1, f) == 1) {
        if (firstFileFound) {
            if (isJPEG(buffer)) {
                fclose(img);
                fileCount++;
                img = createNewFile(fileCount);
            }
            fwrite(buffer, sizeof(buffer), 1, img);
        } else {
            if (isJPEG(buffer)) {
                firstFileFound = true;
                img = createNewFile(fileCount);
                fwrite(buffer, sizeof(buffer), 1, img);
            }
        }
    }
    free(buffer);
    fclose(f);
    return 0;
}

bool isJPEG(BYTE *buffer) {
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) {
        return true;
    }
    return false;
}

FILE* createNewFile(int fileCount) {
    char fileName[8];
    sprintf(fileName, "%03i.jpg", fileCount);
    return fopen(fileName, "w");
}
