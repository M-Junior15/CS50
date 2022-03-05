#include "helpers.h"
#include <math.h>
#include <stdio.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Get every pixel in the imagey
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // The average of each pixel
            float average = (float)(image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3;
            int x = round(average);
            
            image[i][j].rgbtRed = x;
            image[i][j].rgbtGreen = x;
            image[i][j].rgbtBlue = x;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{    
    for (int i = 0; i < height; i++)
    {
        for (int j =  0; j < width; j++)
        {
            // Formulas of sepia image
            float sepiaRed = 0.393 * image[i][j].rgbtRed
            + 0.769 * image[i][j].rgbtGreen
            + 0.189 * image[i][j].rgbtBlue;
            int x = round(sepiaRed);
            
            float sepiaGreen = 0.349 * image[i][j].rgbtRed
            + 0.686 * image[i][j].rgbtGreen
            + 0.168 * image[i][j].rgbtBlue;
            int y = round(sepiaGreen); 
            
            float sepiaBlue = 0.272 * image[i][j].rgbtRed
            + 0.534 * image[i][j].rgbtGreen
            + 0.131 * image[i][j].rgbtBlue;
            int z = round(sepiaBlue);
            
            // If the number is greater than 255 round it 255
            if (x > 255)
            {
                x = 255;
            }
            if (y > 255)
            {
                y = 255;
            }
            if (z > 255)
            {
                z = 255;
            }
            
            image[i][j].rgbtRed = x;
            image[i][j].rgbtGreen = y;
            image[i][j].rgbtBlue = z;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    
    // Make an temporary inverse array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][width - 1 - j];
        }
    }
    
    // Image receive the temporary array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Temporary array to store image values
    RGBTRIPLE temp[height][width];
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = 0, green = 0, blue = 0;
            float divider = 0.0;
            
            // Get each pixel inside of image
            // Get all pixel arround the middle pixel
            for (int x = i - 1; x < i + 2; x++)
            {
                for (int y = j - 1; y < j + 2; y++)
                {
                    if ((x >= 0 && x < height) && (y >= 0 && y < width))
                    {
                        red += image[x][y].rgbtRed;
                        green += image[x][y].rgbtGreen;
                        blue += image[x][y].rgbtBlue;
                        divider++;
                    }
                }
            }
            
            temp[i][j].rgbtRed = round(red / divider);
            temp[i][j].rgbtGreen = round(green / divider);       
            temp[i][j].rgbtBlue = round(blue / divider); 
        }
    }
    
    // Image receive the temporary array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}
