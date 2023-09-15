// diamond.cpp -- CS221 -- Fall '23 -- Project 02//

#include "diamond.h"

Diamond::Diamond(int v) : RedCard(v)
// Parameterized Constructor: Initializes value to the passed in arguement, color to "Red", and suit to 'D'
{
  SetSuit('D'); // SetSuit to "D", where the intended value and color variables are inherited from Card and RedCard
}

string Diamond::Description() const
{
  string d;
  d = RedCard::Description(); // Call Card's Description function to get the value of the card
  d = d + " of suit: " + RedCard::GetSuit();  // Append color variable's to value
  return d;
}