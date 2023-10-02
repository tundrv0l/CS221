// Character.cpp -- CS221 -- Fall '23 -- Project 03//

#include <iostream>
#include <string>
#include <cstring>
#include "Character.h"

using namespace std;

// ** Character Constructors ** //

Character::Character()
// Default Constructor - Sets every private member of 'Character' to their unknown value (0 for ints) //
{
    strcpy_s(m_sName, "Unknown");
    m_iClass = 0;
    m_iAlignment = 0;
    m_iHitPoints = 0;
    for (int i = 0; i < 6; i++)
    {
        m_iCharTraits[i] = 0;
    }

    for (int i = 0; i < 10; i++)
    {
        m_Items[i].m_sItemName[0] = '\0';
    }
}

Character::Character(char *name, int cl, int al, int hp, int str, int dex, int cn, int itl, int wis, int chr) : m_iCharTraits{ str, dex, cn, itl, wis, chr }
// Parameterized Constructor - Sets every private member for 'Character' to their parameterized value //
{
    strcpy_s(m_sName, name); 
    m_iClass = cl;
    m_iAlignment = al;
    m_iHitPoints = hp;

    for (int i = 0; i < 10; i++)
    {
        m_Items[i].m_sItemName[0] = '\0';
    }
}

// ** Character Transformers ** //

void Character::setName(char *name)
/*
A function that takes a name parameter, and sets it to a character array.

    Parameters
    ----------
    *name: CHAR ARRAY
        A pointer to a character array to set our member array to.
*/
{
    strcpy_s(m_sName, name);
}

void Character::setClass(int cl)
/*
A function that takes a class parameter, and sets it to a character class.

    Parameters
    ----------
    cl: INT
        An integer representing a 'class' archetype.
*/
{
    m_iClass = cl;
}

void Character::setAlignment(int al)
/*
A function that takes an alignment parameter, and sets it to a character alignment.

    Parameters
    ----------
    al: INT
        An integer representing a 'alignment' archetype.
*/
{
    m_iAlignment = al;
}

void Character::setHitPoints(int hp)
/*
A function that takes a hit point parameter, and sets it to a character hit point value.

    Parameters
    ----------
    hp: INT
        An integer representing a hit point value.
*/
{
    m_iHitPoints = hp;
}

void Character::setStrength(int str)
/*
A function that takes a strength parameter, and sets it to the strength value index.

    Parameters
    ----------
    str: INT
        An integer representing a strength value.
*/
{
    m_iCharTraits[0] = str;
}

void Character::setDexterity(int dex)
/*
A function that takes a dexterity parameter, and sets it to the dexterity value index.

    Parameters
    ----------
    dex: INT
        An integer representing a dexterity value.
*/
{
    m_iCharTraits[1] = dex;
}

void Character::setConstitution(int cn)
/*
A function that takes a constitution parameter, and sets it to the constitution value index.

    Parameters
    ----------
    cn: INT
        An integer representing a constitution value.
*/
{
    m_iCharTraits[2] = cn;
}

void Character::setIntelligence(int itl)
/*
A function that takes an intelligence parameter, and sets it to the intelligence value index.

    Parameters
    ----------
    itl: INT
        An integer representing an intelligence value.
*/
{
    m_iCharTraits[3] = itl;
}

void Character::setWisdom(int wis)
/*
A function that takes a wisdom parameter, and sets it to the wisdom value index.

    Parameters
    ----------
    wis: INT
        An integer representing a wisdom value.
*/
{
    m_iCharTraits[4] = wis;
}

void Character::setCharisma(int chr)
/*
A function that takes a charisma parameter, and sets it to the charisma value index.

    Parameters
    ----------
    chr: INT
        An integer representing a charisma value.
*/
{
    m_iCharTraits[5] = chr;
}

bool Character::addItem(Item *item)
/*
A function that takes an item parameter, and adds it to the character's inventory.

    Parameters
    ----------
    *item: ITEM
        A pointer to an item to add to the character's inventory.

    Returns
    -------
    BOOL
        A boolean value representing whether or not the item was added to the inventory. TRUE if added, FALSE if not.
*/
{
    for (int i = 0; i < 10; i++) // Iterate through the character's inventory
    {
        if (m_Items[i].m_sItemName[0] == '\0') // If the current inventory slot is empty, add the item and return true
        {   
            m_Items[i] = *item;
            return true;
        }
    }
    return false; 
}

Item *Character::dropItem(char *itemName)
/*
A function that takes an item name parameter, and then locates and removes it from the character's inventory.

    Parameters
    ----------
    *itemName: CHAR ARRAY
        A pointer to a character array representing the name of the item to remove from the character's inventory.

    Returns
    -------
    ITEM
        A pointer to an item that was removed from the character's inventory. NULL if the item was not found.
*/
{
    for (int i = 0; i < 10; i++) // Iterate through the character's inventory
    {
        if (strcmp(m_Items[i].m_sItemName, itemName) == 0) // If the current inventory slot matches the item name, remove the item and return it
        {
            Item *temp = &m_Items[i]; // Create a temporary item pointer to return
            m_Items[i].m_sItemName[0] = '\0'; // Set the item name to null
            return temp;
        }
    }
    return NULL;
}

// ** Character Observers ** //

char *Character::getName()
/*
A function that returns the name member.

    Returns
    ----------
    *m_sName: CHAR ARRAY
        Returns m_sName, a pointer to a character array.
*/
{
    return m_sName;
}

int Character::getClass()
/*
A function that returns the class archetype.

    Returns
    ----------
    m_iClass: INT
        The member representing a 'class' archetype.
*/
{
    return m_iClass;
}

int Character::getAlignment()
/*
A function that returns the Character's alignment.

    Returns
    ----------
    m_iAlignment: INT
        The member representing a 'alignment' archetype.
*/
{
    return m_iAlignment;
}

int Character::getHitPoints()
/*
A function that returns a Character's hit point value.

    Returns
    ----------
    m_iHitPoints: INT
        An integer representing a hit point value.
*/
{
    return m_iHitPoints;
}

int Character::getStrength()
/*
A function returns the strength value.

    Returns
    ----------
    str: INT
        An integer representing a strength value.
*/
{
    return m_iCharTraits[0];
}

int Character::getDexterity()
/*
A function returns the dexertity value.

    Returns
    ----------
    dex: INT
        An integer representing a dexterity value.
*/
{
    return m_iCharTraits[1];
}

int Character::getConstitution()
/*
A function returns the constitution value.

    Returns
    ----------
    cn: INT
        An integer representing a constitution value.
*/
{
    return m_iCharTraits[2];
}

int Character::getIntelligence()
/*
A function returns the intelligence value.

    Returns
    ----------
    itl: INT
        An integer representing an intelligence value.
*/
{ 
    return m_iCharTraits[3];
}

int Character::getWisdom()
/*
A function returns the wisdom value.

    Returns
    ----------
    wis: INT
        An integer representing a wisdom value.
*/
{
    return m_iCharTraits[4];
}

int Character::getCharisma()
/*
A function returns the charisma value.

    Returns
    ----------
    chr: INT
        An integer representing a charisma value.
*/
{
    return m_iCharTraits[5];
}

Item* Character::getItem(char* itemName)
/*
A function that takes an item name parameter, and returns the item from the character's inventory.

    Parameters
    ----------
    *itemName: CHAR ARRAY
        A pointer to a character array representing the name of the item to return from the character's inventory.

    Returns
    -------
    ITEM*
        A pointer to an item that was found from the character's inventory. NULL if the item was not found.
*/
{
    Item* tempItems = m_Items; // Store the array into a temporary pointer for comparison
    for (int i = 0; i < 10; i++) // Iterate through the character's inventory
    {
        if (strcmp(tempItems[i].m_sItemName, itemName) == 0) // If the current inventory slot matches the item name, return the item
        {
            return &tempItems[i];
        }
    }
    return nullptr;
}

// ** Character Destructor ** //

Character::~Character()
/*
A destructor for the Character class.
*/
{
    delete m_pNext;
}

// ** Character Functions ** //

void Character::printAll()
/*
A function that prints all character data members to console. Includes the items they are holding.
*/
{
    cout << "#------------------#" << endl;
    cout << "Name: " << m_sName << endl;
    cout << "Class: " << m_iClass << endl;
    cout << "Alignment: " << m_iAlignment << endl;
    cout << "Hit Points: " << m_iHitPoints << endl;
    cout << "Strength: " << m_iCharTraits[0] << endl;
    cout << "Dexterity: " << m_iCharTraits[1] << endl;
    cout << "Constitution: " << m_iCharTraits[2] << endl;
    cout << "Intelligence: " << m_iCharTraits[3] << endl;
    cout << "Wisdom: " << m_iCharTraits[4] << endl;
    cout << "Charisma: " << m_iCharTraits[5] << endl;
    cout << "Inventory: " << endl;
    cout << "-------------" << endl;
    for (int i = 0; i < 10; i++)
    {
        if (m_Items[i].m_sItemName[0] != '\0')
        {
            cout << "Item Name: " << m_Items[i].m_sItemName << endl;
            cout << "Item Type: " << m_Items[i].m_iType << endl;
            cout << "Item Value: " << m_Items[i].m_dValue << endl;
            cout << "Item Weight: " << m_Items[i].m_dWeight << endl;
        }
    }
    cout << "#------------------#" << endl;
    cout << endl;
}