#include <iostream>
#include <cstdlib>
#include "randomized_queue.h"
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::getline;

int main(int argc, const char * argv[]) {
    int k = atoi(argv[1]);
    cout << "Please enter a sequence of characters. " << endl;
    string str;
    getline(cin,str);
    RandomizedQueue<char> rq;
    for(int i=0;i<str.size();i++)
        if(str[i]!=' ')
            rq.enqueue(str[i]);
    
    char subset[k];
    int count=0;
    while(count!=k){
        char s = rq.sample();
        subset[count] = s;
        count++;
        for(int i=0;i<count-1;i++){
            if(s==subset[i]){  // check any similar elements in subset
                count--;
                break;
            }
        }
    }
    
    cout << k << "-Subset:" << endl;
    for(int i=0;i<k;i++)
        cout << subset[i] << endl;
    
    return 0;
}
