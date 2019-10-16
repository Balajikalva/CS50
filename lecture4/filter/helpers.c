#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int help;

    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)

        {
            help = image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue;

            help = help/3;

            image[i][j].rgbtRed = help;
            image[i][j].rgbtGreen = help;
            image[i][j].rgbtBlue = help;

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float colors[3];

    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            colors[0]= 0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen  + 0.189 * image[i][j].rgbtBlue;
            colors[1] = 0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen  + 0.168 * image[i][j].rgbtBlue;
            colors[2] = 0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen  + 0.131 * image[i][j].rgbtBlue;

            for (int k = 0 ; k < 3 ; k++)
           {
                if (colors[k] > 255)
                {
                    colors[k] = 255;
                }

           }
            image[i][j].rgbtRed  = colors[0];
            image[i][j].rgbtGreen  = colors[1];
            image[i][j].rgbtBlue  = colors[2];

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temp = 0;

    for ( int i = 0; i <  height ; i++)
    {
        for (int j = 0 ; j < width/2 ; j++)
        {
            temp = image[i][j].rgbtRed ;
            image[i][j].rgbtRed = image[i][width-1-j].rgbtRed ;
            image[i][width-1-j].rgbtRed = temp;
            temp = image[i][j].rgbtGreen ;
            image[i][j].rgbtGreen = image[i][width-1-j].rgbtGreen;
            image[i][width-1-j].rgbtGreen = temp ;
            temp = image[i][j].rgbtBlue  ;
            image[i][j].rgbtBlue = image[i][width-1-j].rgbtBlue;
            image[i][width-1-j].rgbtBlue = temp;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

void edges( int height , int width , RGBTRIPLE image[height][width])
{
    return;
}
