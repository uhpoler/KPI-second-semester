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
string get_filename();
char* get_filename1();


void create_file(const string& filename);
void create_file(char filename[]);


void text_to_file(string& filename);
void text_to_file(char* filename);

void open_file(string& filename);
void open_file(char* filename);

int enter_k();

string reverse_string(string line);
string encrypt_string(string line, int k);

char* reverse_string(char* line, int k);
char* encrypt_string(char* line, int k, int n);

void encryption(string& filename, int k);
void encryption(char* filename, int k);

void choose_line();
void choose_line1();

bool is_word_latin(char* word, int n);
bool is_word_latin(string word);

void remove_latin_words();
void remove_latin_words1();


