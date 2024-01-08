#pragma once
#include <iostream>
#include <string>

using namespace std;

class Train {

public:
    int number;
    string destination;
    string departureTime;

    Train() {}

    Train(int num, string dest, string depTime) {
        number = num;
        destination = dest;
        departureTime = depTime;
    }

};

string menu();
bool isValidTrainNumber(int number);
bool isValidDestination(string destination);
bool isValidDepartureTime(string departureTime);
int validationNumber();
string validationDestination();
string validationDepartureTime();
void addTrain(Train trains[], int& numTrains, const int max);
void findLatestTrainToDestination(Train trains[], int numTrains);