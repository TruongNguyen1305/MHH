#ifndef PATIENTNETWORK_H
#define PATIENTNETWORK_H

#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <sstream>
#include <stdlib.h>
#include "Petrinet.h"


vector<Node> patientNetwork() {
    vector<Node> PNet;
    Node node1, node2, node3, node4, node5;
    PNet.push_back(node1);
    PNet.push_back(node2);
    PNet.push_back(node3);
    PNet.push_back(node4);
    PNet.push_back(node5);
    PNet[0].label = "wait";
    PNet[1].label = "start";
    PNet[2].label = "inside";
    PNet[3].label = "change";
    PNet[4].label = "done";
    PNet[0].postset.push_back(1);
    PNet[1].preset.push_back(0);
    PNet[1].postset.push_back(2);
    PNet[2].preset.push_back(1);
    PNet[2].postset.push_back(3);
    PNet[3].preset.push_back(2);
    PNet[3].postset.push_back(4);
    PNet[4].preset.push_back(3);
    PNet[1].isTrans = true;
    PNet[3].isTrans = true;
    return PNet;
}
string flow[15] = {"------>[]------>","+----->[]------>", "-+---->[]------>","--+--->[]------>","---+-->[]------>",
                  "----+->[]------>","-----+>[]------>", "------+[]------>","------>[]+----->","------>[]-+---->",
                  "------>[]--+--->","------>[]---+-->", "-------[]----+->","------>[]-----+>","------>[]------+"};


bool helpAutoFirePatient(vector<Node>& pNet, int idx, int k) {
    bool res = false;
    while(checkPreset(pNet, idx)) {
        if(idx==1){
            pNet[pNet[idx].preset[0]].numToken--;
            for (int i = 0; i<15;i++){
            XoaManHinh();
            cout << " ("<<pNet[0].numToken<<")"<<flow[i]<<"("<<pNet[2].numToken<<")" << flow[0] << "(" << pNet[4].numToken << ")" << endl;    
            cout << " wait     start   inside    change    done";  
            Sleep(100);
            }
            pNet[pNet[idx].postset[0]].numToken++;
        }
        if(idx==3){
            pNet[pNet[idx].preset[0]].numToken--;
            for (int i = 0; i<15;i++){
            XoaManHinh();
            cout << " ("<<pNet[0].numToken<<")"<<flow[0]<<"("<<pNet[2].numToken<<")" << flow[i] << "(" << pNet[4].numToken << ")" << endl;
            cout << " wait     start   inside    change    done";  
            Sleep(100);
            }
            pNet[pNet[idx].postset[0]].numToken++;
        }
        XoaManHinh();
        cout << " ("<<pNet[0].numToken<<")"<<flow[0]<<"("<<pNet[2].numToken<<")" << flow[0] << "(" << pNet[4].numToken << ")" << endl;
        cout << " wait     start   inside    change    done";  
        Sleep(300);
        res = true;
    }
    return res;
}

void AutopatientNetwork(int t0, int t2, int t4) {
    vector <Node> Patient = patientNetwork();
    Patient[0].numToken = t0;
    Patient[2].numToken = t2;
    Patient[4].numToken = t4;
    bool res = false;
    int countT(0), k(0);
    int size = Patient.size();
    for(int i = 0; i < size; i++) {
        if(Patient[i].isTrans)
            countT++;
    }
    system("cls");
    cout << " ("<<Patient[0].numToken<<")"<<flow[0]<<"("<<Patient[2].numToken<<")" << flow[0] << "(" << Patient[4].numToken << ")" << endl;
    cout << " wait     start   inside    change    done";  
    Sleep(100);
    res = true;
    while(k < countT) {
        k = 0;
        for(int i = 0; i < size; i++) {
            if(Patient[i].isTrans) {
                if(helpAutoFirePatient(Patient, i,k) == false) k++;
            }
        }
    }
}







#endif

