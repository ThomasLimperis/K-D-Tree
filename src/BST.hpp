//
// BST.hpp
// CSE 100 Project 1
//
// Last modified by Heitor Schueroff on 01/10/2019
//

#ifndef BST_HPP
#define BST_HPP

#include <iostream>

#include "BSTIterator.hpp"
#include "BSTNode.hpp"

using namespace std;

template <typename Data>
class BST {
protected:
    // Pointer to the root of this BST, or 0 if the BST is empty.
    BSTNode<Data> *root;

    // Number of elements stored in this BST.
    unsigned int isize;

    // Height of this BST.
    unsigned int iheight;

public:
    // Define iterator as an aliased typename for BSTIterator<Data>.
    typedef BSTIterator<Data> iterator;

    /** 
     * Default constructor. Initializes an empty BST.
     */
    BST() : root(0), isize(0), iheight(0) {}

    /** 
     * Default destructor. Frees all memory allocated by this BST.
     */
    // TODO
    virtual ~BST()
    {
    	isize = 0;
    	iheight = 0;
    	deleteAll(root);
    }

    /** 
     * Inserts the given item into this BST.
     *
     * This function should use only the '<' operator when comparing
     * Data items. (do not use ==, >, <=, >=). For the reasoning
     * behind this, see the assignment writeup.
     *
     * Parameters:
     *     item Data item to insert into this BST
     *
     * Returns:
     *     true if the item was inserted as a consequence of calling
     *     this function, false otherwise (e.g. item is a duplicate).
     */
    // TODO
    virtual bool insert(const Data &item)
    {



    BSTNode<Data> *current;
    unsigned int maxLevel = 1;
    if (root  == nullptr)
    {
    	root = new BSTNode<Data>(item);
    	root->parent = 0;
    	isize++;
    	iheight = 1;
    	return true;
    }
    else
    {
    	current = root;
    	while (current != nullptr)
    	{
    		if (current->data < item)
    			if (current->right != nullptr)
    			{
    				current = current->right;
    				maxLevel++;
    			}
    			else
    			{
    				current->right = new BSTNode<Data>(item);
    				current->right->parent = current;
    				isize++;
    				maxLevel++;
    				if (maxLevel > iheight)
    					iheight = maxLevel;
    				return true;
    			}
    		else if (item < current->data)
    			if (current->left != nullptr)
    			{
    				current = current->left;
    				maxLevel++;
    			}
    			else
    			{
    				current->left = new BSTNode<Data>(item);
    				current->left->parent = current;
    				isize++;
    				maxLevel++;
    				if (maxLevel > iheight)
    					iheight = maxLevel;
    				return true;
    			}
    		else
    			return false; //item already exists
    	}
    }
    return true;
    }
    /**
     * Searches for the given item in this BST.
     *
     * This function should use only the '<' operator when comparing
     * Data items. (should not use ==, >, <=, >=). For the reasoning
     *behind this, see the assignment writeup.
     *
     * Parameters:
     *     item Data item to search for in this BST.
     *
     * Returns:
     *     An iterator pointing to the item if found, or pointing
     *     past the last node in this BST if item is not found.
     */
    // TODO
    virtual iterator find(const Data &item) const
    {
    	BSTNode<Data> *temp = root;
    	while (temp != nullptr)
    	{
    		if (temp -> data < item)
    			temp = temp-> right;
    		else if (item < temp->data)
    			temp = temp->left;
    		else
    		{
    			return iterator(temp);
    		}
    	}
    	return iterator(temp);
    }

    /** 
     * Returns the number of items currently in the BST.
     */
    // TODO
    unsigned int size() const {

    	return isize;
    }

    /** 
     * Returns the height of this BST.
     */
    // TODO
    unsigned int height() const
    {
    	return iheight;
    }

    /** 
     * Returns true if this BST is empty, false otherwise.
     */
    // TODO
    bool empty() const {
    	if (isize == 0)
    		return true;
    	else
    		return false;
    }

    /** 
     * Returns an iterator pointing to the first item in the BST (not the root).
     */
    // TODO
    iterator begin() const {

    	if (root == nullptr)
    		return iterator(root);
    	BSTNode<Data> *temp = root;
    	while (temp->left != nullptr)
    		temp = temp->left;
    	return iterator(temp);

    }

    /** 
     * Returns an iterator pointing past the last item in the BST.
     */
    iterator end() const { 
        return typename BST<Data>::iterator(0); 
    }

    /** 
     * Prints the elements in this BST in ascending order.
     */
    void inorder() const { 
        inorder(root); 
    }

private:
    /*
     * Find the first node in the given subtree with root curr.
     */
    static BSTNode<Data>* first(BSTNode<Data> *curr) {
        if (!curr) return 0;
        while (curr->left) {
            curr = curr->left;
        }
        return curr;
    }

    /* 
     * Do an inorder traversal, printing the data in ascending order.
     *
     * You can achieve an inorder traversal recursively by following 
     * the order below.
     *
     *     recurse left - print node data - recurse right
     */
    // TODO
    static void inorder(BSTNode<Data> *n)
    {
    	if (n == nullptr)
    		return;
    	if (n->left != nullptr )
        	{
        		inorder(n->left);
        	}
        	cout << n->data <<endl;
        	if (n->right != nullptr)
        	{
        		inorder(n->right);
        	}
        	return;
    }

    /* 
     * Do a postorder traversal, deleting nodes.
     *
     * You can achieve a postorder traversal recursively by following 
     * the order below.
     *
     *     recurse left - recurse right - delete node
     */
    // TODO
    static void deleteAll(BSTNode<Data> *n)
    {
    		if (n == nullptr)
    			return;
    		deleteAll(n->left);
    		deleteAll(n->right);
    		delete n;
    		return;

    }
};

#endif  // BST_HPP
