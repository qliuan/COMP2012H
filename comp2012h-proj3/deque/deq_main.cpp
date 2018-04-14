#include <iostream>
#include "deque.h"
using std::cout;
using std::endl;

Deque<char> q;
Deque<char>::Iterator itr = q.iterator();

void check(){
    cout << "Empty? "<< q.isEmpty() << endl;
    cout << "Size? " << q.size() << endl;
    
    itr = q.iterator();
    cout << "deque : ";
    for(int i=0; i < q.size();i++){
        cout << *itr << " ";
        ++itr;
    }
    cout << endl;
}

int main(int argc, char ** argv){
    srand(unsigned(time(0)));

    check();
    
    q.addFirst('M');
    q.addLast('I');
    q.addLast('D');
    q.addFirst('T');
    q.addLast('E');
    q.addFirst('R');
    q.addFirst('M');
    
    check();
    
    char rear = q.removeLast();
    cout << "remove last : " << rear << endl;
    
    check();
    
    char front = q.removeFirst();
    cout << "remove first : " << front << endl;
    
    check();
    
    rear = q.removeLast();
    cout << "remove last : " << rear << endl;
    
    check();
    
    rear = q.removeLast();
    cout << "remove last : " << rear << endl;
    
    check();
    
    //  output of 1. is different from 2.'s  , Why?
    /*
    // 1.
    cout <<"remove LFL : " << q.removeLast() << " ";
    cout << q.removeFirst() << " ";
    cout << q.removeLast() << endl;
    /*/
    //*
    // 2.
    cout <<"remove LFL : " << q.removeLast() << " " << q.removeFirst()<< " " << q.removeLast() << endl;
    //*/
    
    return 0;
}
