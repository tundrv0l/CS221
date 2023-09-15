// Character.cpp -- CS221 -- Fall '23 -- Project 03//

#include <iostream>
#include <string>
#include <cstring> // Might remove, not sure how he wants this done
#include "Character.h"

using namespace std;

// ** Character Constructors ** //

Character::Character()
// Default Constructor - Sets every private member of 'Character' to their unknown value (0 for ints) //
{
    strcpy_s(m_sName, "Unknown"); // Might remove, not sure how he wants this done
    m_iClass = 0;
    m_iAlignment = 0;
    m_iHitPoints = 0;
    for (int i = 0; i < 6; i++)
    {
        m_iCharTraits[i] = 0;
    }
}

//Might change this array population as well
Character::Character(char *name, int cl, int al, int hp, int str, int dex, int con, int itl, int wis, int chr) 
: m_iCharTraits{ str, dex, con, itl, wis, chr }
// Parameterized Constructor - Sets every private member for 'Character' to their parameterized value //
{
    strcpy_s(m_sName, name); // Might remove, not sure how he wants this done
    m_iClass = cl;
    m_iAlignment = al;
    m_iHitPoints = hp;
}