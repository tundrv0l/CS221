// blackcard.cpp -- CS221 -- Fall '23 -- Project 02//


#include "blackcard.h"

BlackCard::BlackCard(int v) : Card(v)
// Parameterized Constructor: Initializes value to 0, color to "Black", and suit to 'U'
{ 
  SetColor("Black"); // SetColor to "Black", where the intended value and suit variables are inherited from Card
}

string BlackCard::Description() const
{
  string d;
  d = Card::Description(); // Call Card's Description function to get the value of the card
  d = d + " of color: " + Card::GetColor();  // Append color variable's to value
  return d;                          // Return string describing card value
}