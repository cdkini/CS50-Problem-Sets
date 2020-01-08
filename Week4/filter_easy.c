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
    // Iterate through each pixel
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            //Initilaize pixel pointer
            RGBTRIPLE *ptr = &image[height][width];
            //Create an array of RGB colors to store RGB sums
            unsigned int rgbArr[3];
            //Check if pixel is a corner
            if ((i == 0 || i == height - 1) && (j == 0 || j == width - 1)) {
                printf("\n");
            }
            //Check if pixel is on an edge
            else if ((i == 0 || i == height - 1) || (j == 0 || j == width - 1)) {
                printf("\n");
            }
            //Else is a regular pixel
            else {
                for (int k = i-1; k < i+2; k++) {
                    for (int l = j-1; l < j+2; l++) {
                        rgbArr[0] += image[k][l].rgbtRed;
                        rgbArr[1] += image[k][l].rgbtGreen;
                        rgbArr[2] += image[k][l].rgbtBlue;

                    }
                }
                ptr->rgbtRed = rgbArr[0] / 9;
                ptr->rgbtGreen = rgbArr[1] / 9;
                ptr->rgbtBlue = rgbArr[2] / 9;
            }
            //Reset rgbArr for use with next pixel
            rgbArr[] = { 0, 0, 0 };
        }
    }
    return;
}
