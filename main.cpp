#include "PatientNetwork.h"
#include "SpecialistNetwork.h"
#include "SuperiposedNetWork.h"
#include "Petrinet.h"
#include <iomanip>


using namespace std;

void option() {
    system("cls");
    cout << "\tCHOOSE 1 OPTION" << endl;
    cout << setw(30) << left << "PatientNetwork" << ":\t\t" << 1 << endl;
    cout << setw(30) << left << "SpecialistNetwork" << ":\t\t" << 2 << endl;
    cout << setw(30) << left << "SuperiposedNetwork" << ":\t\t" << 3 << endl;
    cout << setw(30) << left << "Numbers of reachable marking" << ":\t\t" << 4 << endl;
    cout << setw(30) << left << "Exit program" << ":\t\t" <<  0 << endl;
    cout << "\n>>> ";
}


int main(){
    string controller("");
    option();
    cin >> controller;
    while(controller != "") {
        option();
        if(controller[0] == '1') {
            system("cls");
            cout << "PatientNetwork" << endl;
            int t0, t2, t4;
            cout << "Wait: "; cin >> t0; cout << endl;
            cout << "Inside: "; cin >> t2; cout << endl;
            cout << "Done: "; cin >> t4; cout << endl;
            AutopatientNetwork(t0,t2,t4);
            cout << endl;
            cout << "Press any key to continue. ";
            getch();
            option();
            cin >> controller;
        } else if(controller[0] == '2') {
            system("cls");
            cout << "SpecialistNetwork" << endl;
            
            int t0, t2, t4;
            cout << "Free: "; cin >> t0; cout << endl;
            cout << "Busy: "; cin >> t2; cout << endl;
            cout << "Docu: "; cin >> t4; cout << endl;
            AutospecialistNetwork(t0,t2,t4);
            cout << endl;
            cout << "Press any key to continue. ";
            getch();
            option();
            cin >> controller;
        } else if(controller[0] == '3') {
            system("cls");
            cout << "SuperiposedNetwork" << endl;
            int t0, t1, t3, t4, t6, t7;
            cout << "Wait: "; cin >> t0; cout << endl;
            cout << "Free: "; cin >> t1; cout << endl;
            cout << "Busy: "; cin >> t3; cout << endl;
            cout << "Inside: "; cin >> t4; cout << endl;
            cout << "Done: "; cin >> t6; cout << endl;
            cout << "Docu: "; cin >> t7; cout << endl;
            AutoSuperiposedNet(t0,t1,t3,t4,t6,t7);
            cout << endl;
            cout << "Press any key to continue. ";
            getch();
            option();
            cin >> controller;
        } else if(controller[0] == '4') {
            system("cls");
            int t0, t1, t3, t4, t6, t7;
            cout << "Wait: "; cin >> t0; cout << endl;
            cout << "Free: "; cin >> t1; cout << endl;
            cout << "Busy: "; cin >> t3; cout << endl;
            cout << "Inside: "; cin >> t4; cout << endl;
            cout << "Done: "; cin >> t6; cout << endl;
            cout << "Docu: "; cin >> t7; cout << endl;
            cout << "Reachable Marking Calculator: " << endl;
            cout << numReachable(t0,t1,t3,t4,t6,t7);
            cout << endl;
            cout << "Press any key to continue. ";
            getch();
            option();
            cin >> controller;
        } else if(controller[0] == '0') {
            system("cls");
            cout << "Program Exited" << endl;
            break;
        } else {
            break;
        }
    }
    return 0;
}