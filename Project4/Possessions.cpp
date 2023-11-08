// Possessions.cpp -- CS221 -- Fall '23 -- Project 04//

#include "Possessions.h"
#include "Item.h"
#include <cstring>


// - Default Constructor - //
Possessions::Possessions()
{
    m_pRoot = nullptr;
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
    temp,back = nullptr; // Set temp and back to null, used for the search function
    return dropItemSearch(itemName, m_pRoot);
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
    cout << "The Item Type is: " << item->m_iType << endl;
    cout << "The Item Value is: " << item->m_dValue << endl;
    cout << "The Item Weight is: " << item->m_dWeight << endl;
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

Item* Possessions::dropItemSearch(char *itemName, Item *&rt)
/*
This function takes an item name and a root of a binary tree and searches/removes the item from the tree. 

    Parameters
    ----------
    *itemName: CHAR
        A pointer to an item name to remove from the character's inventory.
    *&rt: Item
        A reference to a pointer to the root of the binary tree.

    Returns
    -------
    ITEM
        A pointer to the item that was removed from the inventory. NULL if the item was not found.
*/
{
    temp = rt;
    if (rt == nullptr) // Case 1: Empty Tree, or item not found
    {
        return nullptr;
    }
    if (strcmp(itemName, rt->m_sItemName) < 0) // Search the left subtree
    {
        back = temp; //Maintain back to keep track of the parent node
        return dropItemSearch(itemName, rt->m_pLeft);
    }
    else if (strcmp(itemName, rt->m_sItemName) > 0) // Search the right subtree
    {
        back = temp; //Maintain back to keep track of the parent node
        return dropItemSearch(itemName, rt->m_pRight);
    }
    else // Found the node we want to delete
    {
        if (temp->m_pLeft == nullptr)       // Case 2: No Left child
        {   
            if (back == nullptr) { // Case 2a: The node happens to be the root node
                m_pRoot = temp->m_pRight; // Set the root to the node's right child
            }
            else if (strcmp(back->m_sItemName, temp->m_sItemName) > 0) // Case 2b: The node is a left child
            {
                back->m_pLeft = temp->m_pRight; // Set the parent's left child to the node's right child
            }
            else
            {
                back->m_pRight = temp->m_pRight; // Case 2c: The node is a right child
            }
            return temp; // Deleted the node, return early. 
        }
        else if (temp->m_pRight == nullptr)     // Case 3: No Right child
        {
            if (back == nullptr) { // Case 3a: The node happens to be the root node
                m_pRoot = temp->m_pLeft;
            }
            else if (strcmp(back->m_sItemName, temp->m_sItemName) > 0) // Case 3b: The node is a left child
            {
                back->m_pLeft = temp->m_pLeft; // Set the parent's left child to the node's left child
            }
            else
            {
                back->m_pRight = temp->m_pLeft; // Case 3c: The node is a right child
            }
            return temp;
        }
        // Case 4: The Node has two children

        // Set up replacement ndoes for both the current node and parent of current. 
        Item *replacementParent = temp;
        Item *replacementNode = temp->m_pLeft;
        GetPredecessor(replacementNode, replacementParent); // Find the predecessor of the node to be deleted

        // Handle the case where the predecessor was the left child of the node to be deleted
        if (replacementParent->m_pRight == replacementNode) 
        {
            replacementParent->m_pRight = replacementNode->m_pLeft;
        }
        else 
        {
            replacementParent->m_pLeft = replacementNode->m_pLeft;
        }


        if (back == nullptr) // Case 4a: The node happens to be the root node
        {
            m_pRoot = replacementNode;
        }
        else if (strcmp(back->m_sItemName, temp->m_sItemName) > 0) // Case 4b: The node is a left child
        {
            back->m_pLeft = replacementNode;
        }
        else
        {
            back->m_pRight = replacementNode; // Case 4c: The node is a right child
        }

        // Handles preserving the children of the node to be deleted
        if (replacementNode != temp->m_pLeft)
        {
            replacementNode->m_pLeft = temp->m_pLeft;
        }
        replacementNode->m_pRight = temp->m_pRight;

        // Set the left and right children of the node to be deleted to null
        temp->m_pLeft = nullptr;
        temp->m_pRight = nullptr;

        return temp; // Deleted the node, return early.
    }
    return nullptr; // Item not found
}


void Possessions::GetPredecessor(Item* node, Item *parentNode)
/*
This function takes an two nodes, one node to find the predecessor of, and then that nodes parent. 

    Parameters
    ----------
    *node: CHAR
        A pointer to a node to find the predecessor of.
    *parentNode: Item
        Node's parent to maintain.

    Returns
    -------
    None
*/
{
    while (node->m_pRight != nullptr)   // this can be replaced with getPredecessor
        {
            parentNode = node;
            node = node->m_pRight;
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
