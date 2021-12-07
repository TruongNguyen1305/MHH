#ifndef PETRINET_H
#define PETRINET_H

using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <sstream>
#include <stdlib.h>
#include <conio.h>

struct Node {
    string label;
    bool isTrans;
    int numToken;
    vector<int> preset;
    vector<int> postset;
    Node() : label(""), numToken(0), isTrans(false) {
        preset.clear();
        postset.clear();
    }
    Node(string _label, int _numToken, vector<int> _preset, vector<int> _postset, bool _isTrans = false) :
        label(_label), numToken(_numToken), preset(_preset), postset(_postset), isTrans(_isTrans) {}
};


void printMarking(vector<Node> pNet) {
    // [label, label, label, label] = [3, 4, 6, 1]
    int size = pNet.size();
    string msg("[");
    for(int i = 0; i < size; i++) {
        if(pNet[i].isTrans == false) {
            msg += (pNet[i].label + ", ");
        }
    }
    msg.pop_back();
    msg.pop_back();
    msg += "] = [";
    for(int i = 0; i < size; i++) {
        if(pNet[i].isTrans == false) {
            msg += (to_string(pNet[i].numToken) + ", ");
        }
    }
    msg.pop_back();
    msg.pop_back();
    msg += ']';
    cout << msg << endl;
}
/**
 * Viết hàm kiểm tra xem no deadlock free không?
 * while()
 *  nhập quit -> dừng
 *  gọi hàm fire
 *  no deadlock free -> dừng
 * */


bool checkPreset(vector<Node> pNet, int idx) {
    int sizePreset = pNet[idx].preset.size();
    if(sizePreset == 0) return false;
    for(int i = 0; i < sizePreset; i++) {
        if(pNet[pNet[idx].preset[i]].numToken == 0) {
            return false;
        }
    }
    return true;
}

void updateToken(vector<Node>& pNet, int idx) {
    int sizePreset = pNet[idx].preset.size();
    int sizePostset = pNet[idx].postset.size();
    for(int i = 0; i < sizePreset; i++) {
        pNet[pNet[idx].preset[i]].numToken--;
    }
    for(int i = 0; i < sizePostset; i++) {
        pNet[pNet[idx].postset[i]].numToken++;
    }
}


bool deadlockFree(vector<Node> pNet) {
    int size = pNet.size();
    for(int i = 0; i < size; i++) {
        if(pNet[i].isTrans == true) {
            if(checkPreset(pNet, i))
                return true;
        }
    }
    return false;
}

bool fire(vector<Node>& pNet) {
    int size = pNet.size();
    cout << "Firing at transition: ";
    string fireAt;
    cin >> fireAt;
    for(int i = 0; i < size; i++) {
        if(pNet[i].label == fireAt) {
            if(checkPreset(pNet, i)) {
                updateToken(pNet, i);
            }
            return true;
        }
    }
    return false;
}

bool helpAutoFire(vector<Node>& pNet, int idx) {
    bool res = false;
    while(checkPreset(pNet, idx)) {
        updateToken(pNet, idx);
        Sleep(1000);
        printMarking(pNet);
        res = true;
    }
    return res;
}

void autoFire(vector<Node>& pNet) {
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
                if(helpAutoFire(pNet, i) == false)
                    k++;
            }
        }
    }
}


string getMarking(vector<Node> pNet) {
    string res("");
    res = to_string(pNet[0].numToken) + "-" + to_string(pNet[1].numToken) + "-" + to_string(pNet[3].numToken) + "-" + to_string(pNet[3].numToken) + "-" + to_string(pNet[4].numToken) + "-" + to_string(pNet[6].numToken) + "-" + to_string(pNet[7].numToken);
    return res;
}

void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
#endif
