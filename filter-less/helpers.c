#include "helpers.h"

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
    RGBTRIPLE px;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            px.rgbtRed = (0.393 *  image[i][j].rgbtRed) + (0.769 *  image[i][j].rgbtGreen) + (0.189 *  image[i][j].rgbtBlue);
            px.rgbtGreen = (0.349 *  image[i][j].rgbtRed) + (0.686 *  image[i][j].rgbtGreen) + (0.168 *  image[i][j].rgbtBlue);
            px.rgbtBlue = (0.272 *  image[i][j].rgbtRed) + (0.534 *  image[i][j].rgbtGreen) + (0.131 *  image[i][j].rgbtBlue);
            image[i][j].rgbtBlue = round(px.rgbtRed);
            image[i][j].rgbtGreen = round(px.rgbtGreen);
            image[i][j].rgbtRed = round(px.rgbtBlue);
        }
    }
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
