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
    for(int i=0; i<NUMOFROOMS; i++)
    {
        // Read room name
        getNextLine(line, 128);
        strcpy(m_Rms[i].m_sRoomName, line); // Copy room name into data structure i

        // Read room description
        getNextLine(line, 128);
        strcpy(m_Rms[i].m_sRoomDesc, line); // Copy room description into data structure i

        // Read room item
        getNextLine(line, 128);
        strcpy(m_Rms[i].m_sItemName, line); // Copy room item name into data structure i

        // Read room creature
        getNextLine(line, 128);
        strcpy(m_Rms[i].m_sCreatureName, line); // Copy room creature name into data structure i

        // Read North door
        getNextLine(line, 128);
        link = atoi(line); // Convert to room index
        if (link != -1 )
        {   
            setLinks(i, link, 'N');
        }
        // Call function to set link in adjacency matrix

        // Read South door
        getNextLine(line, 128);
        link = atoi(line);    // Convert to room index
        if (link != -1 )
        {   
            setLinks(i, link, 'S');
        }
        // Call function to set link in adjacency matrix

        // Read East door
        getNextLine(line, 128);
        link = atoi(line);
        if (link != -1 ) // Convert to room index
        {   
            setLinks(i, link, 'E');
        }
        // Call function to set link in adjacency matrix

        // Read West door
        getNextLine(line, 128);
        link = atoi(line);    // Convert to room index
        if (link != -1 )
        {   
            setLinks(i, link, 'W');
        }
        // Call function to set link in adjacency matrix

        // Read up stairway
        getNextLine(line, 128);
        link = atoi(line);    // Convert to room index
        if (link != -1 )
        {   
            setLinks(i, link, 'U');
        }
        // Call function to set link in adjacency matrix

        // Read down stairway
        getNextLine(line, 128);
        link = atoi(line);    // Convert to room index
        if (link != -1 )
        {   
            setLinks(i, link, 'D');
        }
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


    char p[10]; // Char pointer to store the command
    char direction[6]; // Char Array to store the direction

    sscanf(command, "%s", p);

    if(strcmp(p, "GO") == 0)
    {
        sscanf(command, "%s %s", p, direction);
        cout << "You want to go " << direction << endl;
        if(strcmp(direction, "N") == 0 || strcmp(direction, "NORTH") == 0)
        {
            for (int i = 0; i < NUMOFROOMS; i++) {
                if (m_cAdjMatrix[m_iLocation][i] == 'N') // if the character at the location is 'N'
                {
                    m_iLocation = i; // set the location to the index of the room
                    describeRoom(m_iLocation);
                    return false;
                }
            }

            cout << "You cannot go that direction." << endl;
            return false;
        }
        else if (strcmp(direction, "S") == 0 || strcmp(direction, "SOUTH") == 0)
        {
            for (int i = 0; i < NUMOFROOMS; i++) {
                if (m_cAdjMatrix[m_iLocation][i] == 'S') // if the character at the location is 'S'
                {
                    m_iLocation = i;
                    describeRoom(m_iLocation);
                    return false;
                }
            }

            // if the for loop completely executed and never returned, that means 'N' was not found
            cout << "You cannot go that direction." << endl;
            return false;
        }
        else if (strcmp(direction, "E") == 0 || strcmp(direction, "EAST") == 0)
        {
            for (int i = 0; i < NUMOFROOMS; i++) {
                if (m_cAdjMatrix[m_iLocation][i] == 'E')  // if the character at the location is 'E'
                {
                    m_iLocation = i;
                    describeRoom(m_iLocation);
                    return false;
                }
            }

            // if the for loop completely executed and never returned, that means 'N' was not found
            cout << "You cannot go that direction." << endl;
            return false;
        }
        else if (strcmp(direction, "W") == 0 || strcmp(direction, "WEST") == 0)
        {
            for (int i = 0; i < NUMOFROOMS; i++) {
                if (m_cAdjMatrix[m_iLocation][i] == 'W') // if the character at the location is 'W'
                {
                    m_iLocation = i;
                    describeRoom(m_iLocation);
                    return false;
                }
            }

            // if the for loop completely executed and never returned, that means 'N' was not found
            cout << "You cannot go that direction." << endl;
            return false;
        }
        else if (strcmp(direction, "U") == 0 || strcmp(direction, "UP") == 0)
        {
            for (int i = 0; i < NUMOFROOMS; i++) {
                if (m_cAdjMatrix[m_iLocation][i] == 'U') // if the character at the location is 'U'
                {
                    m_iLocation = i;
                    describeRoom(m_iLocation);
                    return false;
                }
            }

            // if the for loop completely executed and never returned, that means 'N' was not found
            cout << "You cannot go that direction." << endl;
            return false;
        }
        else if (strcmp(direction, "D") == 0 || strcmp(direction, "DOWN") == 0)
        {
            for (int i = 0; i < NUMOFROOMS; i++) {
                if (m_cAdjMatrix[m_iLocation][i] == 'D') // if the character at the location is 'D'
                {
                    m_iLocation = i;
                    describeRoom(m_iLocation);
                    return false;
                }
            }

            // if the for loop completely executed and never returned, that means 'N' was not found
            cout << "You cannot go that direction." << endl;
            return false;
        } 
        else
        {
            cout << "Invalid direction" << endl;
            return false;
        }
    }
    else if(strcmp(p, "TAKE") == 0)
    {
        cout << "This command is not implemented";
    }
    else if(strcmp(p, "FIGHT") == 0)
    {
        cout << "This command is not implemented";
    }
    else if(strcmp(p, "QUIT") == 0)
    {
        cout << "Bye!";
        return true;
    }
    else
    {
        cout << "Invalid command" << endl;
        return false;
    }
    return false;
}


void GameGraph::PrintAll()
/*
A function that prints all GameGraph data members to console, including rooms.
*/
{
    for (int i = 0; i < NUMOFROOMS; i++) {
        cout << "Room Name: " << m_Rms[i].m_sRoomName << endl;
        cout << "Room Description: " << m_Rms[i].m_sRoomDesc << endl;
        cout << "Room Item: " << m_Rms[i].m_sItemName << endl;
        cout << "Room Creature: " << m_Rms[i].m_sCreatureName << endl;
        for (int j = 0; j < NUMOFROOMS; j++) {
            if (m_cAdjMatrix[i][j] != ' ') {
                cout << "Link to room " << j << " in direction " << m_cAdjMatrix[i][j] << endl;
            }
        }
        cout << endl;
    }
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