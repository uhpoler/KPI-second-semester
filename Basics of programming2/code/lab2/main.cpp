#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "Files.h"
using namespace std;


int main() {

    setlocale(LC_CTYPE, "ukr");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    tariff();

    ofstream outFile("phonecalls.bin", ios::app | ios::binary);
    if (!outFile) {
            cerr << "Не вдалося відкрити файл!" << endl;
            return 1;
        }

    PhoneCall call;
    bool continueInput = true;

    while (continueInput) {
        int year{}, month{}, day{}, hour{}, minute{}, second{};

        enterDay(call, outFile);
        enterStartTime(call, outFile);
        enterEndTime(call, outFile);

        call.duration = calculateCallDuration(call);
        call.cost = calculateCallCost(call);

        outFile.seekp(0, ios::end);
        outFile.write((char*)&call, sizeof(call));

        continueInput = continueInputFunc();
    }

    outFile.close();

    ifstream inFile("phonecalls.bin", ios::in | ios::binary);
    if (!inFile) {
        cerr << "Не вдалося відкрити файл!" << endl;
        return 1;
    }

    printHeaderTable();

    while (inFile.read((char*)&call, sizeof(PhoneCall))) {
        printf("|%-11s| %-11s | %-14s | %-15.0f | %-12.2f   |\n", call.date, call.startTime, call.endTime, call.duration, call.cost);

    }


    inFile.close();
    cout << "-------------------------------------------------------------------------------" << endl;
    cin.ignore();

 
    return 0;
}
