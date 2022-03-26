#ifndef DOUBLY_H_
#define DOUBLY_H_

#include <iostream>

using namespace std;
typedef int ndata;

class Node{
private:
	ndata val;
	Node * prev, * next;
public:
	// Gentlemanly set //
	Node();
	Node(ndata);
	Node(const Node &); // Copy constructor '='
	~Node();
	Node &operator=(const Node &);
	//-----------------//
	// Sets / gets functions //
	Node &setVal(ndata);
	Node &setNext(Node *);
	Node &setPrev(Node *);
	ndata getVal() const;
	Node *getNext() const;
	Node *getPrev() const;
	//-----------------------//
	// Queue-relevant functions //
	Node * createNode();
	static Node * createNode(ndata); // Overloading with one argument
};

class Doubly{
private:
	Node * head, * tail;
public:
	// Gentlemanly set //
	Doubly();
	~Doubly();
	Doubly &operator=(const Doubly &);
	//-----------------//
	// Queue-relevant functions //
	static Doubly * createDoubly();
	void enqueue(Node&);
	void enqueue(ndata);
	Node *front() const;
	Node *dequeue();
	int isEmpty() const;
	// O(n)'s informative functions
	int size() const;
	void print() const;
	// Elegant input / output,
	// equivalent to enqueue / dequeue functions
	friend istream &operator>>(istream&, Doubly&);
	friend ostream &operator<<(ostream&, Doubly&);
	//--------------------------//
};

#endif
