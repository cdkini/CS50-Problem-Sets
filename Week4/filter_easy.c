#include "helpers.h"
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


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
    // Iterate through each pixel
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            //Initialize pixel pointer
            RGBTRIPLE *ptr = &image[i][j];
            //Initialize array to store sum of RGB values
            unsigned int rgbArr[] = { 0, 0, 0 };
            //Initialize denominator to avg out rgbArr
            float denom = 0;
            for (int a = i - 1; a < i + 2; a++) {
                for (int b = j - 1; b < j + 2; b++) {
                    // Check if pixel exists
                    if (!((a < 0 || b < 0) || (a > height || b > width))) {
                        rgbArr[0] += image[a][b].rgbtRed;
                        rgbArr[1] += image[a][b].rgbtGreen;
                        rgbArr[2] += image[a][b].rgbtBlue;
                        denom++;
                    }
                }
            }
            //Use values in array with ptr to change pixel
            ptr->rgbtRed = round(rgbArr[0] / denom);
            ptr->rgbtGreen = round(rgbArr[1] / denom);
            ptr->rgbtBlue = round(rgbArr[2] / denom);
        }
    }
    return;
}
