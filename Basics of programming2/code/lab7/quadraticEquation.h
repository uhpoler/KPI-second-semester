#pragma once

#include <Windows.h>
#include <msclr\marshal_cppstd.h>
#include <stdexcept>
#include <cctype>
#include <iostream>
#include <string>
#include <cctype>


class QuadraticEquation {
private:
    int a, b, c;

public:
    QuadraticEquation(int coeffA, int coeffB, int coeffC);

    double calculateDiscriminant() const;

    void calculateRoots(double& root1, double& root2) const;

    double calculateRootsSum() const;

   
};

int validateInput(System::String^ input);