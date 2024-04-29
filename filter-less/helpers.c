#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avg = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed, sepiaGreen, sepiaBlue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // apply sepia formula
            sepiaRed = round((0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) +
                             (0.189 * image[i][j].rgbtBlue));
            sepiaGreen = round((0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) +
                               (0.168 * image[i][j].rgbtBlue));
            sepiaBlue = round((0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) +
                              (0.131 * image[i][j].rgbtBlue));
            // check for values outside of bound [0-255]
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            // load new values into original pixel
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    int stop = round(width / 2);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < stop; j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    RGBTRIPLE px;
    int row_minus, row_plus, col_minus, col_plus;
    int pxvalueRed, pxvalueGreen, pxvalueBlue, avgRed, avgGreen, avgBlue;
    float divider;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    // blurring the original picture based on the copy values
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avgRed = 0;
            avgGreen = 0;
            avgBlue = 0;
            divider = 0;
            col_minus = j - 1;
            col_plus = j + 1;
            row_minus = i - 1;
            row_plus = i + 1;
            for (int k = row_minus; k <= row_plus; k++)
            {
                if (k<0 | k> height - 1) // top and bottom edges
                {
                    // change divider
                    divider = divider + 0;
                }
                else
                {
                    for (int l = col_minus; l <= col_plus; l++)
                    {
                        if (l<0 | l> width - 1)
                        {
                            // change divider
                            divider = divider + 0;
                        }
                        else
                        {
                            avgRed = avgRed + copy[k][l].rgbtRed;
                            avgGreen = avgGreen + copy[k][l].rgbtGreen;
                            avgBlue = avgBlue + copy[k][l].rgbtBlue;
                            divider = divider + 1.0;
                        }
                    }
                }
            }
            image[i][j].rgbtRed = round(avgRed / divider);
            image[i][j].rgbtGreen = round(avgGreen / divider);
            image[i][j].rgbtBlue = round(avgBlue / divider);
        }
    }
    return;
}
