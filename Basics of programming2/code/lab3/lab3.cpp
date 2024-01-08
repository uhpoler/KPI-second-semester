#include <iostream>
#include <string>
#include "func.h"

using namespace std;



int main() {


    const int max = 100;
    Train trains[max] = {
        Train(1, "Kyiv", "01-30"),
        Train(2, "Kyiv", "16-15"),
        Train(3, "Kyiv", "14-23"),
        Train(4, "Lviv", "20-45"),
        Train(5, "Lviv", "18-30"),
        Train(6, "Lviv", "20-17"),
        Train(7, "Lviv", "22-15"),
        Train(8, "Odessa", "23-45"),
        Train(9, "Odessa", "01-06"),
        Train(10, "Dnipro", "03-50")
    };
    int numTrains = 10;

    while (true) {
        string choice = menu();

        if (choice == "1") {
            addTrain(trains, numTrains, max);
        }
        else if (choice == "2") {
            findLatestTrainToDestination(trains, numTrains);
        }
        else {
            break;
        }
    }

    return 0;
}



//розробити клас поїзд, який характеризується номером поїзда, 
//пунктом призначення, часом його відправлення(у форматі ГГ-ХХ).
//створити масив об'єктів даного класу. 
//визначити самий пізній поїзд(його номер), який
//відправляється в заданий пункт призначення