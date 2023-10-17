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
    // Case 1: Empty Tree
    if (m_pRoot == nullptr)
    {
        m_pRoot = newItem;
        m_pRoot->m_pLeft = nullptr;
        m_pRoot->m_pRight = nullptr;
        return true;
    }
    else
    {
        Item* currentNode = m_pRoot;
        while (currentNode != nullptr)
        {
            if (strcmp(newItem->m_sItemName, currentNode->m_sItemName) < 0) // Check for a value less than the current node to be placed in left subtree 
            {
                // Case 2: Left subtree
                if (currentNode->m_pLeft == nullptr) // Subcase: Left node is a leaf
                {
                    currentNode->m_pLeft = newItem;
                    currentNode->m_pLeft->m_pLeft = nullptr;
                    currentNode->m_pLeft->m_pRight = nullptr;
                    return true;
                }
                else
                {
                    currentNode = currentNode->m_pLeft; // Subcase: Left node is in the middle of the tree
                }
            }
            else if (strcmp(newItem->m_sItemName, currentNode->m_sItemName) > 0) // Check for a value greater than the current node to be placed in right subtree
            {
                // Case 3: Right Subtree
                if (currentNode->m_pRight == nullptr) // Subcase: Right node is a leaf
                {
                    currentNode->m_pRight = newItem;
                    currentNode->m_pRight->m_pLeft = nullptr;
                    currentNode->m_pRight->m_pRight = nullptr;
                    return true;
                }
                else
                {
                    currentNode = currentNode->m_pRight; // Subcase: Right node is in the middle of the tree
                }
            }
            else
            {
                return false; // Unable to add item
            }
        }
    }
    return false; // Unable to add item
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
        return dropItem(itemName);
    }
    else if (strcmp(itemName, m_pRoot->m_sItemName) > 0) // Check for a value greater than the root to be removed in right subtree
    {
        // Case 3: Node to be deleted is in right subtree
        m_pRoot = m_pRoot->m_pRight;
        return dropItem(itemName);
    }
    // Found the item to be deleted
    else
    {
        // Case 4: Node to be deleted is a leaf
        if (m_pRoot->m_pLeft == nullptr && m_pRoot->m_pRight == nullptr)
        {
            Item *temp = m_pRoot;
            m_pRoot = nullptr;
            return temp;
        }
        // Case 5: Node to be deleted has one child
        else if (m_pRoot->m_pLeft == nullptr)
        {
            Item *temp = m_pRoot;
            m_pRoot = m_pRoot->m_pRight;
            return temp;
        }
        else if (m_pRoot->m_pRight == nullptr)
        {
            Item *temp = m_pRoot;
            m_pRoot = m_pRoot->m_pLeft;
            return temp;
        }
        // Case 6: Node to be deleted has two children
        else
        {
            Item *temp = m_pRoot;
            m_pRoot = m_pRoot->m_pRight;
            while (m_pRoot->m_pLeft != nullptr)
            {
                m_pRoot = m_pRoot->m_pLeft;
            }
            return temp;
        }
    }
    
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

Item *Possessions::getItemCheck(char *itemName, Item *rt)
/*
This function takes an item name and a root, and returns a pointer to the item in the character's inventory binary tree. Helper used for getItem

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


// - Destructor - //

Possessions::~Possessions()
/*
This function deletes all of the items in the character's inventory binary tree. 
*/
{
    destroyTree(m_pRoot);
}
