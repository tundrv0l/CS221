/* project01.cpp */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

extern const int MAXROWS;               // Maximum number of rows in image, grabbed from main.cpp
extern const int MAXCOLS;                 // Maximum number of columns in image, grabbed from main.cpp

void LoadImage(string imagefile, int image[MAXROWS][MAXCOLS])
{
    /*
    A function that loads the 10x10 image from the specified text file into a 2D array for processing.

    Parameters
    ----------
    imagefile: STRING
        The name of the file containing the image.
    
    image[MAXROWS][MAXCOLS]: INT
        The given 2D array for storing the image.
    */

    ifstream inputs;
    inputs.open(imagefile.c_str());

    for (int i = 0; i < MAXROWS; i++)
    {
        string line;
        getline(inputs, line); // Read the entire line into a string

        // Skip lines starting with '#', to ignore the header text
        if (line.size() > 0 && line[0] == '#')
        {
            i--; // Go back and re-read this line
            continue;
        }

        // Otherwise, read the line into the array
        for (int j = 0; j < MAXCOLS; j++)
        {

            inputs >> image[i][j];
        }
    }
    inputs.close();
}


void FlipHorizontal(int image[MAXROWS][MAXCOLS])
{
    /*
    A function that flips a 10x10 2D Array Horizontally.

    Parameters
    ----------
    image[MAXROWS][MAXCOLS]: INT
        The given 2D array for storing the image.
    */

    int temp[MAXROWS][MAXCOLS]; // Temporary array to store the flipped image

    // Copy the original image into the temporary array
    for (int i = 0; i < MAXROWS; i++)
    {
        for (int j = 0; j < MAXCOLS; j++)
        {

            temp[i][j] = image[i][MAXCOLS - j - 1]; // Flip the image horizontally
        }
    }

    for (int i = 0; i < MAXROWS; i++)
    {
        for (int j = 0; j < MAXCOLS; j++)
        {

            image[i][j] = temp[i][j]; // Copy the flipped image back into the original array to print
        }
    }

}

void FlipVertical(int image[MAXROWS][MAXCOLS])
{
    /*
    A function that flips a 10x10 2D Array Veritcally.

    Parameters
    ----------
    image[MAXROWS][MAXCOLS]: INT
        The given 2D array for storing the image.
    */

   int temp[MAXROWS][MAXCOLS]; // Temporary array to store the flipped image

    // Copy the original image into the temporary array
    for (int i = 0; i < MAXROWS; i++)
    {
        for (int j = 0; j < MAXCOLS; j++)
        {
            temp[i][j] = image[MAXROWS - i - 1][j]; // Flip the image veritcally
        }
    }

    for (int i = 0; i < MAXROWS; i++)
    {
        for (int j = 0; j < MAXCOLS; j++)
        {

            image[i][j] = temp[i][j]; // Copy the flipped image back into the original array to print
        }
    }

}
void RotateCW(int image[MAXROWS][MAXCOLS])
{
    /*
    A function that rotates a 10x10 2D Array clock-wise.

    Parameters
    ----------
    image[MAXROWS][MAXCOLS]: INT
        The given 2D array for storing the image.
    */

    int temp[MAXROWS][MAXCOLS]; // Temporary array to store the rotated image

    // Copy the original image into the temporary array
    for (int i = 0; i < MAXROWS; i++)
    {
        for (int j = 0; j < MAXCOLS; j++)
        {

            temp[i][j] = image[MAXROWS - j - 1][i]; // Rotate the image clock-wise
        }
    }

    for (int i = 0; i < MAXROWS; i++)
    {
        for (int j = 0; j < MAXCOLS; j++)
        {

            image[i][j] = temp[i][j]; // Copy the rotated image back into the original array to print
        }
    }

}

void RotateCCW(int image[MAXROWS][MAXCOLS])
{
    /*
    A function that rotates a 10x10 2D Array counter clock-wise.

    Parameters
    ----------
    image[MAXROWS][MAXCOLS]: INT
        The given 2D array for storing the image.
    */

    int temp[MAXROWS][MAXCOLS]; // Temporary array to store the rotated image

    for (int i = 0; i < MAXROWS; i++)
    {
        for (int j = 0; j < MAXCOLS; j++)
        {

            temp[i][j] = image[j][MAXCOLS - i - 1]; // Rotate the image counter clock-wise
        }
    }

    for (int i = 0; i < MAXROWS; i++)
    {
        for (int j = 0; j < MAXCOLS; j++)
        {

            image[i][j] = temp[i][j]; // Copy the rotated image back into the original array to print
        }
    }
}

void Transpose(int image[MAXROWS][MAXCOLS])
{
    /*
    A function that transposes a 10x10 2D Array.

    Parameters
    ----------
    image[MAXROWS][MAXCOLS]: INT
        The given 2D array for storing the image.
    */

     // Temporary array to store the transposed image

    for (int i = 0; i < MAXROWS; i++)
    {
        for (int j = i+1; j < MAXCOLS; j++) // Start at i+1 to avoid swapping the same values twice
        {
            int temp = image[i][j]; // Store the current value of the image into a temporary variable
            image[i][j] = image[j][i]; // Transpose the image
            image[j][i] = temp; // Store the temporary variable into the transposed image
        }
    }
    
}