#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <ctime>
#include <Windows.h>

using namespace std;

static float tariffs[] = { 0, 1.19, 1.7, 1.19, 0 };
static float tariffsEndHou[] = { 420, 540, 1080, 1320, 1440};

struct PhoneCall {
    char date[11];
    char startTime[9];
    char endTime[9];
    double duration;
    float cost;
};


// ������� ��� �������� �� �� � ����������
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

// ������� ��� �������� �� ���� ������
bool isValidDate(int year, int month, int day) {
    if (month < 1 || month > 12) {
        return false;
    }

    int daysInMonth;
    if (month == 2) {
        daysInMonth = isLeapYear(year) ? 29 : 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30;
    }
    else {
        daysInMonth = 31;
    }

    if (day < 1 || day > daysInMonth) {
        return false;
    }

    if (year < 1876) {
        return false;
    }

    if (year > 2023 && month > 4 && day > 7) {
        cout << "�� �� �������� � �������?";
        return false;
    }

    return true;
}


// ������� ��� �������� �� ��� �������
bool isValidTime(int hour, int minute, int second) {
    if (hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0 || second > 59) {
        return false;
    }

    return true;
}

//������� ��� ����� ����
void enterDay(PhoneCall& call, ofstream& outFile) {
    int day, month, year;
    bool isValid = false;

    do {
        cout << "������ ���� � ������ DD/MM/YYYY: ";
        cin >> day;
        cin.ignore();
        cin >> month;
        cin.ignore();
        cin >> year;
        cin.ignore();


        isValid = isValidDate(year, month, day);

        if (!isValid) {
            cout << "������ �������� ����!" << endl;
        }
    } while (!isValid);

    sprintf(call.date, "%02d/%02d/%04d", day, month, year);
    

}

//������� ��� ����� ����������� ����
void enterStartTime(PhoneCall& call, ofstream& outFile) {
    int hour, minute, second;
    bool isValid = false;
    
    do {
        cout << "������ ��� ������� ������� � ������ HH:MM:SS ";
        cin >> hour;
        cin.ignore();
        cin >> minute;
        cin.ignore();
        cin >> second;
        cin.ignore();

        isValid = isValidTime(hour, minute, second);

        if (!isValid) {
            cout << "������ ��������� ���!" << endl;
        }

    } while (!isValid);
    sprintf(call.startTime, "%02d:%02d:%02d", hour, minute, second);
    
}

//������� ��� �������� ����
void enterEndTime(PhoneCall& call, ofstream& outFile) {
    int hour, minute, second;
    bool isValid = false;

    do {
        cout << "������ ��� ��������� ������� � ������ HH:MM:SS ";
        cin >> hour;
        cin.ignore();
        cin >> minute;
        cin.ignore();
        cin >> second;

        isValid = isValidTime(hour, minute, second);

        if (!isValid) {
            cout << "������ ��������� ���!" << endl;
        }

    } while (!isValid);
    sprintf(call.endTime, "%02d:%02d:%02d", hour, minute, second);
    
}

//������� ��� ����������� ����� ���������� ������
bool continueInputFunc() {

    char answer;
    cout << endl;
    cout << "���������� ���? (y/n): ";
    cin >> answer;
    cout << endl;

    if (answer != 'y' && answer != 'Y') {
        return  false;
    }

    cin.ignore();

    return true;
}

//������� ��� ������ ��������� �������
void printHeaderTable() {
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "| ����      | ��� ������� | ��� ��������� | ��������� (��) | ������� (���) |" << endl;
    cout << "------------|-------------|----------------|-----------------|-----------------" << endl;

}


//������� ��� ������ ������
void tariff() {
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "|                                ������� ������:                             |" << endl;
    cout << "|      09:00-18:00  1.7 ���/��                      22:00-07:00  0 ���/��     |" << endl;
    cout << "|                     07:00-09:00  ��  18:00-22:00  1.19 ���/��               |" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << endl;

}

//������� ��� ���������� ������
double calculateCallDuration(PhoneCall call) {
    int startHour, startMinute, startSecond, endHour, endMinute, endSecond;
    double durationInSeconds;
    sscanf(call.startTime, "%d:%d:%d", &startHour, &startMinute, &startSecond);
    sscanf(call.endTime, "%d:%d:%d", &endHour, &endMinute, &endSecond);

    if (startHour < endHour) {
        durationInSeconds = (endHour * 3600 + endMinute * 60 + endSecond) - (startHour * 3600 + startMinute * 60 + startSecond);
    }
    else { //������� �� ���� ����
        durationInSeconds = (endHour * 3600 + endMinute * 60 + endSecond) + ((23-startHour) * 3600 + (59-startMinute) * 60 + (60-startSecond));
    }
    
    double durationInMinutes = durationInSeconds / 60;
   
    return durationInMinutes;
}

//���������� ������� ��� ���������� �������
float function1(double startCallMinute, double allTimeCall, int index) {
    
    if (tariffsEndHou[index]- startCallMinute < allTimeCall) {
        double sum = (tariffsEndHou[index] - startCallMinute) * tariffs[index];
        allTimeCall -= tariffsEndHou[index] - startCallMinute;
        
        if (index == 4) {
            index = 0;
            startCallMinute = 0;
        }
        else {
            startCallMinute = tariffsEndHou[index];
            index += 1;
        }
            
        return sum + function1(startCallMinute, allTimeCall, index);
    }
    return allTimeCall* tariffs[index];
   
}

//������� ��� ���������� �������
float calculateCallCost(PhoneCall call) {
    float startHour, startMinute, startSecond, endHour, endMinute, endSecond;
  
    float cost=0;
    double minute = calculateCallDuration(call);


    sscanf(call.startTime, "%f:%f:%f", &startHour, &startMinute, &startSecond);
    sscanf(call.endTime, "%f:%f:%f", &endHour, &endMinute, &endSecond);

    double startCallMinute = startHour * 60 + startMinute + startSecond / 60;
    if (startHour < 7 || startHour>22) {
        
        if (startHour < 7) {
           return (double)function1(startCallMinute, minute, 0);
        }
        else {
            return (double)function1(startCallMinute, minute, 4);
        }
        
    }
    else if ((startHour>7 && startHour<9) || (startHour>18 && startHour<22)) {
        if (startHour > 7 && startHour < 9) {
            return (double)function1(startCallMinute, minute, 1);
        }
        else {
            return (double)function1(startCallMinute, minute, 3);
        }
    }
    else {
        double cost = (double)function1(startCallMinute, minute, 2);
  
        return cost;
    }
}











//�������� �������� ��� �������� ������� ����, 
//���� ���������� ����� ������� ���������� ��� 
//�������� �������.����, ��� ������� �� ��� 
//��������� �������.��������� �� ������� �� 
//����� ����� ������ �� ������� � ����������� 
//����, �� � ����� ���(� 22:00 �� 7 : 00) ������ 
//����������, � ����� - ���(� 9:00 �� 18 : 00) 
//������� ������� 1.7 ���, � �(18:00 �� 22 : 00)(7:00-9:00) - 
//1.19 ��� �� �������

