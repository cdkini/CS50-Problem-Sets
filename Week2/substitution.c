#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>

char decypher(char letter, string cipher);
int is_valid_key(string key);


int main(int argc, string argv[]) {
    string key = argv[1];
    if (argc != 2) {
        printf("Invalid argument! Please use a single key.\n");
        return 1;
    }
    if (is_valid_key(key) == 0) {
        printf("Not a valid key. Please use each letter once.\n");
        return 1;
    }
    string text = get_string("plaintext: ");
    printf("%s", "ciphertext: ");
    for (int i = 0; text[i] != '\0'; i++) {
        printf("%c", decypher(text[i], key));
    }
    printf("%c", '\n');
    return 0;
}

char decypher(char letter, string cipher) {
    int loc = 0;
    if (isupper(letter) != 0) {
        loc = letter - 65;
        for (int i = 0; i <= loc; i++) {
            if (i == loc) {
                printf("%c", toupper(cipher[i]));
            }
        }
    }
    else if (islower(letter) != 0) {
        loc = letter - 97;
        for (int i = 0; i <= loc; i++) {
            if (i == loc) {
                printf("%c", tolower(cipher[i]));
            }
        }
    }
    else {
        printf("%c", letter);
        return 0;
    }
    return 0;
}

int is_valid_key(string key) {
    if (strlen(key) != 26) {
        return 0;
    }
    int total = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        if (isalpha(key[i]) == 0) {
            return 0;
        }
        total += toupper(key[i]);
    }
    if (total != 2015) {
        return 0;
    }
    return 1;
}
