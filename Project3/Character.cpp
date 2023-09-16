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
}

//Might change this array population as well
Character::Character(char *name, int cl, int al, int hp, int str, int dex, int cn, int itl, int wis, int chr) : m_iCharTraits{ str, dex, cn, itl, wis, chr }
// Parameterized Constructor - Sets every private member for 'Character' to their parameterized value //
{
    strcpy_s(m_sName, name); 
    m_iClass = cl;
    m_iAlignment = al;
    m_iHitPoints = hp;
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
    strcpy_s(m_sName, name); // Might remove, not sure how he wants this done
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

// ** Character Observers ** //

void Character::getName(char *name)
/*
A function that takes a name parameter, and copies it to a character array.

    Parameters
    ----------
    *name: CHAR ARRAY
        A pointer to a character array to copy our member array to.
*/
{
    strcpy_s(name, 65, m_sName);
}

void Character::getClass(int &cl)
/*
A function that takes a class parameter, and copies it to a character class.

    Parameters
    ----------
    cl: INT
        An integer representing a 'class' archetype.
*/
{
    cl = m_iClass;
}

void Character::getAlignment(int &al)
/*
A function that takes an alignment parameter, and copies it to a character alignment.

    Parameters
    ----------
    al: INT
        An integer representing a 'alignment' archetype.
*/
{
    al = m_iAlignment;
}

void Character::getHitPoints(int &hp)
/*
A function that takes a hit point parameter, and copies it to a character hit point value.

    Parameters
    ----------
    hp: INT
        An integer representing a hit point value.
*/
{
    hp = m_iHitPoints;
}

void Character::getStrength(int *str)
/*
A function that takes a strength parameter, and copies it to the strength value index.

    Parameters
    ----------
    str: INT
        An integer representing a strength value.
*/
{
    *str = m_iCharTraits[0];
}

void Character::getDexterity(int *dex)
/*
A function that takes a dexterity parameter, and copies it to the dexterity value index.

    Parameters
    ----------
    dex: INT
        An integer representing a dexterity value.
*/
{
    *dex = m_iCharTraits[1];
}

void Character::getConstitution(int *cn)
/*
A function that takes a constitution parameter, and copies it to the constitution value index.

    Parameters
    ----------
    cn: INT
        An integer representing a constitution value.
*/
{
    *cn = m_iCharTraits[2];
}

void Character::getIntelligence(int *itl)
/*
A function that takes an intelligence parameter, and copies it to the intelligence value index.

    Parameters
    ----------
    itl: INT
        An integer representing an intelligence value.
*/
{
    *itl = m_iCharTraits[3];
}

void Character::getWisdom(int *wis)
/*
A function that takes a wisdom parameter, and copies it to the wisdom value index.

    Parameters
    ----------
    wis: INT
        An integer representing a wisdom value.
*/
{
    *wis = m_iCharTraits[4];
}

void Character::getCharisma(int *chr)
/*
A function that takes a charisma parameter, and copies it to the charisma value index.

    Parameters
    ----------
    chr: INT
        An integer representing a charisma value.
*/
{
    *chr = m_iCharTraits[5];
}

// ** Character Destructor ** //

Character::~Character()
// Destructor - Does nothing //
{
}

// ** Character Functions ** //

void Character::printAll()
/*
A function that prints all character data members to console.
*/
{
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
}