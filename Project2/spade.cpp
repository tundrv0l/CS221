// Spade.cpp -- CS221 -- Fall '23 -- Project 02//

#include "spade.h"


Spade::Spade(int v) : BlackCard(v)
// Parameterized Constructor: Initializes value to the passed in arguement, color to "Black", and suit to 'S'
{
  SetSuit('S'); // SetSuit to "S", where the intended value and color variables are inherited from Card and BlackCard
}

string Spade::Description() const
{
  string d;
  d = BlackCard::Description(); // Call Card's Description function to get the value of the card
  d = d + " of suit: " + BlackCard::GetSuit();  // Append color variable's to value
  return d;
}