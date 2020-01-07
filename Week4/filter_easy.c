#include "helpers.h"
#include <math.h>
#include <stddef.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            RGBTRIPLE *ptr = &image[i][j];
            unsigned int avg = round((float)(((*ptr).rgbtRed + (*ptr).rgbtGreen + (*ptr).rgbtBlue)) / 3);
            (*ptr).rgbtRed = avg;
            (*ptr).rgbtGreen = avg;
            (*ptr).rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
