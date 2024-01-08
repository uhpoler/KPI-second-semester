/*
Спроектувати АТД "Бінарне дерево"(кожна вершина має не більше двох нащадків) для колекції, що містить дані довільного типу. 
Інтерфейс АТД включає такі обов'язкові операції (у рекурсивній формі):
-﻿﻿визначення розміру дерева, ++++++++
-зворотний обхід дерева(за схемою Lt->Rt -> 1).
-включення нового елемента із заданим ключем. +++++++++
-﻿﻿очищення дерева, +++++++++
-﻿﻿ітератор для доступу до елементів дерева з операціями:
﻿﻿﻿ 1)встановлення на корінь дерева,
 2встановлення на  кінць дерева,
 3)перехід до попереднього елементу (відносно того, що ввів користувач),


*/



#include <iostream>
#include "BinaryTree.h"
#include <initializer_list>
#include <Windows.h>



int main() {

    setlocale(LC_CTYPE, "ukr");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    std::cout << "Оберіть тип даних.";
    std::string str;
    std::cin >> str;
    if (str == "int")
    {
        BinaryTree<int> tree1 = { 50, 40, 60, 70, 80, 55, 58, 53, 30, 20, 35, 33, 37 };

        int choice;
        int value;
        do {
            std::cout << "\n---- Меню ----\n";
            std::cout << "1. Вивести дерево на екран." << std::endl;
            std::cout << "2. Визначити розмір дерева." << std::endl;
            std::cout << "3. Включити новий елемент." << std::endl;
            std::cout << "4. Виконати зворотній обхід дерева." << std::endl;
            std::cout << "5. Встановити ітератор на корінь дерева." << std::endl;
            std::cout << "6. Перевірити кінець дерева." << std::endl;
            std::cout << "7. Перейти до попереднього елемента дерева." << std::endl;
            std::cout << "8. Очистити дерево." << std::endl;
            std::cout << "0. Вихід." << std::endl;
            std::cout << "Оберіть: ";
            std::cin >> choice;


            BinaryTree<int>::Iterator it = tree1.begin();
            BinaryTree<int>::Iterator end = tree1.end();
            int iter = *it;

            switch (choice) {
            case 1:
                if (tree1.IsEmpty()) {
                    std::cout << "Дерево пусте " << std::endl;
                }
                else {
                    tree1.Show();
                }
                break;
            case 2:
                std::cout << tree1.Size();
                break;
            case 3:
                //перевырку на однакове значення
                std::cout << "Введіть значення яке хочете додати: ";
                std::cin >> value;
                tree1.Insert(value);
                break;
            case 4:
                std::cout << "Зворотній обхід дерева: ";
                tree1.ReverseTraversal();
                std::cout << std::endl;
                break;
            case 5:
                std::cout << "Ітератор встановлений на корінь дерева." << std::endl;
                std::cout << "Поточне значення ітератора: " << iter << std::endl;
                break;
            case 6:
               
                if (it == end)
                    std::cout << "Ітератор знаходиться в кінці дерева.";
                else
                    std::cout << "Ітератор не знаходиться в кінці дерева.";
                break;
            case 7:
                std::cout << "Введіть значення: ";
                std::cin >> value;
                --it;

                std::cout << "Ітератор переміщений на попередній елемент." << std::endl;
                std::cout << "Поточне значення ітератора: " << iter << std::endl;

                break;
            case 8:
                tree1.Clear();
                std::cout << "Дерево було очищене ";
                break;
            }
        } while (choice != 0);



    }
    if (str == "double")
    {
        BinaryTree<double> tree2 = { 50.5, 40.7, 60.8, 70.87, 80.4, 55.9, 58.4, 53.8};

        int choice;
        double value;
        do {
            std::cout << "\n---- Меню ----\n";
            std::cout << "1. Вивести дерево на екран." << std::endl;
            std::cout << "2. Визначити розмір дерева." << std::endl;
            std::cout << "3. Включити новий елемент." << std::endl;
            std::cout << "4. Виконати зворотній обхід дерева." << std::endl;
            std::cout << "5. Встановити ітератор на корінь дерева." << std::endl;
            std::cout << "6. Перевірити кінець дерева." << std::endl;
            std::cout << "7. Перейти до попереднього елемента дерева." << std::endl;
            std::cout << "8. Очистити дерево." << std::endl;
            std::cout << "0. Вихід." << std::endl;
            std::cout << "Оберіть: ";
            std::cin >> choice;


            BinaryTree<double>::Iterator it = tree2.begin();
           BinaryTree<double>::Iterator end = tree2.end();
            int iter = *it;

            switch (choice) {
            case 1:
                if (tree2.IsEmpty()) {
                    std::cout << "Дерево пусте " << std::endl;
                }
                else {
                    tree2.Show();
                }
                break;
            case 2:
                std::cout << tree2.Size();
                break;
            case 3:
                //перевырку на однакове значення
                std::cout << "Введіть значення яке хочете додати: ";
                std::cin >> value;
                tree2.Insert(value);
                break;
            case 4:
                std::cout << "Зворотній обхід дерева: ";
                tree2.ReverseTraversal();
                std::cout << std::endl;
                break;
            case 5:
                std::cout << "Ітератор встановлений на корінь дерева." << std::endl;
                std::cout << "Поточне значення ітератора: " << iter << std::endl;
                break;
            case 6:

                if (it == end)
                    std::cout << "Ітератор знаходиться в кінці дерева.";
                else
                    std::cout << "Ітератор не знаходиться в кінці дерева.";
                break;
            case 7:
                std::cout << "Введіть значення: ";
                std::cin >> value;
                --it;

                std::cout << "Ітератор переміщений на попередній елемент." << std::endl;
                std::cout << "Поточне значення ітератора: " << iter << std::endl;

                break;
            case 8:
                tree2.Clear();
                std::cout << "Дерево було очищене ";
                break;
            }
        } while (choice != 0);


    }
    if (str == "char")
    {
        BinaryTree<char> tree2 = {'f','e','j','d','k','z','v','o','a'};
        
        int choice;
        char value;
        do {
            std::cout << "\n---- Меню ----\n";
            std::cout << "1. Вивести дерево на екран." << std::endl;
            std::cout << "2. Визначити розмір дерева." << std::endl;
            std::cout << "3. Включити новий елемент." << std::endl;
            std::cout << "4. Виконати зворотній обхід дерева." << std::endl;
            std::cout << "5. Встановити ітератор на корінь дерева." << std::endl;
            std::cout << "6. Перевірити кінець дерева." << std::endl;
            std::cout << "7. Перейти до попереднього елемента дерева." << std::endl;
            std::cout << "8. Очистити дерево." << std::endl;
            std::cout << "0. Вихід." << std::endl;
            std::cout << "Оберіть: ";
            std::cin >> choice;


            BinaryTree<char>::Iterator it = tree2.begin();
            BinaryTree<char>::Iterator end = tree2.end();
            int iter = *it;

            switch (choice) {
            case 1:
                if (tree2.IsEmpty()) {
                    std::cout << "Дерево пусте " << std::endl;
                }
                else {
                    tree2.Show();
                }
                break;
            case 2:
                std::cout << tree2.Size();
                break;
            case 3:
                //перевырку на однакове значення
                std::cout << "Введіть значення яке хочете додати: ";
                std::cin >> value;
                tree2.Insert(value);
                break;
            case 4:
                std::cout << "Зворотній обхід дерева: ";
                tree2.ReverseTraversal();
                std::cout << std::endl;
                break;
            case 5:
                std::cout << "Ітератор встановлений на корінь дерева." << std::endl;
                std::cout << "Поточне значення ітератора: " << iter << std::endl;
                break;
            case 6:

                if (it == end)
                    std::cout << "Ітератор знаходиться в кінці дерева.";
                else
                    std::cout << "Ітератор не знаходиться в кінці дерева.";
                break;
            case 7:
                std::cout << "Введіть значення: ";
                std::cin >> value;
                --it;

                std::cout << "Ітератор переміщений на попередній елемент." << std::endl;
                std::cout << "Поточне значення ітератора: " << iter << std::endl;

                break;
            case 8:
                tree2.Clear();
                std::cout << "Дерево було очищене ";
                break;
            }
        } while (choice != 0);

        
    }



    

    return 0;
 
}