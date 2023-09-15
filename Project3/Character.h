// Character.h -- CS221 -- Fall '23 -- Project 03//

#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character
{
private:
    // ** Character Data Members ** //
    char m_sName[65]; // Character name (up to 64 characters, +1 to account for null terminator)
    int m_iClass; // Character class
    int m_iAlignment; // Character alignment
    int m_iHitPoints; // Character hit points
    int m_iCharTraits[6]; // Character traits (By index: STR[0], DEX[1], CON[2], INT[3], WIS[4], CHA[5])

public:
    // ** Character Constructors ** //
    Character(); // Default constructor

    Character(char *name, int cl, int al, int hp, int str, int dex, int con, int itl, int wis, int chr); // Parameterized constructor

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




    // ** Character Observers ** //

    // ** Character Destructor ** //
    ~Character(); // Destructor

} 








#endif