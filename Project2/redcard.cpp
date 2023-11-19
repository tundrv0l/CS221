// redcard.cpp -- CS221 -- Fall '23 -- Project 02//


#include "redcard.h"

RedCard::RedCard(int v) : Card(v)
// Parameterized Constructor: Initializes value to 0, color to "Red", and suit to 'U'
{
  SetColor("Red"); // SetColor to "Red", where the intended value and suit variables are inherited from Card
}

string RedCard::Description() const
{
  string d;
  d = Card::Description(); // Call Card's Description function to get the value of the card
  d = d + " of color: " + Card::GetColor();  // Append color variable's to value
  return d;    
}