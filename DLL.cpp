
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
			} /*else {
				DNode *n = first;
				while(n != NULL){
					if(n->song->title == t){
						if(n->prev == NULL){
							// Top of list, move to bottom
						} else if (n->prev->prev == NULL){
							// Second in list, make n first
						} else if(n->next == NULL){
							// Last in list, make n->prev last
						}	else {
							// Any other case
						}
					}
				}
			}*/
		}

		void DLL::moveDown(string t){
			if(numSongs == 0){
				cout << "Nothing to do, list is empty" << endl;
			} /*else {
				DNode *n = first;
				while(n != NULL){
					if(n->song->title == t){
						if(n->prev == NULL){
							// Top of list, make n->next last
						} else if (n->next == NULL){
							// Last in list, move to top
						} else if(n->next->next == NULL){
							// Second to last in list, make n last
						}	else {
							// Any other case
						}
					}
				}
			}*/
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
