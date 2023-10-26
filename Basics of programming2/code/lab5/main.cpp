/* 

Визначити клас TPrism, який представляє правильну призму і містить методи
для знаходження площі поверхні та об'єму. На основі цього класу створити класи-нащадки TPrism3
та Tprism4, які представляють правильну трикутну та чотирикутну призми.
Дані для створення правильної трикутної та чотирикутної призми вводяться з клавіатури.
Створити послідовно m правильних призм(трикутних та чотирикутних), об'єм кожної з яких на 5 більше
попередньої. Для трикутних призм знайти сумарний об'єм, а для чотирикутних - суму площ поверхні.
Вивести всі результати на екран

*/
#include <Windows.h>
#include <iostream>
#include "TPrism.h"

using namespace std;


int main() {
    setlocale(LC_CTYPE, "ukr");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    TPrism3 prism3;

    prism3.inputDataBase();
    cout << "  Об'єм: " << prism3.getVolumeNew() << endl;
    cout << "|-----------------------------------------|" << endl;
    cout << endl;

    TPrism4 prism4;
    prism4.inputDataBase();
    cout << "  Об'єм: " << prism4.getVolumeNew() << endl;
    cout << "  Площа повної поверхні: " << prism4.getSurfaceArea() << endl;
    cout << "|-----------------------------------------|" << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    double sumTriangularVolume = prism3.getVolumeNew();
    double sumQuadrilateralSurfaceArea = prism4.getSurfaceArea();


    int m = 3;

    TPrism3 previousPrism3 = prism3;
    for (int i = 0; i < m; i++) {

        TPrism3 additionalPrism3;
        double side;
        cout << endl;
        cout << "  Введіть сторону для " << (i + 1) << " додаткової ТРИКУТНОЇ призми:";
        cin >> side;
        additionalPrism3.setVolume(previousPrism3.getVolumeNew());
        additionalPrism3.inputDataAdd(side);
        cout << "  Об'єм " << (i + 1) << " додаткової ТРИКУТНОЇ призми: " << additionalPrism3.getVolumeNew() << endl;
        previousPrism3 = additionalPrism3;
        sumTriangularVolume += additionalPrism3.getVolumeNew();
    
    }
    cout << endl;
    cout << endl;
    cout << endl;

    TPrism4 previousPrism4 = prism4;
    for (int i = 0; i < m; i++) {
 
        TPrism4 additionalPrism4;
        double side;
        cout << endl;
        cout << "  Введіть сторону для " << (i + 1) << " додаткової ЧОТИРИКУТНОЇ призми:";
        cin >> side;
        additionalPrism4.setVolume(previousPrism4.getVolumeNew());
        additionalPrism4.inputDataAdd(side);
        cout << "  Об'єм " << (i + 1) << " додаткової ЧОТИРИКУТНОЇ призми: " << additionalPrism4.getVolumeNew() << endl;
        cout << "  Площа повної поверхні додаткової ЧОТИРИКУТНОЇ призми: " << additionalPrism4.getSurfaceArea() << endl;
        previousPrism4 = additionalPrism4;
        sumQuadrilateralSurfaceArea += additionalPrism4.getVolumeNew();
    }


    lastSum( sumTriangularVolume, sumQuadrilateralSurfaceArea);

   

    return 0;
}
