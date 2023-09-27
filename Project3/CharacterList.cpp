// Character.cpp -- CS221 -- Fall '23 -- Project 03//

#include "CharacterList.h"
#include "Character.h"
#include "Item.h"
#include <iostream>
#include <cstring>

using namespace std;

// ** CharacterList Constructors ** //

CharacterList::CharacterList()
// Default constructor - Sets the head pointer to null //
{
    m_pHead = nullptr;
}

// ** CharacterList Transformers ** //

bool CharacterList::addCharacter(Character *newCharacter)
/*
#TODO - Add a sort functionality per req
A function that takes a character pointer, and adds it to a ordered linked list sorted by name.

    Parameters
    ----------
    *newCharacter: CHARACTER POINTER
        A pointer to a character to add to the list.

    Returns
    -------
    bool
        A boolean value representing whether or not the character was added to the list. True if added, false if not.
*/
{
    // If the list is empty, set the head to the new character
    if (m_pHead == nullptr)
    {
        m_pHead = newCharacter;
        return true;
    }


    // If the list is not empty, add the character to the end of the list
    else
    {
        Character *pCurrent = m_pHead;
        while (pCurrent != nullptr)
        {
            pCurrent = pCurrent->m_pNext;
        }
        pCurrent->m_pNext = newCharacter;
        return true;
    }
    return false;
}

Character *CharacterList::deleteCharacter(char *characterName)
/*
A function that takes a character name, and removes it from the list.

    Parameters
    ----------
    *characterName: CHAR ARRAY
        A pointer to a character array to remove from the list.

    Returns
    -------
    CHARACTER POINTER
        A pointer to the character that was removed from the list. NULL if the character was not found.
*/
{
    // If the list is empty, return null
    if (m_pHead == nullptr)
    {
        return nullptr;
    }

    // If the list is not empty, remove the character from the list
    else
    {
        Character *pCurrent = m_pHead;
        Character *pPrevious = nullptr;
        while (pCurrent != nullptr)
        {
            // If the current Character name and the parameter are equal, remove the Character from the list
            if (strcmp(pCurrent->getName(), characterName) == 0)
            {
                if (pPrevious == nullptr) // If the previous Character is null, set the head to the next character
                {
                    m_pHead = pCurrent->m_pNext; 
                    return pCurrent; 
                }
                else
                {
                    pPrevious->m_pNext = pCurrent->m_pNext; // Set the previous Character's next pointer to the current Character's next pointer
                    return pCurrent; 
                }
            }
            pPrevious = pCurrent;
            pCurrent = pCurrent->m_pNext;
        }
    }
    return nullptr;
}

bool CharacterList::addItem(char *characterName, Item *newItem)
/*
A function that takes a character name and an item pointer, and adds the item to the character's inventory.

    Parameters
    ----------
    *characterName: CHAR ARRAY
        A pointer to the Character name to add the item to.
    *newItem: ITEM POINTER
        A pointer to an item to add to the character's inventory.

    Returns
    -------
    bool
        A boolean value representing whether or not the item was added to the character's inventory. True if added, false if not.
*/
{
    // If the list is empty, return false
    if (m_pHead == nullptr)
    {
        return false;
    }

    // If the list is not empty, add the item to the character's inventory
    else
    {
        Character *pCurrent = m_pHead;
        while (pCurrent != nullptr)
        {
            // If the current Character name and the parameter are equal, add the item to the Character's inventory
            if (strcmp(pCurrent->getName(), characterName) == 0)
            {
                pCurrent->addItem(newItem);
                return true;
            }
            pCurrent = pCurrent->m_pNext;
        }
    }
    return false;
}


Item *CharacterList::dropItem(char *characterName, char *itemName)
/*
A function that takes a character name and an item name, and removes the item from the character's inventory.

    Parameters
    ----------
    *characterName: CHAR ARRAY
        A pointer to the Character name to remove the item from.
    *itemName: CHAR ARRAY
        A pointer to the item name to remove from the character's inventory.

    Returns
    -------
    ITEM POINTER
        A pointer to the item that was removed from the character's inventory. NULL if the item was not found.
*/
{
    // If the list is empty, return null
    if (m_pHead == nullptr)
    {
        return nullptr;
    }

    // If the list is not empty, remove the item from the character's inventory
    else
    {
        Character *pCurrent = m_pHead;
        while (pCurrent != nullptr)
        {
            // If the current Character name and the parameter are equal, remove the item from the Character's inventory
            if (strcmp(pCurrent->getName(), characterName) == 0)
            {
                return pCurrent->dropItem(itemName); // Return a item pointer if removed from the character's inventory, returns null if the item is not found
            }
            pCurrent = pCurrent->m_pNext;
        }
    }
    return nullptr;
}



// ** CharacterList Observers ** //

Item *CharacterList::getItem(char *characterName, char *itemName)
/*
A function that takes a character name and an item name, and removes the item from the character's inventory.

    Parameters
    ----------
    *characterName: CHAR ARRAY
        A pointer to the Character name to get the item from.
    *itemName: CHAR ARRAY
        A pointer to the item name to get from the character's inventory.

    Returns
    -------
    ITEM POINTER
        A pointer to the item that was retrieved from the character's inventory. NULL if the item was not found or if the character was not found.
*/
{
    // If the list is empty, return null
    if (m_pHead == nullptr)
    {
        return nullptr;
    }

    // If the list is not empty, remove the item from the character's inventory
    else
    {
        Character *pCurrent = m_pHead;
        while (pCurrent != nullptr)
        {
            // If the current Character name and the parameter are equal, remove the item from the Character's inventory
            if (strcmp(pCurrent->getName(), characterName) == 0)
            {
                return pCurrent->getItem(itemName); // Return the item (as a pointer) from the character's inventory, returns null if the item is not found
            }
            pCurrent = pCurrent->m_pNext;
        }
    }
    return nullptr;
}

void CharacterList::printCharacters()
/*
A function that prints the data members of each character in the list to the console.
*/
{
    // If the list is empty, return null
    if (m_pHead == nullptr)
    {
        return;
    }

    // If the list is not empty, print the data members of each character in the list
    else
    {
        Character *pCurrent = m_pHead;
        while (pCurrent != nullptr) // Iterate through the list
        {
            cout << "Name: " << pCurrent->getName() << endl;
            cout << "Class: " << pCurrent->getClass() << endl;
            cout << "Alignment: " << pCurrent->getAlignment() << endl;
            cout << "Hit Points: " << pCurrent->getHitPoints() << endl;
            cout << "Strength: " << pCurrent->getStrength() << endl;
            cout << "Dexterity: " << pCurrent->getDexterity() << endl;
            cout << "Constitution: " << pCurrent->getConstitution() << endl;
            cout << "Intelligence: " << pCurrent->getIntelligence() << endl;
            cout << "Wisdom: " << pCurrent->getWisdom() << endl;
            cout << "Charisma: " << pCurrent->getCharisma() << endl;
            cout << endl;
            pCurrent = pCurrent->m_pNext;
        }
    }
}