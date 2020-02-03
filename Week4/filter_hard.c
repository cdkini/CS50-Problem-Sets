#include "helpers.h"
#include <math.h>

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
   RGBTRIPLE blurredArr[height][width];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            unsigned int newRed = 0, newGreen = 0, newBlue = 0;
            float count = 0;
            for (int a = i - 1; a < i + 2; a++) {
                for (int b = j - 1; b < j + 2; b++) {
                    if (a >= 0 && b >= 0 && a < height && b < width) {
                        newRed += image[a][b].rgbtRed;
                        newGreen += image[a][b].rgbtGreen;
                        newBlue += image[a][b].rgbtBlue;
                        count++;
                    }
                }
            }
            blurredArr[i][j].rgbtRed = round(newRed/count);
            blurredArr[i][j].rgbtGreen = round(newGreen/count);
            blurredArr[i][j].rgbtBlue = round(newBlue/count);
        }
    }
    for (int x = 0; x < height; x++) {
        for (int y = 0; y < width; y++) {
            RGBTRIPLE *ptr = &image[x][y];
            ptr->rgbtRed = blurredArr[x][y].rgbtRed;
            ptr->rgbtGreen = blurredArr[x][y].rgbtGreen;
            ptr->rgbtBlue = blurredArr[x][y].rgbtBlue;
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width]) {
    RGBTRIPLE edgesArr[height][width]; // New array to store updated pixels
    int gxArr[] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    int gyArr[] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};
    // Iterate through pixels
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int index = 0;
            unsigned int redX = 0, greenX = 0, blueX = 0, redY = 0, greenY = 0, blueY = 0; // Store new RGB values
            // Iterate through 3x3 grid surrounding pixel image[i][j]
            for (int a = i - 1; a < i + 2; a++) {
                for (int b = j - 1; b < j + 2; b++) {
                    if (a >= 0 && b >= 0 && a < height && b < width) {
                        redX += (gxArr[index] * image[a][b].rgbtRed);
                        greenX += (gxArr[index] * image[a][b].rgbtGreen);
                        blueX += (gxArr[index] * image[a][b].rgbtBlue);

                        redY += (gyArr[index] * image[a][b].rgbtRed);
                        greenY += (gyArr[index] * image[a][b].rgbtGreen);
                        blueY += (gyArr[index] * image[a][b].rgbtBlue);
                    }
                    index++;
                }
            }
            // New value is the sqrt of Gx^2 + Gy^2
            edgesArr[i][j].rgbtRed = fmin(round(sqrt((float)(redX * redX) + (redY * redY))), 255);
            edgesArr[i][j].rgbtGreen = fmin(round(sqrt((float)(greenX * greenX) + (greenY * greenY))), 255);
            edgesArr[i][j].rgbtBlue = fmin(round(sqrt((float)(blueX * blueX) + (blueY * blueY))), 255);
        }
    }
    // Iterate through edgesArr and use pointer to move values to original picture
    for (int x = 0; x < height; x++) {
        for (int y = 0; y < width; y++) {
            RGBTRIPLE *ptr = &image[x][y];
            ptr->rgbtRed = edgesArr[x][y].rgbtRed;
            ptr->rgbtGreen = edgesArr[x][y].rgbtGreen;
            ptr->rgbtBlue = edgesArr[x][y].rgbtBlue;
        }
    }
}
