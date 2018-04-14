#include <iostream>
#include "randomized_queue.h"
using std::cout;
using std::endl;

RandomizedQueue<char> rq;

void check(){
    cout << "Empty? " << rq.isEmpty() << endl;
    cout << "Size? " << rq.size() << endl;

    int i;
    RandomizedQueue<char>::Iterator itr = rq.iterator();
    cout << "queue : ";
    for(i = 0; i < rq.size();i++){
        cout << *itr << " ";
        ++itr;
    }
    cout << endl;
}

int main(int argc, char ** argv){

    srand(unsigned(time(0)));

    check();

    rq.enqueue('r');

    check();
   
    rq.enqueue('a');
    rq.enqueue('n');
    rq.enqueue('d');
    rq.enqueue('o');
    rq.enqueue('m');
    rq.enqueue('q'); 
    rq.enqueue('u'); 
    rq.enqueue('e');
 
    check();
    
    cout << "dequeue :  " << rq.dequeue() << endl;

    check();

    cout << "dequeue :  " << rq.dequeue() << endl;
    cout << "dequeue :  " << rq.dequeue() << endl;

    check();

    cout << "sampling : " ;
    for(int i=0; i<rq.size()*2;i++){
        cout << rq.sample() << " ";
    }
    cout << endl;

    cout << "dequeue :  " << rq.dequeue() << endl;
    
    check();

    return 0;
}
