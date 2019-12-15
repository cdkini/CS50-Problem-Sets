#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>

int iterate_text(string text, char type);
int coleman_liau(float l, float s);


int main(void) {
    string text = get_string("Text: ");
    printf("Letters: %d\n", iterate_text(text, 'l'));
    printf("Words: %d\n", iterate_text(text, 'w'));
    printf("Sentences: %d\n", iterate_text(text, 's'));
    int cl_index = coleman_liau(1.0, 2.0);
    printf("%d\n", cl_index);
    return 0;
}


int iterate_text(string text, char type) {
    int lws_counts[] = {0, 1, 0};
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            lws_counts[0]++;
        }
        else if (text[i] == ' ') {
            lws_counts[1]++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')  {
            lws_counts[2]++;
        }
    }
    if (type == 'l') {
        return lws_counts[0];
    }
    else if (type == 'w') {
        return lws_counts[1];
    }
    else if (type == 's') {
        return lws_counts[2];
    }
    return 0;
}


int coleman_liau(float l, float s) {
    float index = 0.0588 * l - 0.296 * s - 15.8;
    return (int) round(index);
}
