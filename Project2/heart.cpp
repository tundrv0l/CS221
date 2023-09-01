// heart.cpp -- CS221 -- Fall '23 -- Project 02//

#include <iostream>
#include "heart.h"

Heart::Heart(int v) : RedCard(v)
// Parameterized Constructor: Initializes value to the passed in arguement, color to "Red", and suit to 'D'
{
  SetValue(v);
  SetColor("Red");
  SetSuit('H');
}

string Heart::Description() const
{
    string d = "Value = ";    // temporary variable used to accumulate result

    switch (GetValue())            // Append card value to variable's value
    {
        case 2:   d = d + "2";    break;      // Number cards
        case 3:   d = d + "3";    break;
        case 4:   d = d + "4";    break;
        case 5:   d = d + "5";    break;
        case 6:   d = d + "6";    break;
        case 7:   d = d + "7";    break;
        case 8:   d = d + "8";    break;
        case 9:   d = d + "9";    break;
        case 10:  d = d + "10";   break;

        case 11:  d = d + "J";    break;      // Face cards
        case 12:  d = d + "Q";    break;
        case 13:  d = d + "K";    break;
        case 14:  d = d + "A";    break;

        default:  d = d + "?";    break;      // Unknown card
    }
  
    d = d + " of color: " + GetColor() + " and suit: " + GetSuit();  // Append color and suit variables to description
    return d;  // Return string describing card value

}