#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "Files.h"
using namespace std;

int main(int argc, char* argv[]) {

    setlocale(LC_CTYPE, "ukr");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


   if (argc != 3) {
       cout << "Введіть параметр FileStream/FilePointer" << endl;
       return 1;
    }

   char* mode = argv[2];
   if (!strcmp(mode, "FileStream")) {
       cout << "Ви в режимі роботи з потоками" << endl;
       cout << endl;

       string filename = get_filename();
       create_file(filename);
       text_to_file(filename);
       open_file(filename);

       int k = enter_k();

       encryption(filename, k);
       choose_line();
       remove_latin_words();

       string name = "clean_latin.txt";
       open_file(name);
   }
   else if (strcmp(mode, "FilePointer") == 0) {
       cout << "Ви в режимі роботи з вказівниками" << endl;
       cout << endl;
       int k = 0;
       char* filename = new char[1];
    
       filename = get_filename1();

       create_file(filename);
       text_to_file(filename);
       open_file(filename);

       k = enter_k();

       encryption(filename, k);
       choose_line1();
       remove_latin_words1();
       char name[] = "clean_latin.txt";
       open_file(name);
   }
   else {
       cout << "Невідомий параметр! Ви маєте ввести FileStream/FilePointer" << endl;
       return 1;
   }

  
    return 0;
}
