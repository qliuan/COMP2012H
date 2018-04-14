#include <iostream>
#include <stdexcept>
#include <cstdlib>
using std::runtime_error;

#ifndef randomized_queue_h
#define randomized_queue_h

template <typename Item>
class Iter {
private:
    Item* itr;
    int size;
public:
    Iter(Item* array,int count) : size(count)
    {
        // copy array to itr
        itr = new Item[size];
        for(int i=0;i<size;i++)
            itr[i]=array[i];

        // rearrange the itr randomly
        for(int i=0;i<size;i++)
        {
            int ran1=rand()%size;
            int ran2=rand()%size;
            Item temp=itr[ran1];
            itr[ran1]=itr[ran2];
            itr[ran2]=temp;
        }
    }
    Iter(const Iter& It) : itr(It.itr),size(It.size){}
    Item& operator*()
    {
        return *itr;
    }
    Iter& operator++()
    {
        itr++;
        return *this;
    }
};

template <typename Item>
class RandomizedQueue{
private:
    Item* array;
    int max;
    int count;
public:
    RandomizedQueue() : count(0),max(2) // construct an empty randomized queue
    {
        array = new Item[max];
        array[0] = NULL;
        array[1] = NULL;
    }
    
    bool isEmpty()                      // is the queue empty?
    {
        if(count==0) return true;
        else         return false;
    }
    
    int size()                          // return the number of items on the queue
    {
        return count;
    }
    
    void enqueue(Item item)             // add the item
    {
        count++;
        if(count>max)
        {
            Item* temp = new Item[count-1];
            for(int i=0;i<count-1;i++)
                temp[i] = array[i];
            delete[] array;
            max*=2;     // double the size
            array = new Item[max];
            for(int i=0;i<count-1;i++)
                array[i] = temp[i];
            delete[] temp;
        }
        array[count-1] = item;
    }
    
    Item dequeue()                      // delete and return a random item
    {
        if(count==0)
        {
            std::runtime_error("dequeue an empty queue!!!");
            return NULL;
        }
        else
        {
            int ran = rand()%count;
            int data = array[ran];
            count--;
            if(count<max/4)
            {
                Item* temp = new Item[count];
                for(int i=0;i<count;i++)
                    temp[i] = array[i];     // copy all elements in array except the last one
                if(ran!=count)
                    temp[ran] = array[count]; // copy the last one to the position of the random one
                delete[] array;
                max*=1/2;     // half the size
                array = new Item[max];
                for(int i=0;i<count;i++)
                    array[i] = temp[i];
                delete[] temp;
            }
            else
            {
                array[ran] = array[count];
                array[count] = NULL;
            }
            return data;
        }
    }
    
    Item sample()                           // return (but do not delete) a random item
    {
        if(count==0)
        {
            std::runtime_error("sample an empty queue!!!");
            return NULL;
        }
        else
        {
            int ran = rand()%count;
            return array[ran];
        }
    }

    typedef Iter<Item> Iterator;
    Iterator iterator()                    // return an iterator that returns the items in random order
    {
        return Iterator(array,count);
    }
};

#endif /* randomized_queue_h */
