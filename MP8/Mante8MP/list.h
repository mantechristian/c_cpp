#include <iostream>
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
        student() {
            cout << "Object is being created..." << endl;
        }
};

class node{
    public:
        student item;
        struct node *next;
        void setNode();
};

class list{
    private:
        node *head, *tail;
        int size;
    public:
        list();
        void append(student s);
        void insertFront(student s);
        void insert(student s);
        void emptyList();
        int deleteItem(int pos);
        void setList();
        student getItem(int pos);
        void display();
        void displayStudent(student s);
        int check_valid_studNum(student s);
        int found_studNums(student s);
        int give_pos(student s);
        void display_by_year(student s);
        void student_search(student s);
        int getSize() {
            return size;
        }
        node getHead() {
            return *head;
        }
        node getTail() {
            return *tail;
        }

        node setHead(node *tmp) {
            *tmp = *head;
            return *head;
        }

        node setTail(node *tmp) {
            *tmp = *tail;
            return *tail;
        }
};

