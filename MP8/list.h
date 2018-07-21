#include <iostream>
#include <string>
using namespace std;

class student{
    public:
        string number;
        string fname;
        string mname;
        string lname;
        string program;
        int yr;
        char gender;
};

class node{
    public:
        student item;
        struct node *next;
        node();
        node(student x);
};

class list{
    private:
        node *head, *tail;
        int size;
    public:
        list();
        ~list();
        void append(student s);
        void insertFront(student s);
        void insert(student s);
        void emptyList();
        int deleteItem(int pos);
        void setList();
        student getItem(int pos);
        void display();
        void displayStudent(student s);
        int found_studNums(student s);
        int give_pos(student s);
        void display_by_year(student s);
        void student_search(student s);
        int getSize();
};
