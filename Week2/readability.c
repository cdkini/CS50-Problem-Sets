#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int coleman_liau(float l, float s);


int main(void) {
    string text = get_string("Text: ");

    float l = (float) count_letters(text) / count_words(text) * 100;
    float s = (float) count_sentences(text) / count_words(text) * 100;
    int cl_index = coleman_liau(l, s);

    if (cl_index >= 1 && cl_index <= 16) {
        printf("Grade %d\n", cl_index);
    }
    else if (cl_index > 16) {
        printf("Grade 16+\n");
    }
    else {
        printf("Before Grade 1\n");
    }
}

int count_letters(string text) {
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            count++;
        }
    }
    return count;
}

int count_words(string text) {
    int count = 1;
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ') {
            count++;
        }
    }
    return count;
}

int count_sentences(string text) {
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            count++;
        }
    }
    return count;
}

int coleman_liau(float l, float s) {
    float index = 0.0588 * l - 0.296 * s - 15.8;
    return round(index);
}
