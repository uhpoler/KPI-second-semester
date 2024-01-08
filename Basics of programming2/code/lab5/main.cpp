/* 

��������� ���� TPrism, ���� ����������� ��������� ������ � ������ ������
��� ����������� ����� ������� �� ��'���. �� ����� ����� ����� �������� �����-������� TPrism3
�� Tprism4, �� ������������� ��������� �������� �� ����������� ������.
��� ��� ��������� ��������� �������� �� ����������� ������ ��������� � ���������.
�������� ��������� m ���������� �����(��������� �� ������������), ��'�� ����� � ���� �� 5 �����
����������. ��� ��������� ����� ������ �������� ��'��, � ��� ������������ - ���� ���� �������.
������� �� ���������� �� �����

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
    cout << "  ��'��: " << prism3.getVolumeNew() << endl;
    cout << "|-----------------------------------------|" << endl;
    cout << endl;

    TPrism4 prism4;
    prism4.inputDataBase();
    cout << "  ��'��: " << prism4.getVolumeNew() << endl;
    cout << "  ����� ����� �������: " << prism4.getSurfaceArea() << endl;
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
        cout << "  ������ ������� ��� " << (i + 1) << " ��������� �������ί ������:";
        cin >> side;
        additionalPrism3.setVolume(previousPrism3.getVolumeNew());
        additionalPrism3.inputDataAdd(side);
        cout << "  ��'�� " << (i + 1) << " ��������� �������ί ������: " << additionalPrism3.getVolumeNew() << endl;
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
        cout << "  ������ ������� ��� " << (i + 1) << " ��������� ����������ί ������:";
        cin >> side;
        additionalPrism4.setVolume(previousPrism4.getVolumeNew());
        additionalPrism4.inputDataAdd(side);
        cout << "  ��'�� " << (i + 1) << " ��������� ����������ί ������: " << additionalPrism4.getVolumeNew() << endl;
        cout << "  ����� ����� ������� ��������� ����������ί ������: " << additionalPrism4.getSurfaceArea() << endl;
        previousPrism4 = additionalPrism4;
        sumQuadrilateralSurfaceArea += additionalPrism4.getVolumeNew();
    }


    lastSum( sumTriangularVolume, sumQuadrilateralSurfaceArea);

   

    return 0;
}
