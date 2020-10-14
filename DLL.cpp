
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
		*n->prev = *last;
		*n->prev->next = *n;
		last = n;
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

		/*void DLL::moveUp(string t){
			if(numSongs == 0){
				cout << "Failed: List is Empty" << endl;
			} else {
				DNode *n = first;
				if
				while (n->next != NULL) {

				}*/



			}
		}
