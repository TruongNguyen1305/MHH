#ifndef SPECIALISTNETWORK_H
#define SPECIALISTNETWORK_H

#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <sstream>
#include <stdlib.h>
#include <conio.h>
#include "Petrinet.h"


vector<Node> specialistNetwork() {
    vector<Node> pNet;
    Node free, start, busy, change, docu, end;
    pNet.push_back(free);
    pNet.push_back(start);
    pNet.push_back(busy);
    pNet.push_back(change);
    pNet.push_back(docu);
    pNet.push_back(end);
    pNet[0].preset.push_back(5);
    pNet[0].postset.push_back(1);
    pNet[1].preset.push_back(0);
    pNet[1].postset.push_back(2);
    pNet[2].preset.push_back(1);
    pNet[2].postset.push_back(3);
    pNet[3].preset.push_back(2);
    pNet[3].postset.push_back(4);
    pNet[4].preset.push_back(3);
    pNet[4].postset.push_back(5);
    pNet[5].preset.push_back(4);
    pNet[5].postset.push_back(0);
    pNet[1].isTrans = pNet[3].isTrans = pNet[5].isTrans = true;
    pNet[0].label = "free";
    pNet[1].label = "start";
    pNet[2].label = "busy";
    pNet[3].label = "change";
    pNet[4].label = "docu";
    pNet[5].label = "end";
    return pNet;
}


string flow1Spe[7] = {" [ ]----->", " [ ]+---->", " [ ]-+--->"," [ ]--+-->"," [ ]---+->"," [ ]----+>", " [ ]-----+"};
string flow2Spe[8] = {")------>[ ]", ")+----->[ ]",")-+---->[ ]",")--+--->[ ]",")---+-->[ ]",")----+->[ ]",")-----+>[ ]",")------+[ ]"};
string flowSpe[12] = {"<------[]<------","<------[]<-----+","<------[]<----+-", "<------[]<---+--","<------[]<--+---",
"<------[]<-+----","<------[]<+-----","<-----+[]<------","<----+-[]<------","<---+--[]<------","<-+----[]<------","<+-----[]<------"};

bool helpAutoFirespecialist(vector<Node>& pNet, int idx) {
    while(checkPreset(pNet, idx)) {
        if(_kbhit()){
            char key= _getch();
            if(key==' ') return false;
        }
        if(idx==1){
            XoaManHinh();
            pNet[pNet[idx].preset[0]].numToken--;
            cout << " free      end     docu" << endl;
            cout << " ("<<pNet[0].numToken<<")"<<flowSpe[0]<<"("<<pNet[4].numToken<<")" << endl;    
            cout << "  |                  ^" << endl 
                 << "  |                  |" << endl 
                 << "  |                  |" << endl
                 << "  v                  |" << endl;
            cout << " [ ]----->" <<"("<<pNet[2].numToken<<")------>[ ]" << endl;
            cout << "start    busy    change";  
            cout << endl << "Press \"SPACE\" to break auto fire";
            Sleep(100);

            XoaManHinh();
            cout << " free      end     docu" << endl;
            cout << " ("<<pNet[0].numToken<<")"<<flowSpe[0]<<"("<<pNet[4].numToken<<")" << endl;    
            cout << "  +                  ^" << endl 
                 << "  |                  |" << endl 
                 << "  |                  |" << endl
                 << "  v                  |" << endl;
            cout << " [ ]----->" <<"("<<pNet[2].numToken<<")------>[ ]" << endl;
            cout << "start    busy    change"; 
            cout << endl << "Press \"SPACE\" to break auto fire";
            Sleep(100);

            XoaManHinh();
            cout << " free      end     docu" << endl;
            cout << " ("<<pNet[0].numToken<<")"<<flowSpe[0]<<"("<<pNet[4].numToken<<")" << endl;    
            cout << "  |                  ^" << endl 
                 << "  +                  |" << endl 
                 << "  |                  |" << endl
                 << "  v                  |" << endl;
            cout << " [ ]----->" <<"("<<pNet[2].numToken<<")------>[ ]" << endl;
            cout << "start    busy    change";    
            cout << endl << "Press \"SPACE\" to break auto fire";         
            Sleep(100);
            
            XoaManHinh();
            cout << " free      end     docu" << endl;
            cout << " ("<<pNet[0].numToken<<")"<<flowSpe[0]<<"("<<pNet[4].numToken<<")" << endl;    
            cout << "  |                  ^" << endl 
                 << "  |                  |" << endl 
                 << "  +                  |" << endl
                 << "  v                  |" << endl;
            cout << " [ ]----->" <<"("<<pNet[2].numToken<<")------>[ ]" << endl;
            cout << "start    busy    change";   
            cout << endl << "Press \"SPACE\" to break auto fire";          
            Sleep(100);

            XoaManHinh();
            cout << " free      end     docu" << endl;
            cout << " ("<<pNet[0].numToken<<")"<<flowSpe[0]<<"("<<pNet[4].numToken<<")" << endl;    
            cout << "  |                  ^" << endl 
                 << "  |                  |" << endl 
                 << "  |                  |" << endl
                 << "  +                  |" << endl;
            cout << " [ ]----->" <<"("<<pNet[2].numToken<<")------>[ ]" << endl;
            cout << "start    busy    change";   
            cout << endl << "Press \"SPACE\" to break auto fire";          
            Sleep(100);
            for (int i = 1; i < 7; i++){
                XoaManHinh();
                cout << " free      end     docu" << endl;
                cout << " ("<<pNet[0].numToken<<")"<<flowSpe[0]<<"("<<pNet[4].numToken<<")" << endl;    
                cout << "  |                  ^" << endl 
                     << "  |                  |" << endl 
                     << "  |                  |" << endl
                     << "  v                  |" << endl;
                cout << flow1Spe[i] <<"("<<pNet[2].numToken<<")------>[ ]" << endl;
                cout << "start    busy    change";  
                cout << endl << "Press \"SPACE\" to break auto fire";           
                Sleep(100);
            }
            pNet[pNet[idx].postset[0]].numToken++;
        }
        
        if(idx==3){
            pNet[pNet[idx].preset[0]].numToken--;
            for (int i = 1; i < 8; i++){
                XoaManHinh();
                cout << " free      end     docu" << endl;
                cout << " ("<<pNet[0].numToken<<")"<<flowSpe[0]<<"("<<pNet[4].numToken<<")" << endl;    
                cout << "  |                  ^" << endl 
                     << "  |                  |" << endl 
                     << "  |                  |" << endl
                     << "  v                  |" << endl;
                cout << flow1Spe[0] <<"("<<pNet[2].numToken<<flow2Spe[i] << endl;
                cout << "start    busy    change"; 
                cout << endl << "Press \"SPACE\" to break auto fire";            
                Sleep(100);
            }
                XoaManHinh();
                cout << " free      end     docu" << endl;
                cout << " ("<<pNet[0].numToken<<")"<<flowSpe[0]<<"("<<pNet[4].numToken<<")" << endl;    
                cout << "  |                  ^" << endl 
                     << "  |                  |" << endl 
                     << "  |                  |" << endl
                     << "  v                  +" << endl;
                cout << flow1Spe[0] <<"("<<pNet[2].numToken<<")------>[ ]" << endl;
                cout << "start    busy    change";   
                cout << endl << "Press \"SPACE\" to break auto fire";          
                Sleep(100);

                XoaManHinh();
                cout << " free      end     docu" << endl;
                cout << " ("<<pNet[0].numToken<<")"<<flowSpe[0]<<"("<<pNet[4].numToken<<")" << endl;    
                cout << "  |                  ^" << endl 
                     << "  |                  |" << endl 
                     << "  |                  |" << endl
                     << "  v                  +" << endl;
                cout << flow1Spe[0] <<"("<<pNet[2].numToken<<")------>[ ]" << endl;
                cout << "start    busy    change";   
                cout << endl << "Press \"SPACE\" to break auto fire";          
                Sleep(100);

                XoaManHinh();
                cout << " free      end     docu" << endl;
                cout << " ("<<pNet[0].numToken<<")"<<flowSpe[0]<<"("<<pNet[4].numToken<<")" << endl;    
                cout << "  |                  ^" << endl 
                     << "  |                  |" << endl 
                     << "  |                  +" << endl
                     << "  v                  |" << endl;
                cout << flow1Spe[0] <<"("<<pNet[2].numToken<<")------>[ ]" << endl;
                cout << "start    busy    change"; 
                cout << endl << "Press \"SPACE\" to break auto fire";           
                Sleep(100);

                XoaManHinh();
                cout << " free      end     docu" << endl;
                cout << " ("<<pNet[0].numToken<<")"<<flowSpe[0]<<"("<<pNet[4].numToken<<")" << endl;    
                cout << "  |                  ^" << endl 
                     << "  |                  +" << endl 
                     << "  |                  |" << endl
                     << "  v                  |" << endl;
                cout << flow1Spe[0] <<"("<<pNet[2].numToken<<")------>[ ]" << endl;
                cout << "start    busy    change";  
                cout << endl << "Press \"SPACE\" to break auto fire";           
                Sleep(100);
            pNet[pNet[idx].postset[0]].numToken++;
        }

        if(idx==5){
            pNet[pNet[idx].preset[0]].numToken--;
            for (int i = 0; i < 12; i++){
                XoaManHinh();
                cout << " free      end     docu" << endl;
                cout << " ("<<pNet[0].numToken<<")"<<flowSpe[i]<<"("<<pNet[4].numToken<<")" << endl;    
                cout << "  |                  ^" << endl 
                     << "  |                  |" << endl 
                     << "  |                  |" << endl
                     << "  v                  |" << endl;
                cout << " [ ]----->" <<"("<<pNet[2].numToken<<")------>[ ]" << endl;
                cout << "start    busy    change";  
                cout << endl << "Press \"SPACE\" to break auto fire";
                Sleep(100);   
            }
            pNet[pNet[idx].postset[0]].numToken++;
        }     
        XoaManHinh();
        cout << " free      end     docu" << endl;
        cout << " ("<<pNet[0].numToken<<")"<<flowSpe[0]<<"("<<pNet[4].numToken<<")" << endl;    
        cout << "  |                  ^" << endl 
            << "  |                  |" << endl 
            << "  |                  |" << endl
            << "  v                  |" << endl;
        cout << " [ ]----->" <<"("<<pNet[2].numToken<<")------>[ ]" << endl;
        cout << "start    busy    change"; 
        cout << endl << "Press \"SPACE\" to break auto fire";
        Sleep(500);
    }
    return true;
}

void AutospecialistNetwork(int t0, int t2, int t4) {
    vector <Node> specialist = specialistNetwork();
    specialist[0].numToken = t0;
    specialist[2].numToken = t2;
    specialist[4].numToken = t4;
    bool res = false;
    int countT(0), k(0);
    int size = specialist.size();
    for(int i = 0; i < size; i++) {
        if(specialist[i].isTrans)
            countT++;
    }
    system("cls");
    bool label = 1;
    while(label) {
        for(int i = 0; i < size; i++) {
            if(specialist[i].isTrans) {
                if(!helpAutoFirespecialist(specialist,i)) {
                    label = 0;
                    break;
                }
            }
        }
    }
}         
#endif

