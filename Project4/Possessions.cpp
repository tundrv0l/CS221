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
        A pointer to the item that was removed from the inventory. NULL if the item was not found.
*/
{
    if (m_pRoot == nullptr) // Check if the root node is null
    {
        return nullptr;
    }
    temp = nullptr;     // probably not needed
    back = nullptr;
    return dropItemSearch(itemName, m_pRoot);
}


Item* Possessions::dropItemSearch(char *itemName, Item *&rt)
/*
*/
{
    temp = rt;
    Item *removedItem = nullptr; // Create a pointer to the removed item
    if (rt == nullptr) // Check if the root node is null
    {
        return nullptr;
    }
    if (strcmp(itemName, rt->m_sItemName) < 0) // Check for a value less than the root to be in the left subtree 
    {
        back = temp;
        return dropItemSearch(itemName, rt->m_pLeft);
    }
    else if (strcmp(itemName, rt->m_sItemName) > 0) // Check for a value greater than the root to be in the right subtree
    {
        back = temp;
        return dropItemSearch(itemName, rt->m_pRight);
    }
    else // found node to delete
    {
        if (temp->m_pLeft == nullptr)       // if node has no left child
        {   
            if (back == nullptr) {
                m_pRoot = temp->m_pRight;
            }
            else if (strcmp(back->m_sItemName, temp->m_sItemName) > 0) // Back's left child
            {
                back->m_pLeft = temp->m_pRight;
            }
            else
            {
                back->m_pRight = temp->m_pRight;
            }
            return temp;
        }
        else if (temp->m_pRight == nullptr)     // if node has no right child
        {
            if (back == nullptr) {
                m_pRoot = temp->m_pLeft;
            }
            else if (strcmp(back->m_sItemName, temp->m_sItemName) > 0) // Back's left child
            {
                back->m_pLeft = temp->m_pLeft;
            }
            else
            {
                back->m_pRight = temp->m_pLeft;
            }
            return temp;
        }
        // If this line is reached, then temp has 2 children

        // find the node to replace temp, this will be the rightmost node on the left
        Item *replacementParent = temp;
        Item *replacementNode = temp->m_pLeft;
        while (replacementNode->m_pRight != nullptr)   // this can be replaced with getPredecessor
        {
            replacementParent = replacementNode;
            replacementNode = replacementNode->m_pRight;
        }

        // what if replacementNode has a left child?
        if (replacementParent->m_pRight == replacementNode) {
            replacementParent->m_pRight = replacementNode->m_pLeft;
        } else {
            replacementParent->m_pLeft = replacementNode->m_pLeft;
        }


        if (back == nullptr) {
                m_pRoot = replacementNode;
        }
        else if (strcmp(back->m_sItemName, temp->m_sItemName) > 0) // Back's left child
        {
            back->m_pLeft = replacementNode;
        }
        else
        {
            back->m_pRight = replacementNode;
        }

        if (replacementNode != temp->m_pLeft)   // this will ensure there is no self loop
        {
            replacementNode->m_pLeft = temp->m_pLeft;
        }
        replacementNode->m_pRight = temp->m_pRight;

        temp->m_pLeft = nullptr;
        temp->m_pRight = nullptr;

        return temp;

        // Tree results:
//                        4
//                      /   \
//                     2     6
//                    / \   / \
//                   1   3  5  7
    }
    
}

/* void Possessions::dropItemHelp(char *itemName, Item *&rt, Item *&removedItem)
/*
This function takes an item name and a root of a binary tree and removes the item from the tree. 

    Parameters
    ----------
    *itemName: CHAR
        A pointer to an item name to remove from the character's inventory.
    *&rt: Item
        A reference to a pointer to the root of the binary tree.
    *&removedItem: Item
        A reference to a pointer to the removed item.

    Returns
    -------
    None

{

    char * data = new char[50];
    
    removedItem = rt;
    temp = rt;
    if (rt->m_pLeft == nullptr) // Case 2: No Left Child
    {
        rt = rt->m_pRight;
        delete temp;
    }
    else if (rt->m_pRight == nullptr) // Case 3: No Right Child
    {
        rt = rt->m_pLeft;
        delete temp;
    }
    else // Case 4: Two Children
    {
        // Find the node with the maximum value in the left subtree
        GetPredecessor(data, rt->m_pLeft);
        strcpy_s(rt->m_sItemName, data);
        dropItemSearch(data, rt->m_pLeft);
    }

} */

void Possessions::GetPredecessor(char *&data, Item *rt)
/*
*/
{
    while (rt->m_pRight != nullptr)
    {
        rt = rt->m_pRight;
    }
    // Copy the rt data into the data pointer
    data = rt->m_sItemName;
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

/* bool Possessions::dropItemHelp(char *itemName, Item *&rt)
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
} */


// - Destructor - //

Possessions::~Possessions()
/*
This function deletes all of the items in the character's inventory binary tree. 
*/
{
    destroyTree(m_pRoot);
}
