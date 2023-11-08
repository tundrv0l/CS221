// GameGraph.h -- CS221 -- Fall '23 -- Project 05//

#pragma once

#include <stdlib.h>
#include <string.>
#include <iostream>
#include <fstream>


#define NUMOFROOMS 20

struct Room
{
    char m_sRoomName[64];
    char m_sRoomDesc[128];
    char m_sItemName[32];
    char m_sCreatureName[64];
};


class GameGraph
{
private:
    // ** Private Data Members ** //
    ifstream m_InFile;
    char m_cAdjMatrix[NUMOFROOMS][NUMOFROOMS];
    Room m_Rms[NUMOFROOMS];
    int m_iLocation;

    // ** Private Functions ** //
    void getNextLine(char *line, int lineLen); // Gets the next line from the file
    void setLinks(int roomIdx, int linkIdx, char dCode); // Sets the links between rooms
    void describeRoom(int roomIdx); // Describes the room

public:


    // ** GameGraph Constructors ** //
    GameGraph(); // Default constructor

    // ** GameGraph Observers ** //
    bool LoadGame(char *filename); // Loads the GameGraph from a file
    bool doCommand(char *command); // Executes a command from the user

    // ** GameGraph Destructor ** //
    ~GameGraph(); // Destructor

    // ** GameGraph Functions ** //
    void PrintAll(); // Prints all GameGraph data members to console, includes the items they are holding
};
