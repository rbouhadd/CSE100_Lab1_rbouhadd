/**
 * Names: Stephanie Chen, Ramsey Bouhaddou
 * Date: January 17, 2017
 * Overview: testBST.hpp tests the creation of a basic binary search tree. 
 * Assignment #1 
 */


#include "BSTInt.h"
#include "BST.hpp"
#include "BSTIterator.hpp"

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

/**
 * A test driver for the BST int class and class template.
 * PA1 CSE 100 2017
 * Author: Christine Alvarado and YOU
 **/
int main() {

	/* Create an STL vector of some ints */
	/*test*/
	/*
		 vector<int> v0; // Empty tree
		 vector<int> v1; // One node tree
		 vector<int> v5; // Five node tree

		 v1.push_back(4); 

		 v5.push_back(3);
		 v5.push_back(4);
		 v5.push_back(1);
		 v5.push_back(100);
		 v5.push_back(-33);
		 v5.push_back(0);

	// Create an instance of BST holding int 
	BSTInt b0;
	BSTInt b1;
	BSTInt b5;

	// BSTInt is the tree. The tree creates a root node BSTNodeInt. 

	// Could use: for(auto item : v) { instead of the line below
	// Empty tree should have size 0
	if (v0.size() != 0) {
	cout << "Empty tree's size is wrong. It is " << v0.size() << endl;  
	return -1; 
	}

	// One node tree
	if (v1.size()) {
	for(int item : v1) {

	bool pr = b1.insert(item);
	if(! pr ) {
	cout << "Incorrect bool return value when inserting " << item 
	<< endl;
	return -1; 
	}
	}
	}

	// Five node tree
	if (v5.size()) {
	for(int item : v5) {

	bool pr = b5.insert(item);
	if(! pr ) {
	cout << "Incorrect bool return value when inserting " << item 
	<< endl;
	return -1; 
	}
	}
	}

	// Test size of empty tree
	cout << "Size is: " << b0.size() << endl;
	if(b0.size() != v0.size()) {
	cout << "... which is incorrect." << endl;
	return -1; 
	}

	// Test size of one node tree
	cout << "Size is: " << b1.size() << endl;
	if(b1.size() != v1.size()) {
	cout << "... which is incorrect." << endl;
	return -1; 
	}
	// Test size of six node tree 
	cout << "Size is: " << b5.size() << endl;
	if(b5.size() != v5.size()) {
	cout << "... which is incorrect." << endl;
	return -1; 
}

// Test find return value. 
// Test the items that are already in the tree
for(int item : v0) {
	if(!b0.find(item)) {
		cout << "Incorrect return value when finding " << item << endl;
		return -1; 
	}
}

for(int item : v1) {
	if(!b1.find(item)) {
		cout << "Incorrect return value when finding " << item << endl;
		return -1; 
	}
}

for(int item : v5) {
	if(!b5.find(item)) {
		cout << "Incorrect return value when finding " << item << endl;
		return -1; 
	}
}

// Test empty() function. True if BST empty. False otherwise.
if ( b0.empty() != true ) {
	cout << "Incorrect return value for empty BST" << endl; 
	return -1; 
}

if ( b1.empty() != false ) {
	cout << "Incorrect return value for one-node BST" << endl; 
	return -1; 
}

if ( b5.empty() != false ) {
	cout << "Incorrect return value for six-node BST" << endl; 
	return -1; 
}


// Test heights
if ( b0.height() != -1 ) {
	cout << "Incorrect height for empty BST" << endl;
	return -1; 
}

if ( b1.height() != 0 ) {
	cout << "Incorrect height for one-node BST. Height is " << b1.height() << endl;
	return -1; 
}

if ( b5.height() != 3 ) {
	cout << "Incorrect height for six-node BST. Height is " << b5.height() << endl;
	return -1; 
}

*/

/* UNCOMMENT THE LINES BELOW TO TEST THE TEMPLATE-BASED ITERATOR */



// Test the template version of the BST with ints 
BST<int> bst0;
BST<int> bst1;
BST<int> bst7;

vector<int> vec0;// 0 Nodes
vector<int> vec1;// 1 Node
vector<int> vec7; // 7 nodes

vec1.push_back(12);

vec7.push_back(10);
vec7.push_back(6);
vec7.push_back(5);
vec7.push_back(15);
vec7.push_back(9);
vec7.push_back(8);
vec7.push_back(7);

//Inserting into the BST
//vec1
for (int item : vec1) {
	// The auto type here is the pair of BSTIterator<int>, bool
	cout << "Inserting " << item << " into the int template-based BST...";
	auto p = bst1.insert(item);
	// p.first is the iterator
	if (*(p.first) != item) {
		cout << "Wrong iterator returned.  "
			<< "Expected " << item << " but got " << *(p.first) << endl;
		return -1;
	}
	
	// p.second is the bool 
	if (!p.second) {
		cout << "Wrong boolean returned.  Expected true but got " 
			<< p.second << endl;
		return -1;
	}
	cout << "success!" << endl;

}
//vec7
for (int item : vec7) {
	// The auto type here is the pair of BSTIterator<int>, bool
	cout << "Inserting " << item << " into the int template-based BST...";
	auto p = bst7.insert(item);
	// p.first is the iterator
	if (*(p.first) != item) {
		cout << "Wrong iterator returned.  "
			<< "Expected " << item << " but got " << *(p.first) << endl;
		return -1;
	}
	
	// p.second is the bool 
	if (!p.second) {
		cout << "Wrong boolean returned.  Expected true but got " 
			<< p.second << endl;
		return -1;
	}
	cout << "success!" << endl;

}

// Now test finding the elements we just put in
for (int item: vec7) {
	cout << "Finding " << item << "...." << endl;
	BSTIterator<int> foundIt = bst7.find(item);
	if (*(foundIt) != item) {
		cout << "incorrect value returned.  Expected iterator pointing to "
			<< item << " but found iterator pointing to " << *(foundIt) 
			<< endl;
		return -1;
	}
	cout << "success!" << endl;
}



// Test the iterator: The iterator should give an in-order traversal

// Sort the vector, to compare with inorder iteration on the BST
sort(vec7.begin(),vec7.end());

cout << "traversal using iterator..." << endl;
auto vit = vec7.begin(); // returns an iterator pointing to v[0]
auto ven = vec7.end(); // returns an iterator pointing to the v[length] past-the-end elmt 

// This is equivalent to BSTIterator<int> en = bst7.end();
auto en = bst7.end();

// This is equivalent to BST<int>::iterator it = bst7.begin();
auto it = bst7.begin(); // begin() eventually returns a ptr to the smallest elmt in the tree 
for(; vit != ven; ++vit) {
	if(! (it != en) ) { // we overwrode !=, so this is checking if it and en point to the same node
		cout << *it << "," << *vit 
			<< ": Early termination of BST iteration." << endl;
		return -1;

	}
	cout << *it << endl;
	if(*it != *vit) {
		cout << *it << "," << *vit 
			<< ": Incorrect inorder iteration of BST." << endl;
		return -1;
	}
	++it;
}

cout << "success!" << endl;



cout << "We were able to run through all tests w/o crashing" << endl;
return 0;
}

//Test empty
if(bst7.empty())==true) return -1;
if(vec0.size() != 0) return -1;//TODO



//Test size
if(vec0.size() != 0){
	return -1;
}



//Test height














