/* project01.cpp */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

extern const int MAXROWS;               // Maximum number of rows in image
extern const int MAXCOLS;                 // Maximum number of columns in image

void LoadImage(string imagefile, int image[MAXROWS][MAXCOLS])
{
    for (int i = 0; i < MAXROWS; i++)
    {
        for (int j = 0; j < MAXCOLS; j++)
        {
            image[i][j] = 0;
        }
    }

    std::cout << "File name: " << imagefile << std::endl;

    ifstream inputs;
    inputs.open(imagefile.c_str());

    if (!inputs.is_open())
    {
        std::cout << "Unable to open file" << std::endl;
        return;
    }

    for (int i = 0; i < MAXROWS; i++)
    {
        for (int j = 0; j < MAXCOLS; j++)
        {
            if (inputs.eof() || inputs.fail())
            {
                std::cout << "Reached end of file" << std::endl;
                return;
            }

            inputs >> image[i][j];
            std::cout << i << " " << j << " " << image[i][j] << std::endl;  // josh debug
        }
    }
    inputs.close();
}

// Loads the image from the file into the array.
// Parameters:
//  imagefile - the name of the file containing the image
//  image[MAXROWS][MAXCOLS] - the array for storing the image
// Returns: nothing


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