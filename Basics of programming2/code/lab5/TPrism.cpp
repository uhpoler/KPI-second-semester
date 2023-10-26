#include "TPrism.h"
#include <cmath>
#include <iostream>


using namespace std;

TPrism::TPrism() {
    volume = 0.0;
}

void TPrism::setVolume(double v) {
    volume = v;
}

double TPrism::getVolume() const {
    return volume;
}





TPrism3::TPrism3() {
    side = 0.0;
    height = 0.0;
}

double TPrism3::getVolumeNew()  {
    double baseArea = (sqrt(3) / 4) * side * side;
    double volume = baseArea*height;
    return volume;
}

double TPrism3::getSurfaceArea()  {
    double baseArea = (sqrt(3) / 4) * side * side;
    double lateralArea = 3 * side * height;
    return 2 * baseArea + lateralArea;
}


void TPrism3::inputDataBase() {
    cout << "|-----------------------------------------|" << endl;
    cout << "|Äàí³ äëÿ ïðàâèëüíî¿ ÒÐÈÊÓÒÍÎ¯ ïðèçìè:    |" << endl;
    cout << "  Ââåä³òü ñòîðîíó: ";
    cin >> side;
    cout << "  Ââåä³òü âèñîòó: ";
    cin >> height;
    cout << endl;

}

void TPrism3::inputDataAdd(double side) {
    this->side = side;
    this->height = (volume + 5.0) / ((sqrt(3) / 4) * side * side);
}





TPrism4::TPrism4() {
    side = 0.0;
    height = 0.0;
}

double TPrism4::getVolumeNew()  {
    double baseArea = side * side;
    double volume = baseArea * height;
    return volume;
}

double TPrism4::getSurfaceArea()  {
    double baseArea = side * side;
    double lateralArea = 4 * side * height;
    return 2 * baseArea + lateralArea;
}
void TPrism4::inputDataBase() {
    cout << "|-----------------------------------------|" << endl;
    cout << "|Äàí³ äëÿ ïðàâèëüíî¿ ×ÎÒÈÐÈÊÓÒÍÎ¯ ïðèçìè: |" << endl;
    cout << "  Ââåä³òü ñòîðîíó: ";
    cin >> side;
    cout << "  Ââåä³òü âèñîòó: ";
    cin >> height;
    cout << endl;
}
void TPrism4::inputDataAdd(double side) {
    this->side = side;
    this->height = (volume + 5.0) / (side * side);
}


void lastSum(double sumTriangularVolume, double sumQuadrilateralSurfaceArea) {
    cout << endl;
    cout << endl;
    cout << "Ñóìà îá'ºêò³â ïðàâèëüíèõ ÒÐÈÊÓÒÍÈÕ ïðèçì: " << sumTriangularVolume << endl;
    cout << "Ñóìà ïëîù ïîâíî¿ ïîâåðõí³ ïðàâèëüíèõ ×ÎÒÈÐÈÊÓÒÍÈÕ ïðèçì: " << sumQuadrilateralSurfaceArea << endl;
    cout << endl;
    cout << endl;
}
