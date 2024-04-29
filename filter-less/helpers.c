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
    int sepiaRed, sepiaGreen, sepiaBlue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // apply sepia formula
            sepiaRed = round((0.393 *  image[i][j].rgbtRed) + (0.769 *  image[i][j].rgbtGreen) + (0.189 *  image[i][j].rgbtBlue));
            sepiaGreen = round((0.349 *  image[i][j].rgbtRed) + (0.686 *  image[i][j].rgbtGreen) + (0.168 *  image[i][j].rgbtBlue));
            sepiaBlue = round((0.272 *  image[i][j].rgbtRed) + (0.534 *  image[i][j].rgbtGreen) + (0.131 *  image[i][j].rgbtBlue));
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
    int stop = round(width/2);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < stop; j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][width-(j+1)];
            image[i][width-(j+1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    RGBTRIPLE px;
    int row, col;
    int pxvalueRed, pxvalueGreen, pxvalueBlue, avgRed, avgGreen, avgBlue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    // blurring the original picture based on the copy values
    for (int i = 1; i < height-1; i++)
    {
        for (int j = 1; j < width-1; j++)
        {
            avgRed = 0;
            avgGreen = 0;
            avgBlue = 0;
            for (int k = i-1; k < i+2; k++)
            {
                    avgRed = avgRed + copy[k][j-1].rgbtRed + copy[k][j].rgbtRed + copy[k][j+1].rgbtRed;
                    avgGreen = avgGreen + copy[k][j-1].rgbtGreen + copy[k][j].rgbtGreen + copy[k][j+1].rgbtGreen;
                    avgBlue = avgBlue + copy[k][j-1].rgbtBlue + copy[k][j].rgbtBlue + copy[k][j+1].rgbtBlue;
            }
            image[i][j].rgbtRed = round(avgRed / 9.0);
            image[i][j].rgbtGreen = round(avgGreen / 9.0);
            image[i][j].rgbtBlue = round(avgBlue / 9.0);
        }
    }
    // beware corners and edges
    image[0][width]
    image[height-1][width]
    image[height][0]
    image[height][width-1]
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avgRed = 0;
            avgGreen = 0;
            avgBlue = 0;
            for (int k = i-1; k < i+2; k++)
            {
                if (k < 0 | k > height-1) // top and bottom edges
                {
                    // change divider
                    divider = divider + 0;
                }
                else if (k > height-1)
                {

                }
                else
                {
                    avgRed = avgRed + copy[k][j-1].rgbtRed + copy[k][j].rgbtRed + copy[k][j+1].rgbtRed;
                    avgGreen = avgGreen + copy[k][j-1].rgbtGreen + copy[k][j].rgbtGreen + copy[k][j+1].rgbtGreen;
                    avgBlue = avgBlue + copy[k][j-1].rgbtBlue + copy[k][j].rgbtBlue + copy[k][j+1].rgbtBlue;
                    divider = divider + 3.0;
                }
            }
            image[i][j].rgbtRed = round(avgRed / 9.0);
            image[i][j].rgbtGreen = round(avgGreen / 9.0);
            image[i][j].rgbtBlue = round(avgBlue / 9.0);
            // If border
            if(i-1 < 0 | )
            {

            }
            else if (i == 0 & j == width-1)
            {

            }
            else if (i == height-1 & j == 0)
            else if (i == height-1 & j == width-1)

            // If edges
            if(i == 0 | i == height-1 | j == 0 | j == width-1)
            {

            }
    return;
}
