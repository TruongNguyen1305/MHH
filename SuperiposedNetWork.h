#ifndef SuperiposedNetWork_H
#define SuperiposedNetWork_H

#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <sstream>
#include <stdlib.h>
#include "Petrinet.h"
#include <conio.h>

void createSuperiposedNet(vector<Node>& super, int t0, int t1, int t3, int t4, int t6, int t7) {
    super.push_back(Node("wait", t0, {}, {}));  //0
    super.push_back(Node("free", t1, {}, {}));
    super.push_back(Node("start", 0, {}, {}, true));
    super.push_back(Node("busy", t3, {}, {}));
    super.push_back(Node("inside", t4, {}, {}));
    super.push_back(Node("change", 0, {}, {}, true));
    super.push_back(Node("done", t6, {}, {}));
    super.push_back(Node("docu", t7, {}, {}));
    super.push_back(Node("end", 0, {}, {}, true));
    super[0].preset = {};
    super[0].postset = {2};
    super[1].preset = {8};
    super[1].postset = {2};
    super[2].preset = {0, 1};
    super[2].postset = {3, 4};
    super[3].preset = {2};
    super[3].postset = {5};
    super[4].preset = {2};
    super[4].postset = {5};
    super[5].preset = {3, 4};
    super[5].postset = {6, 7};
    super[6].preset = {5};
    super[6].postset = {};
    super[7].preset = {5};
    super[7].postset = {8};
    super[8].preset = {7};
    super[8].postset = {1};
}
bool firer(vector<Node> &pNet, int fireAt) {
    if(checkPreset(pNet, fireAt)) {
        updateToken(pNet, fireAt);
        return true;
    }
    return false;
}
void countReachable(long &store, vector <Node> pNet){
    for (int i = 0; i < pNet.size(); i++){
        if (pNet[i].isTrans){
            vector <Node> pNetnew = pNet;
            if (firer(pNetnew, i)) {
                store++;
                countReachable(store, pNetnew);
            }
        }
    }
}
long numReachable(int t0, int t1, int t3, int t4, int t6, int t7 ){
    vector<Node> super;
    createSuperiposedNet(super,t0,t1,t3,t4,t6,t7);
    long store = 0;
    countReachable(store, super);
    return store + 1;
}

string flowSupe1[15] = {"----->[ ]----->","+----->[ ]------>", "-+---->[ ]------>","--+--->[ ]------>","---+-->[ ]------>",
                  "----+->[ ]------>","-----+>[ ]------>", "------+[ ]------>","------>[ ]+----->","------>[ ]-+---->",
                  "------>[ ]--+--->","------>[ ]---+-->", "-------[ ]----+->","------>[ ]-----+>","------>[ ]------+"};

string flowSupe2[12] = {"<-----[ ]<-----","<-----[ ]<----+","<-----[ ]<---+-", "<-----[ ]<--+--","<-----[ ]<-+---",
"<-----[]<+----","<----+[]<-----","<---+-[]<-----","<--+--[]<-----","<-+---[]<-----","<+----[]<-----"};

string flowSupe3[9] = {"------->(","+------>(","-+----->(","--+---->(", "---+--->(","----+-->(","-----+->(",
"------+>(","-------+("};

       
bool helpAutoFireSuperiposed(vector <Node> &pNet, int idx ){
    bool res = false;
    while(checkPreset(pNet, idx)) {
        system("cls");
        cout << "         free      end     docu" << endl;
        cout << "         ("<<pNet[1].numToken<<")"<<flowSupe2[0]<<"("<<pNet[7].numToken<<")" << endl;  
        cout << "          |                 ^" << endl 
            << "          |                 |" << endl 
            << "          |                 |" << endl
            << "          v start           |change" << endl;
        cout << "("<<pNet[0].numToken<<")"<< flowSupe1[0] << "("<< pNet[3].numToken<< ")" << flowSupe1[0] << "(" <<pNet[6].numToken<<")" << endl;
        cout << " wait     |       busy      ^      done" << endl;
        cout << "          |                 |"  << endl
             << "          |                 |"  << endl  
             << "          ------->("<<pNet[4].numToken<<")" << "--------" << endl;
        cout << "                inside";
        cout << endl << "Fire at: " << pNet[idx].label;
        Sleep (3500);
        updateToken(pNet, idx);
        res = true;
    }
    return res;
}
void AutoSuperiposedNet(int t0, int t1, int t3, int t4, int t6, int t7) {
    vector <Node> pNet;
    createSuperiposedNet(pNet,t0,t1,t3,t4,t6,t7);
    bool res = false;
    int countT(0), k(0);
    int size = pNet.size();
    for(int i = 0; i < size; i++) {
        if(pNet[i].isTrans)
            countT++;
    }
    while(k < countT) {
        k = 0;
        for(int i = 0; i < size; i++) {
            if(pNet[i].isTrans) {
                if(helpAutoFireSuperiposed(pNet, i) == false) k++;
            }
        }
    }
    


}

#endif