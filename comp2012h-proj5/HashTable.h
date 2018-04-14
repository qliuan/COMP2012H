#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "List.h"
#include <string>
#include <cctype>
#include <iostream>
using namespace std;

template <class Node>
class HashTable{
private:
	List<Node>* *lists;
	int size;
	int base;
public:
	HashTable(int,int);
	~HashTable();
	int basePower(int);
	int Hash(const string&);
	Node* searchNode(const string&);
    Node* searchNode(Node*);
	Node* modifyNode(const string&);
	Node* insertNode(const string&);
	bool deleteNode(const string&);
	Node* queryNode(const string&);
	List<Node>* getList(const string&);
    List<Node>* *getLists();
};

template <class Node>
HashTable<Node>::HashTable(int s,int b) : size(s),base(b) {
	lists = new List<Node>*[size]; 
	for(int i=0;i<size;i++){
		lists[i] = new List<Node>;
	}
	//cout << "****creation of stuTab****" << endl; 
}

template <class Node>
HashTable<Node>::~HashTable() {}

template <class Node>
int HashTable<Node>::basePower(int i){
	if(i==0)
		return 1;
	else
		return (base*basePower(i-1))%size;
}

template <class Node>
int HashTable<Node>::Hash(const string &key){
    int value = 0;
	for(int i=0;i<key.length();i++){
		if(isdigit(key[i])){
			value = ( value+(key[i]-'0')*(basePower(i))%size )%size; 
		}
		else{  // character
			value = ( value+(key[i]-'A'+10)*(basePower(i))%size )%size; 
		}
	}
    return value;
}

template <class Node>
Node* HashTable<Node>::searchNode(const string &key){
    int buck = Hash(key);
	return lists[buck]->searchNode(key);
}

template <class Node>
Node* HashTable<Node>::searchNode(Node* node){
    int buck = Hash(node->key);
    return lists[buck]->searchNode(node);
}

template <class Node>
Node* HashTable<Node>::modifyNode(const string &key){
	int buck = Hash(key);
    //cout << "****call for Hash::modifyNode****" << endl;
    cout << "buck = " << buck << endl;
	return lists[buck]->searchNode(key);
}

template <class Node>
Node* HashTable<Node>::insertNode(const string &key){
	int buck = Hash(key);
    //cout << "****call for Hash::insertNode****" << endl;
    cout << "buck = " << buck << endl;
	return lists[buck]->insertNode(key);
}

template <class Node>
bool HashTable<Node>::deleteNode(const string &key){
	int buck = Hash(key);
    //cout << "****call for Hash::deleteNode****" << endl;
    cout << "buck = " << buck << endl;
	return lists[buck]->deleteNode(key);
}

template <class Node>
Node* HashTable<Node>::queryNode(const string &key){
	int buck = Hash(key);
    //cout << "****call for Hash::queryNode****" << endl;
    cout << "buck = " << buck << endl;
	return lists[buck]->queryNode(key);
}

template <class Node>
List<Node>* HashTable<Node>::getList(const string &key){
    int buck = Hash(key);
	return lists[buck];
}

template <class Node>
List<Node>** HashTable<Node>::getLists(){
    return lists;
}

#endif /*HASHTABLE_H*/
