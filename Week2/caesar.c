#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>

char decrypt_letter(char letter, int key);


int main(int argc, string argv[]) {
    if (argc != 2) {
        printf("Invalid argument! Please use a single cipher key.\n");
        return 1;
    }
    int cipher = atoi(argv[1]);
    if (cipher == 0) {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string text = get_string("plaintext: ");
    printf("ciphertext: ");

    for (int i = 0; text[i] != '\0'; i++) {
        decrypt_letter(text[i], cipher);
    }
    printf("\n");
    return 0;
}

char decrypt_letter(char letter, int key) {
    int upper_bound = 0;
    key = key % 26;

    if (islower(letter) != 0) {
        upper_bound = 122;
    }
    else if (isupper(letter) != 0) {
        upper_bound = 90;
    }
    else {
        printf("%c", letter);
        return 0;
    }

    if ((key + letter) > upper_bound) {
        printf("%c", (key + letter) - 26);
    }
    else {
        printf("%c", (key + letter));
    }
    return 0;
}
