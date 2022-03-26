#include <iostream>
#include "doubly.h"

int main(){
	Doubly *Queue = Doubly::createDoubly();
	int i, n;
	cout << "Please enter the length of the queue : " << endl;
	cin >> n;
	cout << "Please insert data into the queue : " << endl;
	for(i = 0; i < n; i++)
		cin >> *Queue;
	cout << "\nThe size of the queue : " << (*Queue).size() << endl;
	cout << "The queue that entered : " << endl;
	(*Queue).print();
	cout << "\nDequeuing the queue : " << endl;
	for(i = 0; i < n; i++){
		cout << "#" << i+1 << " dequeue : " << *Queue << endl;
	}
	cout << "\nDequequing one more time : " << *Queue << endl;
	return 0;
}
