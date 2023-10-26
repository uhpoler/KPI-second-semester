#include <iostream>
using namespace std;

class Animal {
protected:
    string name;
    int age;
public:
    Animal(string _name, int _age) {
        name = _name;
        age = _age;
    }
    virtual void makeSound() {
        cout << "Animal sound" << endl;
    }
    string getName() {
        return name;
    }
    void setName(string _name) {
        name = _name;
    }
    int getAge() {
        return age;
    }
    void setAge(int _age) {
        age = _age;
    }
};

class Dog : public Animal {
public:
    Dog(string _name, int _age) : Animal(_name, _age) {}
    void makeSound() {
        cout << "Bark!" << endl;
    }
};

class Cat : public Animal {
public:
    Cat(string _name, int _age) : Animal(_name, _age) {}
    void makeSound() {
        cout << "Meow!" << endl;
    }
};

int main() {
    Animal* animal1 = new Animal("Generic Animal", 5);
    Dog* dog1 = new Dog("Buddy", 3);
    Cat* cat1 = new Cat("Mittens", 2);

    animal1->makeSound(); // Animal sound
    dog1->makeSound(); // Bark!
    cat1->makeSound(); // Meow!

    cout << animal1->getName() << " is " << animal1->getAge() << " years old." << endl; // Generic Animal is 5 years old.
    cout << dog1->getName() << " is " << dog1->getAge() << " years old." << endl; // Buddy is 3 years old.
    cout << cat1->getName() << " is " << cat1->getAge() << " years old." << endl; // Mittens is 2 years old.

    delete animal1;
    delete dog1;
    delete cat1;

    return 0;
}


#include <iostream>
#include <string>
using namespace std;

class Animal {
private:
    string name;
    int age;

public:
    Animal(string n, int a) {
        name = n;
        age = a;
    }

    string get_name() {
        return name;
    }

    void set_name(string n) {
        name = n;
    }

    int get_age() {
        return age;
    }

    void set_age(int a) {
        age = a;
    }

    virtual void make_sound() {
        cout << "Animal sound\n";
    }
};

class Dog : public Animal {
private:
    string breed;

public:
    Dog(string n, int a, string b) : Animal(n, a) {
        breed = b;
    }

    string get_breed() {
        return breed;
    }

    void set_breed(string b) {
        breed = b;
    }

    void make_sound() {
        cout << "Woof!\n";
    }
};

class Cat : public Animal {
private:
    bool is_indoor;

public:
    Cat(string n, int a, bool i) : Animal(n, a) {
        is_indoor = i;
    }

    bool get_is_indoor() {
        return is_indoor;
    }

    void set_is_indoor(bool i) {
        is_indoor = i;
    }

    void make_sound() {
        cout << "Meow!\n";
    }
};

int main() {
    Animal* my_animal = new Animal("Animal", 5);
    my_animal->make_sound();

    Dog* my_dog = new Dog("Rufus", 3, "Golden Retriever");
    my_dog->make_sound();

    Cat* my_cat = new Cat("Whiskers", 2, true);
    my_cat->make_sound();

    delete my_animal;
    delete my_dog;
    delete my_cat;

    return 0;
}





