
#include "DNode.hpp"
#include "DLL.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;


	DLL::DLL(){  // constructor - initializes an empty list
		last = NULL;
		first = NULL;
		numSongs = 0;
	}
	DLL::DLL(string t, string l, int m, int s){  // constructor, initializes a list with one new node with data x
		DNode *n = new DNode (t,l,m,s);
		first = n;
		last = n;
		numSongs=1;
	}

	void DLL::push(string t, string a, int m ,int s){
		DNode *n = new DNode(t,a,m,s);
		if(numSongs == 0){
			first = n;
		} else {
			n->prev = last;
			n->prev->next = n;
		}
		last = n;
		numSongs++;
	}

	Song *DLL::pop(){
		DNode *temp = last;
		Song *song = temp->song;
		last = last->prev;
		delete temp;
		last->next = NULL;
		numSongs--;
		return song;
	}

	void DLL::printList(){
		if (numSongs > 0){
			DNode *n = first;
			n->song->printSong();
			while(n->next != NULL){
				n = n->next;
				n->song->printSong();
			}
		}
	}

		int DLL::remove(string t){
			if(numSongs == 0){
				cout << "Failed: List is Empty" << endl;
				return -1;
			}
			if (last->song->title == t){
				cout << "Removing: ";
				pop()->printSong();
				return 0;
			}
			DNode *n = first;
			if(n->song->title == t){
				cout << "Removing: ";
				n->song->printSong();
				n->prev->next = n->next;
				n->next->prev = n->prev;
				return 0;
			}
			while(n->next != NULL){
				n = n->next;
				if(n->song->title == t){
					cout << "Removing: ";
					n->song->printSong();
					n->prev->next = n->next;
					n->next->prev = n->prev;
					return 0;
				}
			}
			cout << "Failed: Song not in List" << endl;
			return -1;
		}

		void DLL::moveUp(string t){
			if(numSongs == 0){
				cout << "Nothing to do, list is empty" << endl;
			} else {
				DNode *n = first;
				while(n != NULL){
					if(n->song->title == t){
						if(n->prev == NULL){
							// Top of list, move to bottom
							first = n->next;
							first->prev = NULL;
							last->next = n;
							n->prev = last;
							last = n;
							last->next = NULL;
							break;
						} else if (n->prev->prev == NULL){
							// Second in list, make n first
							n->prev->next = n->next;
							n->next->prev = n->prev;
							n->prev->prev = n;
							n->next = n->prev;
							n->prev = NULL;
							first = n;
							break;
						} else if(n->next == NULL){
							// Last in list, make n->prev last
							n->prev->prev->next = n;
							last = n->prev;
							n->prev->next = NULL;
							n->next = n->prev;
							n->prev = n->next->prev;
							n->next->prev = n;
							break;
						}	else {
							// Any other case
							n->prev->prev->next = n;
							n->next->prev = n->prev;
							n->prev->next = n->next;
							n->next = n->prev;
							n->prev = n->prev->prev;
							n->next->prev = n;
							break;
						}
					}
					n = n->next;
				}
			}
		}

		void DLL::moveDown(string t){
			if(numSongs == 0){
				cout << "Nothing to do, list is empty" << endl;
			} else {
				DNode *n = first;
				while(n != NULL){
					if(n->song->title == t){
						if(n->prev == NULL){
							// Top of list, make n->next first
							n->next->next->prev = n;
							first = n->next;
							first->prev = NULL;
							n->next = first->next;
							first->next = n;
							n->prev = first;
						} else if (n->next == NULL){
							// Last in list, move to top
							first->prev = n;
							n->next = first;
							first = n;
							last = n->prev;
							last->next = NULL;
							n->prev = NULL;
						} else if(n->next->next == NULL){
							// Second to last in list, make n last
							n->prev->next = n->next;
							n->next->prev = n->prev;
							n->next->next = n;
							n->prev = n->next;
							last = n;
							n->next = NULL;
						}	else {
							// Any other case
							n->prev->next = n->next;
							n->next->prev = n->prev;
							n->next = n->next->next;
							n->prev = n->next->prev;
							n->next->prev->next = n;
							n->next->prev = n; 
						}
					}
					n = n->next;
				}
			}
		}

		void DLL::makeRandom(){

		}

		void DLL::listDuration(int *tm, int *ts){
			if(numSongs == 0){
				*tm = 0;
				*ts = 0;
			} else {
				DNode *n = first;
				while (n != NULL){
					*tm += n->song->min;
					*ts += n->song->sec;
					n = n->next;
				}
			}
		}

		DLL::~DLL(){
			DNode *n = first;
			while(numSongs){
				n = n->next;
				delete n->prev;
				numSongs--;
			}
			first = NULL;
			last = NULL;
		}
