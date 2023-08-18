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



// The rest of the function prototypes go here
void FlipHorizontal(int image[MAXROWS][MAXCOLS])
{

}
void FlipVertical(int image[MAXROWS][MAXCOLS])
{

}
void RotateCW(int image[MAXROWS][MAXCOLS])
{

}
void RotateCCW(int image[MAXROWS][MAXCOLS])
{

}
void Transpose(int image[MAXROWS][MAXCOLS])
{
    
}