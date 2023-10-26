#pragma once



class TPrism {
protected:
    double volume;
public:
    TPrism();
    void setVolume(double v);
    double getVolume() const;
    virtual double getSurfaceArea()  = 0; //чисто віртуальна функція
    virtual double getVolumeNew()  = 0;
    virtual void inputDataBase() = 0;
    virtual void inputDataAdd(double side) = 0;
};

class TPrism3 : public TPrism {
private:
    double side;
    double height;
public:
    TPrism3();
    double getSurfaceArea() ;
    double getVolumeNew() ;
    void inputDataBase();
    void inputDataAdd(double side);
};

class TPrism4 : public TPrism {
private:
    double side;
    double height;
public:
    TPrism4();
    double getSurfaceArea() ;
    double getVolumeNew() ;
    void inputDataBase();
    void inputDataAdd(double side);
};



void lastSum(double sumTriangularVolume, double sumQuadrilateralSurfaceArea);