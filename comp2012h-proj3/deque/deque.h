#include <iostream>
#include <cstdlib>
#include <stdexcept>
using std::runtime_error;

#ifndef deque_h
#define deque_h

template <typename Item>
struct Node{
    Item data;
    Node* prev;
    Node* next;
};

template <typename Item>
class Iter
{
private:
    Node<Item>* itr;
public:
    Iter(Node<Item>* it) : itr(it){}
    Iter(const Iter& It) : itr(It.itr){}
    Iter& operator++(){
        itr = itr->next;
        return *this;
    }
    Item& operator*(){
        return itr->data;
    }
};

template <typename Item>
class Deque
{
private:
    Node<Item>* dummy;
    Node<Item>* front;
    Node<Item>* rear;
    int count;
public:
    Deque() : count(0)
    {
        dummy = new Node<Item>;
        dummy->data = NULL;
        dummy->prev = dummy;
        dummy->next = dummy;
        front = dummy;
        rear  = dummy;
    }
    
    bool isEmpty()            // is the deque empty?
    {
        if(count == 0)  return true;
        else            return false;
    }
    
    int size()                // return the number of items on the deque
    {
        return count;
    }
    
    void addFirst(Item item)  // insert the item at the front of the queue
    {
        Node<Item>* temp = new Node<Item>;
        temp->data = item;
        
        temp->next = dummy->next;
        dummy->next->prev = temp;
        dummy->next = temp;
        temp->prev = dummy;
        
        front = temp;
        rear = dummy->prev;
        count++;
    }
    
    void addLast(Item item)   // insert the item at the end of the queue
    {
        Node<Item>* temp = new Node<Item>;
        temp->data = item;
        
        temp->prev = dummy->prev;
        dummy->prev->next = temp;
        dummy->prev = temp;
        temp->next = dummy;
        
        rear = temp;
        front = dummy->next;
        count++;
    }
    
    Item removeFirst()        // delete and return the first item in queue
    {
        if(count==0)
        {
            std::runtime_error("remove from empty deque!!!");
            return NULL;
        }
        else
        {
            Item data = front->data;
            dummy->next = front->next;
            front->next->prev = dummy;
            delete front;
            
            front = dummy->next;
            count--;
            return data;
        }
    }
    
    Item removeLast()         // delete and return the last item in queue
    {
        if(count==0)
        {
            std::runtime_error("remove from empty deque!!!");
            return NULL;
        }
        else
        {
            Item data = rear->data;
            dummy->prev = rear->prev;
            rear->prev->next = dummy;
            delete rear;
            
            rear = dummy->prev;
            count--;
            return data;
        }
    }
    
    typedef Iter<Item> Iterator;
    
    Iterator iterator()  // return an iterator that examines the items in order from front to back
    {
        return front;
    }
};

#endif /* deque_h */
