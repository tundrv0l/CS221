//------------------------------------------------------------------
// Possessions.h
//
// Header file for a player possession object for programming 
//   assignment 3.
//------------------------------------------------------------------
#ifndef POSSESSIONS_H
#define POSSESSIONS_H
#include <iostream>
#include "Item.h"
using namespace std;

class Possessions
{
	private:
		Item	*m_pRoot;
		Item    *temp, *back;  // Used by generic search

	public:
		Possessions();						// Class constructor
		~Possessions();						// Class destructor
		bool addItem(Item *newItem);		// Add an item to this list
		Item *dropItem(char *itemName);	// Delete an item from this list
		Item *getItem(char *itemName);		// Return a pointer to an item
		void printTree();					// Print list of all items in tree

	private:
		void printOne(Item *item);			// Print a single item.
		void destroyTree(Item *rt);			// Recursively destroy the tree
		void printAll(Item *rt);			// Recursively print all items in tree
		Item *search(char *itemName);       // Generic search function
		// Helper function for getItem //
		Item *getItemCheck(char *itemName, Item *rt); // Recursive search function
		// Helper function for addItem //
		bool addItemHelp(Item *newItem, Item *&rt); // Recursive function for addItem
		// Helper function for dropItem //
		Item* dropItemSearch(char *itemName, Item *&rt); // Recursive function for dropItem
		// Helper function for Predecessor //
		void GetPredecessor(Item* node, Item *parentNode); // Recursive function for Predecessor
};
#endif