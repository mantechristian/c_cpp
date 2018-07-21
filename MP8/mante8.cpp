/*  I, Christian R. Mante, do solemnly swear that I have made this MP all by myself.
    This program is a C++ implementation of the student enrollment system using linked lists.
*/

#include <iostream>
#include "list.cpp"
#include <stdlib.h>

int main() {
    list l;
    int c = 0, i = 0, z = 0, x = 0;
    student s;

    do {
        system("cls");
        cout << "\n\tMenu :\n"
                "\n\t1. Enroll a Student\n\t2. Drop a Student\n"
                "\t3. Display all Students\n\t4. Display all Students by year\n\t5. Search by Name\n\t6. Exit"
                "\n\n\tType in your choice : ";
        cin>>c;
        switch(c)
        {
            case 1:
                system("cls");
                cin.ignore();
                cout<<"Please fill-in the appropriate student info:" << endl;

                do {
                    cout << "Student number : ";
                    getline(cin,s.number,'\n');
                    z = check_valid_studNum(s);
                    x = l.found_studNums(s);
                    if(!z) {
                        cout << endl << "Invalid student number input." << endl;
                    }

                    else if(x) {//x means a duplicate of the student number exists in the database
                        cout << endl << "Student Number already exists in the database." << endl;
                        cin.get();
                        break;
                    }

                }while(!z);

                if(x)
                    break;

                do {
                    cout<<"First name : ";
                    getline(cin,s.fname,'\n');
                    z = check_valid_first_name(s);
                    if(!z) {
                        cout << endl << "Invalid first name format." << endl;
                    }

                } while(!z);

                do {
                    cout << "Middle name : " ;
                    getline(cin,s.mname,'\n');
                    z = check_valid_middle_name(s);
                    if(!z) {
                        cout<< endl << "Invalid middle name format." << endl;
                    }

                } while(!z);

                do {
                    cout << "Family name : " ;
                    getline(cin,s.lname, '\n');
                    z = check_valid_family_name(s);
                    if(!z) {
                        cout<< endl <<  "Invalid family name format." << endl;
                    }

                } while(!z);

                cout << "Student's Full Name is : " << s.fname <<" "<< s.mname <<" "<< s.lname << endl;

                do
                {
                    cout << "Program : ";
                    getline(cin,s.program,'\n');
                    z = check_program(s);
                    if(!z) {
                        cout << endl << "Invalid program input." << endl;
                    }
                } while(!z);

                do
                {
                    z = 0;
                    cout <<  "Year level : " << endl;
                    cin >> s.yr;
                    z = check_valid_level(s);
                    if(!z) {
                        cout << endl << "Invalid year level format." << endl;
                    }

                } while(!z);

                do
                {
                    z = 0;
                    cout << "Gender : " <<endl ;
                    cin.ignore();
                    cin >> s.gender;
                    z = check_valid_gender(s);
                    if(!z) {
                        cout << endl << "Invalid gender format." << endl;
                    }

                } while(!z);


                l.append(s);
                cout << endl << "Student successfully enrolled in CMSC21." << endl;
                //save(l,s);//save
                cin.ignore();
                cin.get();
                break;

            case 2:
                //load
                system("cls");
                cout << "Drop a Student" << endl;
                cout << "Enter student number : ";
                cin.ignore();
                getline(cin,s.number,'\n');
                x = l.found_studNums(s);

                if(!x) {
                    cout << "Student number " << s.number <<  " does not exist in the database." << endl;
                    cin.get();
                    break;
                }

                i = l.give_pos(s);
                i = l.deleteItem(i);
                cout << endl << s.number <<  " is officially dropped from CMSC21." << endl;
                //save(l,s);//save
                cin.get();
                break;

            /*case 3:
                //load
                printf("Student list sorted by order of Student Number.\n");
                sort_snum(l);
                save(l,s);//save
                system("pause");
                break;

            case 4:
                //load
                printf("Student list sorted by order of Family Name\n");
                sort_lname(l);
                save(l,s);//save
                system("pause");
                break;*/

            case 3:
                //load
                system("cls");
                if(l.getSize() == 0) {
                    cout << "No student have been enrolled in this course yet." << endl << endl;
                    cin.get();
                    break;
                }
                cout << "The following students are currently enrolled in CMSC21 : " << endl << endl;
                l.display();
                //printf("\n");
                //save(l,s);//save
                cin.ignore();
                cin.get();
                break;

            case 4:
                //load
                system("cls");
                cout << "Display all Students by Year Level " << endl;
                cout << "Enter student year level : ";
                cin >> s.yr;
                l.display_by_year(s);
                //save(l,s);//save
                cin.ignore();
                cin.get();
                break;

            case 5:
                //load
                cout << "Student Search " << endl;
                cout << "Please enter student family name for search : ";
                cin.ignore();
                getline(cin,s.lname,'\n');
                l.student_search(s);
                //save(l,s);//save
                cin.get();

            default:
                break;
        }
    }
    while(c!=6);
    //l.emptyList();
    l.~list();
    return 0;
}

/*
void sort_snum(list l) { //bubble sort
    node *tmp = l.head;
    student store;
    int i = 0, size = 0;

    size = getSize(l);

    for(;i<size-1;i++) {//similar to the bubble sort implementation in arrays
        tmp = l.head;
        while(tmp->next!=NULL) {
            if(strcmp(tmp->item.number, tmp->next->item.number) > 0) {
                store = tmp->item;
                tmp->item = tmp->next->item;
                tmp->next->item = store;
            }
            tmp = tmp->next;
        }
    }
    return;
}

void sort_lname(list l) { //bubble sort
    node *tmp = l.head;
    student store;
    int i = 0, size = 0;

    size = getSize(l);

    for(;i<size-1;i++) {//similar to the bubble sort implementation in arrays
        tmp = l.head;
        while(tmp->next!=NULL) {
            if(strcmp(tmp->item.lname, tmp->next->item.lname) > 0) {
                store = tmp->item;
                tmp->item = tmp->next->item;
                tmp->next->item = store;
            }
            tmp = tmp->next;
        }
    }
    return;
}

void student_search(list l, student s) {
    node *tmp = l.head;
    int found = 0;
    while(tmp!=NULL) {
        if(strcmp(tmp->item.lname,s.lname)==0){
            found == 1;
            system("cls");
            printf("Student Number : %s\n",tmp->item.number);
            printf("Student Full Name : %s %s %s\n",tmp->item.fname, tmp->item.mname, tmp->item.lname);
            printf("Student Program & Year Level : %s %d\n\n",tmp->item.program, tmp->item.yr);
            return;
        }
        tmp = tmp->next;
    }
    if(!found)
        printf("\nStudent not found.\n");
    return;
}

int getSize(list l) {//
    node *tmp = l.head;
    int size = 0;
    while(tmp!=NULL){
        tmp = tmp->next;
        size++;
    }
    return size;
}

int save(list l, student s){//write
    FILE *fp;
    fp = fopen("studentDatabase.txt","w");
    if(fp == NULL) {//if file isn't found. display error message
        printf("\n\nNo such file exists.\n");
    }
    fprintf(fp, "Student's First Name : %s\n", s.fname);
    fprintf(fp, "Student's Middle Name : %s\n", s.mname);
    fprintf(fp, "Student's Family Name : %s\n", s.lname);
    //fprintf(fp, "Student's Full Name : %s %s %s", s.fname, s.mname, s.lname);
    fprintf(fp, "Student's Student Number : %s\n", s.number);
    fprintf(fp, "Student's Program : %s\n", s.program);
    fprintf(fp, "Student's Year Level : %s\n", s.yr);
    fprintf(fp, "Student's Gender : %s\n", s.gender);
    fclose(fp);
}

int load(list l, student s){//read
    FILE *fp;
    int size=0;
    size = getSize(l);
    fp = fopen("studentDatabase.txt","r");
    while(fgets(line, sizeof line, fp) != NULL){
        fgets
    }
    fclose(fp);
}
*/
