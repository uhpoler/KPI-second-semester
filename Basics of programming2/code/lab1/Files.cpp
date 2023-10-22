#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <cstdio>
#include <algorithm>
#include <regex>
#include <sstream>
#include "Files.h"
using namespace std;


//функція для запиту в користувача імені файлу 
string get_filename() {
    string filename;
    bool valid = false;
    string invalidChars = "\\/:;*?! .,\"<>|";

    while (!valid) {
    cout << "Введіть назву файлу: ";
    cin >> filename;

        if (filename.length() > 20) {
            cout << "Невірна назва файлу. Назва файлу повинна бути не більше 20 символів." << endl;
        }
        else {
            bool containsInvalidChars = false;
            for (char c : filename) {
                if (invalidChars.find(c) != string::npos) {
                    containsInvalidChars = true;
                    break;
                }
            }
            if (containsInvalidChars) {
                cout << "Назва файлу не може містити наступні символи " << invalidChars << endl;

            }
            else {
                valid = true;
            }
        }
    }

    filename += ".txt";

    return filename;
}
char* get_filename1() {

    const int max_filename_length = 20;
    bool valid = false;
    char* filename = new char[max_filename_length];
    char txt[] = ".txt";

    while (!valid) {
        cout << "Введіть назву файлу: ";
        cin >> filename;


        if (strlen(filename) > max_filename_length - 1) {
            cerr << "Невірна назва файлу. Назва файлу повинна бути не більше 20 символів." << endl;
        }
        else {
            bool containsInvalidChars = false;
            for (int i = 0; i < strlen(filename); i++) {
                if (filename[i] == '\n' || filename[i] == '!' || filename[i] == ';' || filename[i] == ':' || filename[i] == ' ' || filename[i] == ',' || filename[i] == '.' || filename[i] == '/' || filename[i] == '\\' || filename[i] == ':' || filename[i] == '*' || filename[i] == '?' || filename[i] == '"' || filename[i] == '<' || filename[i] == '>' || filename[i] == '|') {
                    containsInvalidChars = true;
                    break;
                }

            }
            if (containsInvalidChars) {
                cout << "Назва файлу не може містити наступні символи \\/:;*?! .,\"<>|" << endl;
            }
            else {
                valid = true;
            }

            
        }

        
    }
   
    char* finalfilename = new char[strlen(filename) + strlen(txt) + 1];

    strcpy(finalfilename, filename);
    strcat(finalfilename, txt);
    cin.clear();
    return finalfilename;
}


//функція для створення нового файлу
void create_file(const string& filename) {
    ofstream file(filename);

    cout << "Створено новий файл " << filename << endl;
    cout << endl;

    if (!file.is_open()) {
        cout << "Не вдалося створити файл " << filename << endl;
    }

    file.close();
    
}
void create_file(char filename[]) {

    FILE* fp;
    cout << "Створено новий файл " << filename << endl;
    cout << endl;

    fp = fopen(filename , "w");

    if (fp == nullptr) {
        cout << "Не вдалося створити файл " << filename << endl;
        return;
    }

    fclose(fp);
}


//функція для запису тексту в файл
void text_to_file(string& filename) {
    ofstream file(filename);
    string line;
    int max_size = 10 * 1024 * 1024;
    int curr_size = 0;
    int line_count = 0;

    if (!file.is_open()) {
        cout << "Не вдалося відкрити файл " << filename << endl;
        return;
    }

    cout << "-------------------------------------------------------"<< endl;
    cout << "Введіть текст, який бажаєте записати у файл для подальшого шифрування " << filename << endl;
    cout << "Натисніть 1, щоб завершити запис."<< endl;
    cout << endl;

    while (getline(cin, line)) {
        if (line == "1") {
            break;
        }
        curr_size += line.length();
        line_count++;
        if (curr_size > max_size) {
            cout << "Помилка вводу. Розмір файлу не має перевищувати 10 МВ" << endl;
            file.close();
            remove(filename.c_str());
            exit(1);
        }
        file << line << endl;
    }

    file.close();

    cout << endl;
    cout << "Запис завершено." << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << endl;

    cout << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "Вміст створеного файлу:" << endl;
    


}
void text_to_file(char* filename) {
    FILE* fp;
    fp = fopen(filename, "w");
    char line[7000];

    if (fp == nullptr) {
        cout << "Не вдалося відкрити файл " << filename << endl;
        return;
    }

    cout << "-------------------------------------------------------" << endl;
    cout << "Введіть текст, який бажаєте записати у файл для подальшого шифрування " << filename << endl;
    cout << "Натисніть 1, щоб завершити запис." << endl;
    cout << endl;

    while (scanf(" %[^\n]%*c", line)) {
        if (line[0] == '1' && strlen(line) == 1) {
            break;
        }
        else if (strlen(line) > 7000) {
            cout << "Рядок має бути менше 7000 символів. Спробуйте ще раз." << endl;
            continue;
        }
        fprintf(fp, "%s \n", line);
    }
    fclose(fp);

    cout << endl;
    cout << "Запис завершено." << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << endl;

    cout << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "Вміст створеного файлу:" << endl;
    cout << endl;
}


//функція для відкриття файлу та відображення його змісту
void open_file(string& filename) {
    ifstream file(filename);
    string line;

    if (file.is_open()) {

       /* cout << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "Вміст файлу:" << endl;
        cout << endl;*/

        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
        cout << endl;
        cout << "-------------------------------------------------------" << endl;

    }
    else {
        cout << "Неможливо відкрити файл" << endl;
    }
}
void open_file(char* filename) {
    bool fileExists = true;
    FILE* fp = fopen(filename, "r");
    char* line = new char[4192];

    /*cout << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "Вміст файлу:" << endl;
    cout << endl;*/

    while (fgets(line, 7000, fp)) {
        printf( "%s", line);
    }
    fclose(fp);
    delete[] line;

    cout << endl;
    cout << "-------------------------------------------------------" << endl;
}


//функція для введення К
int enter_k() {
    int k;
    bool valid = false;

    while (!valid) {
        cout << "Введіть К (кількість елементів для розбиття на групи)" << endl;
        cin >> k;
        if (k > 20) {
            cout << "К має бути не більше 20" << endl;
        }
        else {
            valid = true;
        }
    }
    return k;
}


//функція для зворотного запису символів в рядку
string reverse_string(string line) {
    reverse(line.begin(), line.end());
    return line;
}
char* reverse_string(char* line, int k) {
    char* newline = new char[k];
    for (int i = 0, j = k - 1; j >= 0; i++, j--) {
        newline[i] = line[j];
    }
    return newline;
}


//функція для шифрування тексту в рядках
string encrypt_string(string line, int k) {

    string result = "";
    int n = line.length();
    for (int i = 0; i < n; i += k) {
        string group = line.substr(i, k);
        result += reverse_string(group);
    }
    return result;
}
char* encrypt_string(char* line, int k, int n) {
    char* result = new char[n];
        for (int i = 0; i < n; i += k) {
            char* group = new char[k];
            for (int j = i; j < i + k && j < n; j++) {
                group[j - i] = line[j];
            }
            char* reverse = reverse_string(group, min(k,n - i));
            for (int j = i; j < i + k && j < n; j++){
                result[j] = reverse[j - i];
            }
        }
    return result;
}


//функція для запису в файл шифрування тексту в рядках
void encryption(string& filename, int k) {

    ifstream infile(filename);
    ofstream outfile("encrypted.txt");
    string line;
    while (getline(infile, line)) {
        string encrypted_line = encrypt_string(line, k);
        outfile << encrypted_line << endl;
    }

    infile.close();
    outfile.close();

    cout << endl;
    //cout << "Вміст зашифрованого файлу:" << endl;
    //ifstream inputfile("encrypted.txt");
    //cout << inputfile.rdbuf();
    //inputfile.close();

}
void encryption(char* filename, int k) {
    FILE* inf;
    FILE* outf;
    inf = fopen(filename, "r");
    char encryptedfilename[] = "encrypted.txt";
    outf = fopen("encrypted.txt", "w");
    char line[7000];
    while (fgets(line, 7000, inf)) {
        int n = strlen(line) - 2;
        char* newline = encrypt_string(line, k, n);
        for (int i = 0; i < n; i++) {
            fprintf(outf, "%c", newline[i]);
        }
        fprintf(outf, "\n");
    }
    fclose(inf);
    fclose(outf);

    cout << endl;
    //cout << "Вміст зашифрованого файлу:" << endl;
    //open_file(encryptedfilename);
}


//функція для відбору непарних рядків
void choose_line() {

    ifstream inFile("encrypted.txt");
    ofstream outFile("choose_line.txt");

    if (inFile.is_open()) {
        string line;

        while (getline(inFile, line)) {
            if (line.length() %2 !=0) {
                outFile << line << endl;
            }
        }

        inFile.close();
        outFile.close();
    }
}
void choose_line1() {

    FILE* inf;
    FILE* outf;
    char inputfilename[] = "encrypted.txt";
    inf = fopen(inputfilename, "r");

    char outputfilename[] = "choose_line.txt";
    outf = fopen(outputfilename, "w");
    char line[7000];

    while (fgets(line, 7000, inf)) {
        if((strlen(line) - 1 )% 2 == 1)
            fprintf(outf, "%s", line);
    }
    fclose(inf);
    fclose(outf);
}


//функція для перевірки латинських символів
bool is_word_latin(string word) {
    for (int i = 0; i < word.length(); i++) {
        if (!((word[i] >= 'a' && word[i] <= 'z' ) || (word[i] >= 'A' && word[i] <= 'Z'))) {
            return false;
        }
       
    }
    return true;
}
bool is_word_latin(char* word, int n) {
    for (int i = 0; i < n; i++) {
        if (!((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z'))) {
            return false;
        }

    }
    return true;
}


//функція для видалення латинських слів
void remove_latin_words() {
    ifstream input_file("choose_line.txt");
    ofstream output_file("clean_latin.txt");

    string line;

    while (getline(input_file, line))
    {
        string final_line = "";
        string word = "";
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == ' ') {
                if (!is_word_latin(word)) {
                    final_line += word;
                    final_line += " ";
                }
                word = "";
            }
            else {
                word += string(1, line[i]);
            }
        }
        if (!is_word_latin(word)) {
            final_line += word;
        }
        output_file << final_line << endl;
    }

    input_file.close();
    output_file.close();

    cout << "-------------------------------------------------------" << endl;
    cout << "Вміст зашифрованого нового файлу:" << endl;
    cout << endl;
}
void remove_latin_words1() {
    FILE* inf;
    FILE* outf;
    char inputfilename[] = "choose_line.txt";
    inf = fopen(inputfilename, "r");

    char outputfilename[] = "clean_latin.txt";
    outf = fopen(outputfilename, "w");

    char line[10000];
    while (fgets(line, 10000, inf)) {
        char* final_line = new char[1];
        strcpy(final_line, "");

        char* word = new char[1];
        strcpy(word, "");

        int n = 0;
        int m = strlen(line) - 1;

        for (int i = 0; i < m; i++) {
            if (line[i] == ' ') {
                if (!is_word_latin(word,n)) {
                    strcat(final_line, word);
                    strcat(final_line, " ");
                }
                n = 0;
                strcpy(word,"");
            }
            else {
                n++;
                strncat(word, &line[i], 1);
            }
        }
        if (!is_word_latin(word, n)) {
            strcat(final_line, word);
        }
        fprintf(outf, "%s \n", final_line);
    }
    fclose(inf);
    fclose(outf);

    cout << "-------------------------------------------------------" << endl;
    cout << "Вміст зашифрованого нового файлу:" << endl;
    cout << endl;
}





//зашифрувати кожен рядок тексту наступним чином: 
//текст розбивається на групи з К елементів(К вводиться з клавіатури), 
//в кожній групі символи, включаючи пробіли, записуються у зворотному порядку. 
//Кожен рядок непарної довжини зміненого файлу переписати в новий файл. 
//У кожному рядку нового файлу видалити всі слова, 
//що складаються виключно із латинських літер. 
//Вивести вміст вхідного і створеного файлів


/*

Думи my думи мої,
Лихо мені with вами!
Нащо стали на paper
Sad рядами?.
Чом вас wind не розвіяв
In степу як пилину??
apple orange car знов тут
так прикро це бачити interesting what is it

*/



