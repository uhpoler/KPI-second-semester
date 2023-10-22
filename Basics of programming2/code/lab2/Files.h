#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <cstdio>
#include <algorithm>
#include <regex>
#include <sstream>
using namespace std;

struct PhoneCall {
    char date[11];
    char startTime[9];
    char endTime[9];
    double duration;
    float cost;
};

bool isLeapYear(int year);
bool isValidDate(int year, int month, int day);
bool isValidTime(int hour, int minute, int second);

void tariff();
void enterDay(PhoneCall& call, ofstream& outFile);
void enterStartTime(PhoneCall& call, ofstream& outFile);
void enterEndTime(PhoneCall& call, ofstream& outFile);

bool continueInputFunc();
void printHeaderTable();


double calculateCallDuration(PhoneCall call);
float function1(double startCallMinute, double allTimeCall, int index);
float calculateCallCost(PhoneCall call);

