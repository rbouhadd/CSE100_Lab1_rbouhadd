#include <iostream>
#include "BSTInt.h"
using namespace std;

/* Function definitions for a int-based BST class */


/** Default destructor.
 *  Delete every node in this BST.
 */
BSTInt::~BSTInt() {
	if (root) {
		deleteAll(root);
	}
}

/** Given a reference to a Data item, insert a copy of it in this BST.
 *  Return  true if the item was added to this BST
 *  as a result of this call to insert,
 *  false if an item equal to this one was already in this BST.
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=)  For the reasoning
 *  behind this, see the assignment writeup.
 */

bool BSTInt::insert(int item)
{
	if (!root) {
		root = new BSTNodeInt(item);
		++isize;
		return true;
	}

	BSTNodeInt* curr = root;

	while (true) {
		if (item < curr->data) {
			if (curr->left == 0) {
				BSTNodeInt* newNode = new BSTNodeInt(item); 
				curr->left = newNode; 
				newNode->parent = curr;
				++isize; 
				return true; 
			}
			curr = curr->left; 
		}
		else if (curr->data < item) {
			if (curr->right == 0) {
				BSTNodeInt* newNode = new BSTNodeInt(item); 
				curr->right = newNode;
				newNode->parent = curr;
				++isize;
				return true;
			}
			curr = curr->right;
		}
		else {
			return false;
		}
	}

	/*

		 while (curr->left && curr->right) {
		 if (item < curr->data) {
		 curr = curr->left;
		 }
		 else if (curr->data < item) {
		 curr = curr->right;
		 }
		 else {
		 return false;
		 }
		 }

	// Ready to insert
	BSTNodeInt* newNode = new BSTNodeInt(item);
	if (item < curr->data) {
	curr->left = newNode;
	newNode->parent = curr;
	}
	else {
	curr->right = newNode;
	newNode->parent = curr;
	}

	++isize;
	return true;
	*/
}



/** Find a Data item in the BST.
 *  Return true if the item is in the BST or false otherwise
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=).  For the reasoning
 *  behind this, see the assignment writeup.
 */
bool BSTInt::find(int item) const
{

	if (empty()) {
		return false; 
	}

	BSTNodeInt* curr = root;
	while (curr) {
		if (curr->data < item) {
			curr = curr->right;
		}
		else if (item < curr->data) {
			curr = curr->left;
		}
		else {
			return true;
		}
	}
	return false;
}


/** Return the number of items currently in the BST.
*/
unsigned int BSTInt::size() const 
{
	return isize;
}


/** Return the height of the BST.
	Height of tree with just root node is 0
	*/
int BSTInt::height() const
{
	// Empty tree has height -1 
	if (isize == 0) {
		return -1; 
	}

	BSTNodeInt* curr = root;
	return (heightHelp(curr)-1);
}

/*
 * Method: heightHelp()
 * Parameters: BSTNodeInt* curr
 * Purpose: Helper function for finding height
 */
int BSTInt::heightHelp(BSTNodeInt* curr) const {

	int leftHeight = 0;
	int rightHeight = 0;

	if(curr->left){
		leftHeight = heightHelp(curr->left);
	}
	if(curr->right){
		rightHeight = heightHelp(curr->right);
	}

	if(leftHeight>rightHeight) return leftHeight + 1;
	else return rightHeight + 1;

}

/** Return true if the BST is empty, else false. 
*/
bool BSTInt::empty() const 
{
	if (isize == 0) {
		return true;
	}

	return false;
}

/** do a postorder traversal, deleting nodes
 * This is a helper for the destructor
 * This method is static because it acts on BSTNodeInts
 *   and not on the BSTInt object directly.
 */
void BSTInt::deleteAll(BSTNodeInt* n)
{
	if ( n->left ) {
		deleteAll( n->left );	
	}

	if ( n->right ) {
		deleteAll( n->right );
	}

	delete( n );
}
