//
//  main.cpp
//  playground
//
//  Created by Kyle Lei on 4/11/2016.
//  Copyright © 2016 LEI Zhao. All rights reserved.
//
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;

int main(int argc,const char* argv[]){
    if(argc!=2) {
        printf("Please specify size\n");
        exit(EXIT_FAILURE);
    }
    int COUNT=atoi(argv[1]);
    int pixel=32767;
    srand(time(NULL));
    const char *OUTPUT_FILE = "input.txt";
    ofstream fout(OUTPUT_FILE);
    assert (fout.is_open ());
    fout<<COUNT<<endl;
    for(int i=0;i<COUNT;++i){
        double k = 1/(rand()%10);
        int c = rand()%7 + 4;
        for(int j=0;j<c;j++){
            int x = rand()%pixel;
            int y = (rand()%pixel)*k;
            fout<<x<<" "<<y<<endl;
        }
    }
    fout.close();
    printf("input.txt with %d lines generated\n",COUNT);
    return 0;
}
