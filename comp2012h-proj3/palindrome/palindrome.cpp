#include <iostream>
#include "deque.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

int main(int argc, const char * argv[]) {
    cout << "Please enter a sequence consisting of characters from {A,C,G,T} " << endl;
    string str;
    getline(cin,str);
    Deque<char> dq;
    for(int i=0;i<str.size();i++)
        if(str[i]!=' '){
            dq.addFirst(str[i]);
        }
    
    bool finished = false;
    if(dq.size()%2==1){
        finished = true;    // odd size
    }
    else{
        while(dq.size()>0){
            char front=dq.removeFirst();
            char rear =dq.removeLast();
            //  checks whether front and rear matches
            if(front=='A'){
                if(rear!='T'){
                    finished = true;
                    break;
                }
            }
            else if(front=='C'){
                if(rear!='G'){
                    finished = true;
                    break;
                }
            }
            else if(front=='G'){
                if(rear!='C'){
                    finished = true;
                    break;
                }
            }
            else if(front=='T'){
                if(rear!='A'){
                    finished = true;
                    break;
                }
            }
            else{
                finished = true;
                break;
            }
        }
    }
    
    if(finished)
        cout << "false" << endl;
    else
        cout << "true" << endl;
    
    return 0;
}
