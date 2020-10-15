
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
				int c = 1;
				if(n->song->title == t){
					first = n->next;
					first->prev = NULL;
					last->next = n;
					n->prev = last;
					last = n;
					last->next = NULL;
					c = !c;
				}
				while (n->next != NULL && c) {
					n = n->next;
					if(n->song->title == t){
						if(n->prev->prev == NULL){
							first->next = n->next;
							first->prev = n;
							n->next = first;
							n->prev = NULL;
							first = n;
						} else {
							DNode *temp = n->prev;
							n->prev->next = n->next;
							n->prev->prev = n;
							n->next = n->prev;
							n->prev = temp->prev;
							delete temp;
						}
					}
					c = !c;
				}
			}
		}

		void DLL::moveDown(string t){
			if(numSongs == 0){
				cout << "Nothing to do, list is empty" << endl;
			} else {
				DNode *n = first;
				int c = 1;
				if(n->song->title == t){
					n->next = n->next->next;
					n->prev = n->next;
					first = n->next;
					first->prev = NULL;
					first->next = n;
					c = !c;
				}
				while (n->next != NULL && c) {
					n = n->next;
					if(n->song->title == t){
						if(n->next->next == NULL){

						} else if(n->next == NULL){

						} else {
							DNode *temp = n->next;
							n->next->next = n;
							n->next->prev = n->prev;
							n->next = temp->next;
							n->prev = n->next;

						}
					}
					c = !c;
				}
			}
		}
