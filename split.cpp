/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */
void splitHelper(Node*& in, Node*& odds, Node*& evens, Node*& oddsCurrNode, Node*& evensCurrNode);

void split(Node*& in, Node*& odds, Node*& evens) {
  /* Add code here */
  // WRITE YOUR CODE HERE
  // By the end of the function, in should not be preserved aka set to nullptr
  // the other node pointers should point to the head of their respective lists
  // what we need to do is sort them 
  if (in == nullptr) {
    return;
  }
  // Check if the value is even or odd igggggg
  if (in->value % 2 == 0) {
    // even so we add into the even list
    evens->value = in->value;
    evens->next = nullptr;
    split(in->next, odds, evens->next);
  }
  else {
    odds->value = in->value;
    odds->next = nullptr;
    split(in->next, odds->next, evens);
  }
  in = nullptr;
  

}

/* If you needed a helper function, write it here */
void splitHelper(Node*& in, Node*& odds, Node*& evens, Node*& oddsCurrNode, Node*& evensCurrNode) {
  if (odds != nullptr) {
    oddsCurrNode = odds;
  }
}

// WRITE YOUR CODE HERE