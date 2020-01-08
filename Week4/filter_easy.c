#include "helpers.h"
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>


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
        int a = 0, b = width-1;
        for (int j = 0; j < width/2; j++) {
            RGBTRIPLE *aPtr = &image[i][a], *bPtr = &image[i][b];
            RGBTRIPLE temp = image[i][a];
            *aPtr = image[i][b];
            *bPtr = temp;
            a++;
            b--;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            //Check if corner
            //Check if edge
            //Else
            unsigned int avg = round((float)(image[i-1][j-1] + image[i-1][j] + image[i-1][j+1] + image[i][j-1] + image[i][j] + image[i][j+1] + image[i+1][j-1] + image[i+1][j] + image[i+1][j+1]) / 9));
        }
    }
    return;
}
