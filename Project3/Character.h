// Character.h -- CS221 -- Fall '23 -- Project 03//

#pragma once

#include <string>
#include "Item.h"

class Character
{
private:
    // ** Private Data Members ** //
    char m_sName[65]; // Character name (up to 64 characters, +1 to account for null terminator)
    int m_iClass; // Character class
    int m_iAlignment; // Character alignment
    int m_iHitPoints; // Character hit points
    int m_iCharTraits[6]; // Character traits (By index: STR[0], DEX[1], CON[2], INT[3], WIS[4], CHA[5])
    Item m_Items[10]; // Character inventory (up to 10 items)


public:

    // ** Public Data Members ** //
    Character *m_pNext; // Pointer to the next Character in the list

    // ** Character Constructors ** //
    Character(); // Default constructor

    Character(char *name, int cl, int al, int hp, int str, int dex, int cn, int itl, int wis, int chr); // Parameterized constructor

    // ** Character Transformers ** //

    void setName(char *name); // Sets m_SName to parameter 'name'
    void setClass(int cl); // Sets m_iClass to parameter 'cl'
    void setAlignment(int al); // Sets m_iAlignment to parameter 'al'
    void setHitPoints(int hp); // Sets m_iHitPoints to parameter 'hp'
    void setStrength(int str); // Sets m_iCharTraits[0] to parameter 'str'
    void setDexterity(int dex); // Sets m_iCharTraits[1] to parameter 'dex'
    void setConstitution(int con); // Sets m_iCharTraits[2] to parameter 'con'
    void setIntelligence(int itl); // Sets m_iCharTraits[3] to parameter 'itl'
    void setWisdom(int wis); // Sets m_iCharTraits[4] to parameter 'wis'
    void setCharisma(int chr); // Sets m_iCharTraits[5] to parameter 'chr'
    bool addItem(Item *item); // Adds an item to the character's inventory
    Item *dropItem(char *itemName); // Removes an item from the character's inventory



    // ** Character Observers ** //
    char *getName(); // Gets the m_sName array
    int getClass(); // Gets the m_iClass integer
    int getAlignment(); // Gets the m_iAlignment integer
    int getHitPoints(); // Gets the m_iHitPoints integer
    int getStrength(); // Gets the m_iCharTraits[0] integer
    int getDexterity(); // Gets the m_iCharTraits[1] integer
    int getConstitution(); // Gets the m_iCharTraits[2] integer
    int getIntelligence(); // Gets the m_iCharTraits[3] integer
    int getWisdom(); // Gets the m_iCharTraits[4] integer
    int getCharisma(); // Gets the m_iCharTraits[5] integer
    Item *getItem(char *itemName); // Returns an item from the character's inventory

    // ** Character Destructor ** //
    ~Character(); // Destructor

    // ** Character Functions ** //
    void printAll(); // Prints all character data members to console, includes the items they are holding
    void printName(); // Prints the character's name to console


};
