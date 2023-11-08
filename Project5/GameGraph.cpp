// GameGraph.cpp -- CS221 -- Fall '23 -- Project 05//
#include <stdlib.h>
#include <string.>
#include <iostream>
#include <fstream>
#include <cstring>
#include "GameGraph.h"



#define NUMOFROOMS 20

using namespace std;


GameGraph::GameGraph()
// Default Constructor - Sets every private member of 'Gamegraph' to their default value //
{
    m_iLocation = 0;
    for (int i = 0; i < NUMOFROOMS; i++)
    {
        for (int j = 0; j < NUMOFROOMS; j++)
        {
            m_cAdjMatrix[i][j] = '0';
        }
    }
}



bool GameGraph::LoadGame(char *filename)
/*
A function that will load the game scenario from a file.

    Parameters
    ----------
    filename: *CHAR
        A character array that represents a line of text.
*/
{
    char line[128];
    int link;
    bool done;

    m_InFile.open(filename, ifstream::in); 
    if(!m_InFile.is_open())
    {
        // m_InFile.is_open() returns false if the file could not be found or
        //    if for some other reason the open failed.
        return false;
    }

    done = false;
    for(int i=0; i<20; i++)
    {
        // Read room name
        getNextLine(line, 128);
        /* --- Copy room name into data structure i --- */

        // Read room description
        getNextLine(line, 128);
        /* --- Copy room description into data structure i --- */

        // Read room item
        getNextLine(line, 128);
        /* --- Copy room item name into data structure i --- */

        // Read room creature
        getNextLine(line, 128);
        /* --- Copy room creature name into data structure i --- */

        // Read North door
        getNextLine(line, 128);
        link = atoi(line); // Convert to room index
        // Call function to set link in adjacency matrix

        // Read South door
        getNextLine(line, 128);
        link = atoi(line);    // Convert to room index
        // Call function to set link in adjacency matrix

        // Read East door
        getNextLine(line, 128);
        link = atoi(line);    // Convert to room index
        // Call function to set link in adjacency matrix

        // Read West door
        getNextLine(line, 128);
        link = atoi(line);    // Convert to room index
        // Call function to set link in adjacency matrix

        // Read up stairway
        getNextLine(line, 128);
        link = atoi(line);    // Convert to room index
        // Call function to set link in adjacency matrix

        // Read down stairway
        getNextLine(line, 128);
        link = atoi(line);    // Convert to room index
        // Call function to set link in adjacency matrix
    }
    return true;
}


bool GameGraph::doCommand(char *command)
/*
A function that executes a command from the user.

    Parameters
    ----------
    command: *CHAR
        A character array that represents a line of text. Only valid commands are: GO, TAKE, FIGHT, QUIT
*/
{
    char *p; // Char pointer to store the command
    char direction[2]; // Char Array to store the direction
    /*int roomIdx;
    int linkIdx;
    int done;*/

    sscanf(command, "%s", p);
    if(strcmp(p, "GO") == 0)
    {
        sscanf(command, "%s %s", p, direction);
        if(strcmp(direction, "N") == 0)
        {
            if(m_cAdjMatrix[m_iLocation][0] == 'N')
            {
                m_iLocation = 0;
                describeRoom(m_iLocation);
                return true;
            }
            else
            {
                cout << "You can't go that way" << endl;
                return false;
            }
        }
        else if(strcmp(direction, "S") == 0)
        {
            if(m_cAdjMatrix[m_iLocation][1] == 'S')
            {
                m_iLocation = 1;
                describeRoom(m_iLocation);
                return true;
            }
            else
            {
                cout << "You can't go that way" << endl;
                return false;
            }
        }
        else if(strcmp(direction, "E") == 0)
        {
            if(m_cAdjMatrix[m_iLocation][2] == 'E')
            {
                m_iLocation = 2;
                describeRoom(m_iLocation);
                return true;
            }
            else
            {
                cout << "You can't go that way" << endl;
                return false;
            }
        }
        else if(strcmp(direction, "W") == 0)
        {
            if(m_cAdjMatrix[m_iLocation][3] == 'W')
            {
                m_iLocation = 3;
                describeRoom(m_iLocation);
                return true;
            }
            else
            {
                cout << "You can't go that way" << endl;
                return false;
            }
        }
    }
    else if(strcmp(p, "TAKE") == 0)
    {
        cout << "This command is not implemented"
    }
    else if(strcmp(p, "FIGHT") == 0)
    {
        cout << "This command is not implemented"
    }
    else if(strcmp(p, "QUIT") == 0)
    {
        return false;
    }
    else
    {
        cout << "Invalid command" << endl;
        return false;
    }
    return false;
}



// ** Private Functions ** //

void GameGraph::getNextLine(char *line, int lineLen)
/*
A function that reads lines from the graph definition data.

    Parameters
    ----------
    line: *CHAR
        A character array that represents a line of text.
    lineLen: INT
        An integer that represents the length of the line of text.
*/
{
    int done = false;

    while(!done)
    {
        m_InFile.getline(line, lineLen);  
        // Note: m_InFile is an ifstream object that is part of the GameGraph class

        if(m_InFile.good())    // If a line was successfully read
        {
           if(strlen(line) == 0)  // Skip any blank lines
                continue;
            else if(line[0] == '#')  // Skip any comment lines
                continue;
            else done = true;    // Got a valid data line so return with this line
        }
        else
        {
            strcpy(line, "");
            return;
        }
    } // end while
}


void GameGraph::setLinks(int roomIdx, int linkIdx, char dCode)
/*
A function that sets the links between rooms.

    Parameters
    ----------
    roomIdx: INT
        An integer that represents the index of a room.
    linkIdx: INT
        An integer that represents the index of a link.
    dCode: CHAR
        A character that represents a direction code.
*/
{
    m_cAdjMatrix[roomIdx][linkIdx] = dCode;
}


void GameGraph::describeRoom(int roomIdx)
/*
A function that describes a room.

    Parameters
    ----------
    roomIdx: INT
        An integer that represents the index of a room.
*/
{
    cout << m_Rms[roomIdx].m_sRoomName << endl;
    cout << m_Rms[roomIdx].m_sRoomDesc << endl;
    cout << "You see a " << m_Rms[roomIdx].m_sItemName << " here." << endl;
    cout << "You see a " << m_Rms[roomIdx].m_sCreatureName << " here." << endl;
}




// ** GameGraph Destructor ** //

GameGraph::~GameGraph()
// Destructor - Closes the file //
{
    m_InFile.close();
}



/* void Character::setClass(int cl)
/*
A function that takes a class parameter, and sets it to a character class.

    Parameters
    ----------
    cl: INT
        An integer representing a 'class' archetype.

{
    m_iClass = cl;
} */