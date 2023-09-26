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
            if (strcmp(pCurrent->getName(), characterName) == 0) // If the current Character name and the parameter are equal, remove the Character from the list
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