#ifndef LIST_H
#define LIST_H

#include <string>
#include <iostream>
using namespace std;

template <class Node>
class List{
private:
    Node *head;
    Node *end;
    Node* nextNode;
public:
    List(Node *h=NULL,Node *e=NULL);
    ~List();
    Node* searchNode(const string&);
    Node* searchNode(Node*);
    Node* insertNode(const string&);
    bool deleteNode(const string&);
    Node* queryNode(const string&);
    bool updateList(Node*);
    Node* getHead();
    Node* getEnd();
};

template <class Node>
List<Node>::List(Node *h,Node *e) : head(h),end(e),nextNode(NULL) {}

template <class Node>
List<Node>::~List() {}

template <class Node>
Node* List<Node>::searchNode(const string& key){
    cout << "Search for " << key << endl;
    
    Node *iter = head; 
    Node *node = new Node;
    node->key = key;

    if(iter==NULL)
        return NULL;
    if( (*head)>(*node) ){
        nextNode = head;
        return NULL;
    }
    if( (*end)<(*node) ){
        nextNode = NULL;
        return NULL;
    }
    
    while( (*iter)<(*node) ){
        cout << iter->key << endl;
        iter = iter->next;
    }
    
    if( (*iter)==(*node) ){
        cout << "Such node exists" << endl;
        return iter;
    }
    else{
        nextNode = iter;
        cout << "No such node" << endl;
        return NULL;
    }
}

template <class Node>
Node* List<Node>::searchNode(Node *node){
    cout << "Search for Node " << node->key << endl;
    
    Node *iter = head;
    
    if(iter==NULL)
        return NULL;
    if( (*head)>(*node) ){
        nextNode = head;
        return NULL;
    }
    if( (*end)<(*node) ){
        nextNode = NULL;
        return NULL;
    }
    
    while( (*iter)<(*node) ){
        cout << iter->key << endl;
        iter = iter->next;
    }
    
    if( (*iter)==node ){
        cout << "Such node exists" << endl;
        return iter;
    }
    else{
        nextNode = iter;
        cout << "No such node" << endl;
        return NULL;
    }
}

template <class Node>
Node* List<Node>::insertNode(const string& key){
    
    if(searchNode(key)){
        // Node already exists
        return NULL;
    }
    else{
        Node *newNode = new Node;
        newNode->key = key;
        
        if(head==NULL||end==NULL){  // head and end are NULL
            head = newNode;
            end = newNode;
            head->prev = end;
            end->next = head;
        } 
        else{   // find the position for newNode
            if(nextNode == head){
                head->prev = newNode;
                newNode->prev = end;
                end->next = newNode;
                newNode->next = head;
                head = newNode;
            }
            if(nextNode == NULL){
                end->next = newNode;
                newNode->prev = end;
                head->prev = newNode;
                newNode->next = head;
                end = newNode;
            }
            else{
                nextNode->prev->next = newNode;
                newNode->prev = nextNode->prev;
                nextNode->prev = newNode;
                newNode->next = nextNode;
            }
        }
        return newNode;
    }
}

template <class Node>
bool List<Node>::deleteNode(const string& key){
    //cout << "****call for List::deleteNode****" << endl;
    cout << "Delete " << key << endl;
    
    Node *node = searchNode(key); 
    if(node){
        if(head!=NULL && head==end){ // only one node
            head = end = NULL;
        }
        else{
            if(node==head)
                head = head->next;
            if(node==end)
                end = end->prev;
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        delete node;
        return true;
    }
    else{ // no node being found
        return false;
    }
}

template <class Node>
Node* List<Node>::queryNode(const string& key){
    //cout << "****call for List::queryNode****" << endl;
    cout << "Query " << key << endl;
    Node* node = searchNode(key); 
    if(node){
        return node;
    }
    else{ // no node being found
        return NULL;
    }
}

template <class Node>
bool List<Node>::updateList(Node* node){
    if( (*head)==(*end) ){
        head = end = NULL;
        return true;
    }
    else if( (*node)==(*head) ){
        head = head->next;
        return true;
    }
    else if( (*node)==(*end) ){
        end = end->prev;
        return true;
    }
    else{
        return false;
    }
}


template <class Node>
Node* List<Node>::getHead(){
    return head;
}

template <class Node>
Node* List<Node>::getEnd(){
    return end;
}
#endif /*LIST_H*/
