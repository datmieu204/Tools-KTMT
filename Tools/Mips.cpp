#include <bits/stdc++.h>
using namespace std;

int main() {
    double perLw, perSw, perRtype, perBeq, perJump;
    double fCPU;
    cout << "%lw: ";
    cin >> perLw;
    cout << "%sw: ";
    cin >> perSw;
    cout << "%R-type: ";
    cin >> perRtype;
    cout << "%Rẽ nhánh: ";
    cin >> perBeq;
    cout << "%jump: ";
    cin >> perJump;
    cout << "tần số CPU (Ghz), không có thì nhập 0: ";
    cin >> fCPU; 

    double CPInoPipe = (perLw*5)/100 + (perSw*4)/100 + (perRtype*4)/100 + (perBeq*3)/100 + (perJump*3)/100;
    double MIPSnoPipe = (fCPU / CPInoPipe) * 1000;

    string checkPipeline;
    cout << "Có pipeline không? (Y/N)";
    cin >> checkPipeline;

    if (tolower(checkPipeline[0]) == 'y') {
        double constrainLw, perWrong;
        cout << "% Lệnh lw gây phụ thuộc: ";
        cin >> constrainLw;
        cout << "% Lệnh rẽ nhánh dự đoán sai: ";
        cin >> perWrong;

        constrainLw /= 100;
        perWrong /= 100;

        double cycleLw, cycleBeq, cycleJump;
        cycleLw = constrainLw*2 + (1 - constrainLw);
        cycleBeq = perWrong*2 + (1 - perWrong);
        cycleJump = 2;

        double CPIhavePipe = perLw*cycleLw + perSw*1 + perRtype*1 + perBeq*cycleBeq + perJump*cycleJump;
        CPIhavePipe /= 100;
        double MIPShavePipe = (fCPU / CPIhavePipe)*1000;

        cout << "\nCPI không có pipeline: " << CPInoPipe << endl;
        if (MIPSnoPipe != 0) {
            cout << "MIPS không có pipeline: " << MIPSnoPipe << endl << endl;
        }

        cout << "CPI có pipeline: " << CPIhavePipe << endl;
        if (MIPShavePipe != 0) {
            cout << "MIPS có pipeline: " << MIPShavePipe << endl;
        }

        cout << "\nCó pipeline nhanh hơn " << CPInoPipe / CPIhavePipe << " lần!" << endl;
    } else {
        cout << "CPI không có pipeline: " << CPInoPipe << endl;
        if (MIPSnoPipe != 0) {
            cout << "MIPS không có pipeline: " << MIPSnoPipe << endl;
        }
    }



}