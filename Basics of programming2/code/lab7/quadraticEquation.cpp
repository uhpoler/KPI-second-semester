#include "quadraticEquation.h"
#include <cmath>

QuadraticEquation::QuadraticEquation(int coeffA, int coeffB, int coeffC) : a(coeffA), b(coeffB), c(coeffC) {
    
    if (a == 0) {
        throw std::invalid_argument("Коефіцієнт а не може дорівнювати 0");
    }

    if (coeffA < -999 || coeffA > 999 || coeffB < -999 || coeffB > 999 || coeffC < -999 || coeffC > 999) {
        throw std::out_of_range("Введено неправильні значення коефіцієнтів. Коефіцієнти повинні бути в діапазоні від -999 до 999.");
    }



}

double QuadraticEquation::calculateDiscriminant() const {
    return b * b - 4 * a * c;
}

void QuadraticEquation::calculateRoots(double& root1, double& root2) const {
    double discriminant = calculateDiscriminant();
    if (discriminant < 0) {
        throw std::runtime_error("Дискримінант менше нуля");
    }
    else if (discriminant == 0) {
        root1 = root2 = -b / (2 * a);
    }
    else {
        root1 = (-b + std::sqrt(discriminant)) / (2 * a);
        root2 = (-b - std::sqrt(discriminant)) / (2 * a);
    }
}

double QuadraticEquation::calculateRootsSum() const {
    double root1, root2;
    calculateRoots(root1, root2);
    root1 = std::pow(root1, 2);  
    root2 = std::pow(root2, 2);  
    return root1 + root2;
}



int validateInput(System::String^ input)
{

   
    if (input->Length == 0)
    {
        throw std::invalid_argument("Уведіть всі коефіцієнти.");
       
    }

    
    for each (wchar_t c in input)
    {
        if (!System::Char::IsDigit(c) && c != '-' )
        {
            throw std::invalid_argument("Введено неправильні символи для коефіцієнтів. Коефіцієнти повинні бути числами.");
           
        }
    }


    int value = System::Convert::ToInt32(input);

    return value;
}
