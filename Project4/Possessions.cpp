// Possessions.cpp -- CS221 -- Fall '23 -- Project 04//

#include "Possessions.h"
#include "Item.h"


// - Default Constructor - //
Possessions::Possessions()
{
    m_pRoot = NULL;
    temp,back = NULL;
}

// - Mutator Functions - //

bool Possessions::addItem(Item *newItem)
/*
A function that takes an item parameter, and adds it to the binary tree of items.

    Parameters
    ----------
    *item: ITEM
        A pointer to an item to add to the character's inventory.

    Returns
    -------
    BOOL
        A boolean value representing whether or not the item was added to the inventory. TRUE if added, FALSE if not.
*/

