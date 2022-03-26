#include "doubly.h"

// Node class functions //
Node::Node() : val(0), prev(NULL), next(NULL)
	{	}
Node::Node(ndata x) : val(x), prev(NULL), next(NULL)
	{	}
Node::Node(const Node &node){
	val = node.val;
	prev = node.prev;
	next = node.next;
}
Node::~Node()
	{	}
Node &Node::operator=(const Node &node){
	val = node.val;
	prev = node.prev;
	next = node.next;
	return *this;
}
Node * Node::createNode()
	{ return new Node; }
Node * Node::createNode(ndata x)
	{ return new Node(x); }
Node &Node::setVal(ndata x) // Enables cascading
	{ val = x; return *this; }
Node &Node::setNext(Node *ptr)
	{ next = ptr; return *this; }
Node &Node::setPrev(Node *ptr)
	{ prev = ptr; return *this; }
ndata Node::getVal() const
	{ return val; }
Node *Node::getNext() const
	{ return next; }
Node *Node::getPrev() const
	{ return prev; }
//---------------------//
// Doubly class functions //
Doubly::Doubly() : head(NULL), tail(NULL)
	{	}
Doubly::~Doubly()
	{	}
Doubly &Doubly::operator=(const Doubly &doubly){
	head = doubly.head;
	tail = doubly.tail;
	return *this;
}
Doubly * Doubly::createDoubly()
	{ return new Doubly; }
void Doubly::enqueue(Node& node){
	if ((*this).isEmpty()){
		head = tail = &node;
		node.setNext(NULL).setPrev(NULL);
		return;
	}
	head->setPrev(&node);
	node.setNext(head).setPrev(NULL);
	head = &node;
}
void Doubly::enqueue(ndata x)
	{ enqueue(*Node::createNode(x)); }
Node *Doubly::front() const
		{ return head; }
Node *Doubly::dequeue(){
	if ((*this).isEmpty())
		return NULL;
	Node *node = tail;
	tail = tail->getPrev();
	if (!tail){
		head = NULL;
	}
	else
		tail->setNext(NULL);
	node->setPrev(NULL);
	return node;
}
int Doubly::isEmpty() const
	{ return !(head || tail); }
int Doubly::size() const{
	int cnt;
	Node *tmp = head;
	for (cnt = 0; tmp; cnt++)
		tmp = tmp->getNext();
	return cnt;
}
void Doubly::print() const{
	cout << "head->";
	Node *tmp = head;
	while (tmp){
		cout << tmp->getVal() << "->";
		tmp = tmp->getNext();
	}
	cout << "tail\n";
}
istream &operator>>(istream& input, Doubly& list){
	ndata x;
	input >> x;
	list.enqueue(x);
	return input;
}
ostream &operator<<(ostream& output, Doubly& list){
	Node *tmp = list.dequeue();
	if(!tmp){
		output << "\nList is empty!\n";
		return output;
	}
	output << tmp->getVal();
	free(tmp);
	tmp = NULL;
	return output;
}
//---------------------//
