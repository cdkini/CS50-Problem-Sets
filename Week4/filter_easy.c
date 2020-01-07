#include "helpers.h"
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>

bool isEvenRow(unsigned int array[]) {
    int count = 0;
    for (int i = 0; array[i] != '\0'; i++) {
        count++;
    }
    if (count % 2 == 0) {
        return true;
    }
    return false;
}

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            RGBTRIPLE *ptr = &image[i][j];
            unsigned int avg = round((float)((ptr->rgbtRed + ptr->rgbtGreen + ptr->rgbtBlue)) / 3);
            ptr->rgbtRed = avg;
            ptr->rgbtGreen = avg;
            ptr->rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width]) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            RGBTRIPLE *ptr = &image[i][j];
            unsigned int rgbArr[3];

            rgbArr[0] = round((float) (ptr->rgbtRed * .393) + (ptr->rgbtGreen * .769) + (ptr->rgbtBlue * .189));
            rgbArr[1] = round((float) (ptr->rgbtRed * .349) + (ptr->rgbtGreen * .686) + (ptr->rgbtBlue * .168));
            rgbArr[2] = round((float) (ptr->rgbtRed * .272) + (ptr->rgbtGreen * .534) + (ptr->rgbtBlue * .131));

            for (int k = 0; k < 3; k++) {
                if (rgbArr[k] > 255) {
                    rgbArr[k] = 255;
                }
                if (k == 0) {
                    ptr->rgbtRed = rgbArr[k];
                }
                else if (k == 1) {
                    ptr->rgbtGreen = rgbArr[k];
                }
                else {
                    ptr->rgbtBlue = rgbArr[k];
                }
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]) {
    for (int i = 0; i < height; i++) {
        for (int j = 0)
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
