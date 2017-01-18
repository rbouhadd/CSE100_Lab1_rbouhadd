/**
 * Names: Stephanie Chen, Ramsey Bouhaddou
 * Date: January 17, 2017
 * Overview: BSTNode.hpp creates a basic binary search tree node. 
 * Assignment #1 
 */


#ifndef BSTNODE_HPP
#define BSTNODE_HPP
#include <iostream>
#include <iomanip>

/** Starter code for PA1, CSE 100 2016
 * Authors: Christine Alvarado, based on code by Paul Kube 
 * Ramsey Bouhaddou, Stephanie Chen
 */

template<typename Data>
class BSTNode {

public:

  BSTNode<Data>* left = NULL;
  BSTNode<Data>* right = NULL;
  BSTNode<Data>* parent = NULL;
  Data const data;   // the const Data in this node.

  /** Constructor.  Initialize a BSTNode with the given Data item,
   *  no parent, and no children.
   */
  BSTNode(const Data & d);


  /** Return the successor of this BSTNode in a BST, or 0 if none.
   ** PRECONDITION: this BSTNode is a node in a BST.
   ** POSTCONDITION:  the BST is unchanged.
   ** RETURNS: the BSTNode that is the successor of this BSTNode,
   ** or 0 if there is none.
   */ 
  BSTNode<Data>* successor(); 

}; 


// Function definitions
// For a templated class it's easiest to just put them in the same file as the class declaration

template <typename Data>
BSTNode<Data>::BSTNode(const Data & d) : data(d), left(0), right(0), parent(0) {}

/* Return a pointer to the BSTNode that contains the item that is sequentially next 
 * in the tree */
template <typename Data>
BSTNode<Data>* BSTNode<Data>::successor()
{
	BSTNode<Data>* curr = right;

	// if the node we're trying to find a successor for has a right child 
	if(right) {
		while(curr->left) {
			curr = curr->left; 
		}
		return curr;
	}

	if(!right){
		if(curr->data < curr->parent->data) {
			return parent;
		}
		if(curr->parent->data < curr->data) {
			return curr->parent->parent;
		}
	}

	return 0;
}

/** Overload operator<< to print a BSTNode's fields to an ostream. */
template <typename Data>
std::ostream & operator<<(std::ostream& stm, const BSTNode<Data> & n) {
  stm << '[';
  stm << std::setw(10) << &n;                 // address of the BSTNode
  stm << "; p:" << std::setw(10) << n.parent; // address of its parent
  stm << "; l:" << std::setw(10) << n.left;   // address of its left child
  stm << "; r:" << std::setw(10) << n.right;  // address of its right child
  stm << "; d:" << n.data;                    // its data field
  stm << ']';
  return stm;
}

#endif // BSTNODE_HPP
