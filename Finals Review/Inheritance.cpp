#include <iostream>
using namespace std;

class Boss{
private:
    int age;
    string familyName;
    string rank;
public:
    Boss(){
        age = 0;
        familyName = "Houdini";
        rank = "Boss";
        cout<<"(1.Parent of Class Company)Boss: I am your boss!" << endl;
    }
    ~Boss(){
        cout<<"(1.Parent of Class Company)Boss: Down with the company!." << endl;
    }
    int getAge(){return age;}
    string getBossFamilyName(){return familyName;}
    string getFamilyName(){return familyName;}
};

class Company:protected Boss{
public:
    string companyName;
    Company(){companyName = "Company.inc"; cout << "(2.Parent of Class Employee)Company.inc owned by Mr. " << getBossFamilyName() << endl;}
    ~Company(){cout << "(2.Parent of Class Employee)Company gone bankrupt!" << endl;}
};

class Employee: public Company{
private:
    int age;
    string rank;
public:
    Employee(){
        age = 20;
        rank = "Employee";
        cout << "(3.Class Employee)I am an Employee and Mr. " << getBossFamilyName() << " "<< "is my boss." << endl;
    }
    ~Employee(){
        rank = "none";
        cout << "(3.Class Employee)I've got fired. T_T" << endl;
    }
};

class Neighbour : public Employee{
private:
    int age;
    string rank;
public:
    string name;
    Neighbour(){name = "Totoro"; age = 12; cout << "(4.Child of Class Employee)Hi. I am" << name << " , I'm your friendly neighbour." << endl;}
    ~Neighbour(){cout << "(4.Child of Class Employee)Totoro: I am moving to Philadelphia. Bye!" << endl;}
};

class You : private Employee{
private:
    int age;
    string rank;
public:
    string familyName;
    You(){age = 21; rank = "Employee"; familyName = "Roberts"; cout << "(4.Child of Class Employee)I am Bucky " << familyName <<" and I'm secretly Employed." << endl;}
    ~You(){cout << "(4.Child of Class Employee)Roberts: Wassup guys. Got fired. T_T Boss's turn." << endl;}
};

int main()
{
    Boss MrHoudini;
    cout << "Accepting Applicants (Inheritance Incoming...)" << endl;
    You Bucky;
    cout << "-----You've got a visitor-----" << endl;
    Neighbour Totoro;
    return 0;
}
