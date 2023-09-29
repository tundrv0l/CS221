// CharacterList.h -- CS221 -- Fall '23 -- Project 03//

#pragma once
#include "Character.h"
#include "Item.h"

class CharacterList
{
private:
    // ** CharacterList Data Members ** //
    Character *m_pHead; // Pointer to the head of the list

public:
    // ** CharacterList Constructors ** //
    CharacterList(); // Default constructor

    // ** CharacterList Transformers ** //
    bool addCharacter(Character *newCharacter); // Adds a character to the list NOTE: add a sort functionality per req
    Character *deleteCharacter(char *characterName); // Removes a character from the list
    bool addItem(char *characterName, Item *newItem); // Adds an item to a character's inventory
    Item *dropItem(char *characterName, char *itemName); // Removes an item from a character's inventory

    // ** CharacterList Observers ** //
    Item *getItem(char *characterName, char *itemName); // Returns an item from a character's inventory
    void printCharacters(); // Prints a character's data members to console

    // ** CharacterList Destructors ** //
    ~CharacterList(); // Destructor
};