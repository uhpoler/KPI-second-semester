
#include <iostream>
#include "ClassTime.h"

using namespace std;

int main() {
	Time T1;
	T1.setHours(23);
	T1.setMinutes(12);
	T1.setSeconds(7);

	Time T2(21, 14, 34);

	Time T3 = T1;
	T3.setHours(4);
	T3.setMinutes(40);
	T1.setSeconds(13);

	cout << "T1: " << T1.getHours() << ":" << T1.getMinutes() << ":" << T1.getSeconds() << endl;
	++T1;
	cout << "T1: " << T1.getHours() << ":" << T1.getMinutes() << ":" << T1.getSeconds() << endl;
	cout << endl;

	cout << "T2: " << T2.getHours() << ":" << T2.getMinutes() << ":" << T2.getSeconds() << endl;
	T2++;
	cout << "T2: " << T2.getHours() << ":" << T2.getMinutes() << ":" << T2.getSeconds() << endl;

	cout << "T3: " << T3.getHours() << ":" << T3.getMinutes() << ":" << T3.getSeconds() << endl;
	cout << endl;
	if (T1 > T2) {
		cout << "T1 is later than T2" << endl;
	}
	else {
		cout << "T2 is later than or equal to T1" << endl;
	}

	Time T3_diff = T3.timeUntil(Time(15, 30, 0));
cout << "Time until 15:30:00 for T3: " << T3_diff.getHours() << " hours, " << T3_diff.getMinutes() << " minutes, " << T3_diff.getSeconds() << " seconds" << endl;

cout << endl;
	return 0;
}