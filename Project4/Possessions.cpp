// Possessions.cpp -- CS221 -- Fall '23 -- Project 04//

#include "Possessions.h"
#include "Item.h"
#include <cstring>


// - Default Constructor - //
Possessions::Possessions()
{
    m_pRoot = NULL;
    temp,back = NULL;
}

// - Mutator Functions - //

bool Possessions::addItem(Item *newItem)
/*
This function takes an item and adds it to the character's inventory binary tree. 

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
    return addItemHelp(newItem, m_pRoot);
}

Item *Possessions::dropItem(char *itemName)
/*
This function takes an item name and removes it from the character's inventory binary tree. 

    Parameters
    ----------
    *itemName: CHAR
        A pointer to an item name to remove from the character's inventory.

    Returns
    -------
    ITEM
        A pointer to the item that was removed from the inventory. 
*/
{
    // Case 1: Empty Tree
    if (m_pRoot == nullptr)
    {
        return nullptr;
    }
    else if (strcmp(itemName, m_pRoot->m_sItemName) < 0) // Check for a value less than the root to be removed in left subtree 
    {
        // Case 2: Node to be deleted is in left subtree
        m_pRoot = m_pRoot->m_pLeft; 
        dropItem(itemName);
    }
    else if (strcmp(itemName, m_pRoot->m_sItemName) > 0) // Check for a value greater than the root to be removed in right subtree
    {
        // Case 3: Node to be deleted is in right subtree
        m_pRoot = m_pRoot->m_pRight;
        dropItem(itemName);
    }
    // Found the item to be deleted
    else
    {
        if (dropItemHelp(itemName, m_pRoot))
        {
            return m_pRoot;
        }
        else
        {
            return nullptr;
        }
    }
    return nullptr; // Item was not found
}
// - Observer Functions - //

Item *Possessions::getItem(char *itemName)
/*
This function takes an item name and returns a pointer to the item in the character's inventory binary tree. 

    Parameters
    ----------
    *itemName: CHAR
        A pointer to an item name to search for in the character's inventory.

    Returns
    -------
    ITEM
        A pointer to the item that was found in the inventory. 
*/
{
    return getItemCheck(itemName, m_pRoot);
}



void Possessions::printOne(Item *item)
/*
This function takes an item structure and prints out the item's information.  

    Parameters
    ----------
    *item: Item
        A pointer to an item structure to print out.

    Returns
    -------
    Nothing
*/
{
    cout << item->m_sItemName << endl;
    cout << item->m_sDesc << endl;
    cout << item->m_iType << endl;
    cout << item->m_dValue << endl;
    cout << item->m_dWeight << endl;
}

void Possessions::printAll(Item *rt)
/*
This function prints out all of the items in given root's tree. 

    Parameters
    ----------
    *rt: Item
        A pointer to the root of the character's inventory binary tree.

    Returns
    -------
    Nothing
*/
{
    if (rt != nullptr)
    {
        // Inorder traversal
        printAll(rt->m_pLeft);
        printOne(rt);
        printAll(rt->m_pRight);
    }
}

void Possessions::printTree()
/*
This function prints out all of the items in the character's inventory binary tree. 

    Parameters
    ----------
    None

    Returns
    -------
    Nothing
*/
{
    printAll(m_pRoot);
}

void Possessions::destroyTree(Item *rt)
/*
This function takes an item structure and deletes all of the items in the character's inventory binary tree. 

    Parameters
    ----------
    *rt: Item
        A pointer to the root of the character's inventory binary tree.

    Returns
    -------
    Nothing
*/
{
    // Postorder traversal
    while(rt != nullptr)
    {
        destroyTree(rt->m_pLeft);
        destroyTree(rt->m_pRight);
        delete rt;
    }
}

// - Helper Functions - //
// - NOTE: These functions are private and are only used by the public functions. - //

Item *Possessions::getItemCheck(char *itemName, Item *rt)
/*
This private function takes an item name and a root, and returns a pointer to the item in the character's inventory binary tree. Helper used for getItem

    Parameters
    ----------
    *itemName: CHAR
        A pointer to an item name to search for in the character's inventory.
    *rt: Item
        A pointer to the root of the character's inventory binary tree.

    Returns
    -------
    ITEM
        A pointer to the item that was found in the inventory. 
*/
{
    if (rt == nullptr)
    {
        return nullptr;
    }
    else if (strcmp(itemName, rt->m_sItemName) < 0) // Check for a value less than the root to be in the left subtree 
    {
        return getItemCheck(itemName, rt->m_pLeft);
    }
    else if (strcmp(itemName, rt->m_sItemName) > 0) // Check for a value greater than the root to be in the right subtree
    {
        return getItemCheck(itemName, rt->m_pRight );
    }
    else
    {
        return rt; // Otherwise, the item was found on the current node
    }
}

bool Possessions::addItemHelp(Item *newItem, Item *&rt)
/*
This private function takes an item name and a root, and adds an item to the character's inventory binary tree.

    Parameters
    ----------
    *newItem: Item
        A pointer to the item to be added to the character's inventory.
    *&rt: Item
        A reference to the pointer to the root of the character's inventory binary tree.

    Returns
    -------
    BOOL
        True if the item was successfully added, false otherwise.
*/
{
    if (rt == nullptr) // Found the location to add the item
    {
        rt = newItem;
        rt->m_pLeft = nullptr;
        rt->m_pRight = nullptr;
        return true;
    }
    else if (strcmp(newItem->m_sItemName, rt->m_sItemName) < 0) // Check for a value less than the root to be in the left subtree 
    {
        return addItemHelp(newItem, rt->m_pLeft);
    }
    else if (strcmp(newItem->m_sItemName, rt->m_sItemName) > 0) // Check for a value greater than the root to be in the right subtree
    {
        return addItemHelp(newItem, rt->m_pRight);
    }
    else
    {
        return false; // Otherwise, we are unable to add the item
    }
}

bool Possessions::dropItemHelp(char *itemName, Item *&rt)
/*
This private function takes an item name and a root, and removes an item from the character's inventory binary tree.

    Parameters
    ----------
    *itemName: CHAR
        A pointer to an item name to remove from the character's inventory.
    *&rt: Item
        A reference to the pointer to the root of the character's inventory binary tree.

    Returns
    -------
    BOOL
        Will return true if the item was successfully removed, false otherwise.
*/
{
    temp = rt; // Set temp to the root passed in
    if (rt->m_pLeft == nullptr) 
    {
        rt = rt->m_pRight;
        delete temp;
        return true;
    } 
    else if (rt->m_pRight == nullptr)
    {
        rt = rt->m_pLeft;
        delete temp;
        return true;
    } 
    else 
    {
        while (rt->m_pRight != nullptr) 
        {
            rt = rt->m_pRight;
        }
        strcpy(itemName, rt->m_sItemName);
        rt = rt->m_pLeft;
        dropItem(itemName);
        return true;
    }
    return false;
}


// - Destructor - //

Possessions::~Possessions()
/*
This function deletes all of the items in the character's inventory binary tree. 
*/
{
    destroyTree(m_pRoot);
}
