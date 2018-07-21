/*  I, Christian R. Mante, do solemnly swear that I have made this MP all by myself.
    This program is a C++ implementation of the student database.
*/

#include <iostream>
#include "list.h"

int main() {
    list l;
    int c = 0, i = 0, z = 0, x = 0;
    student s;

    do {
        //system("cls");
        cin.ignore();
        cout << "\n\t1. Enroll a Student\n\t2. Drop a Student\n\t3. Sort by ID\n\t4. Sort by Name"
                "\n\t5. Display all Students\n\t6. Display all Students by year\n\t7. Search by Name\n\t8. Exit" ;
        cin>>c;
        switch(c)
        {
            case 1:
                //system("cls");
                cin.ignore();
                cout<<"Please fill in the appropriate info:" << endl;

                do {
                    cout<<"Student's First name : ";
                    getline(cin,s.fname,'\0');
                    //z=check_valid_first_name(s);
                    if(!z) {
                        cout << endl << "Invalid first name format." << endl;
                        cin.get();
                    }

                } while(!z);

                do {
                    z = 0;
                    cout << "Student's Middle name : " ;
                    getline(cin,s.mname,'\0');
                    //z=check_valid_middle_name(s);
                    if(!z) {
                        cout<< endl << "Invalid middle name format." << endl;
                        cin.get();
                    }

                } while(!z);

                do {
                    z = 0;
                    cout << "Student's Family name : " ;
                    getline(cin,s.lname, '\0');
                    //z=check_valid_family_name(s);
                    if(!z) {
                        cout<< endl <<  "Invalid family name format." << endl;
                        cin.get();
                    }

                } while(!z);

                cout << "Student's Full Name is : " << s.fname << s.mname << s.lname << endl;

                do {
                    cout << "Student's student number : ";
                    getline(cin,s.number,'\0');
                    //z=check_valid_studNum(l,s);
                    //x=found_studNums(l,s);
                    if(!z) {
                        cout << endl << "Invalid student number input." << endl;
                        cin.get();
                    }

                    else if(x) {//x means tells a duplicate of the student number exists in the database
                        cout << endl << "Student Number already exists in the database." << endl;
                        cin.get();
                    }

                }while(!z || x);

                do
                {
                    cout << "Program : ";
                    getline(cin,s.program,'\0');
                    //z=check_program(s);
                    if(!z) {
                        cout << endl << "Invalid program input." << endl;
                        cin.get();
                    }
                } while(!z);

                do
                {
                    z = 0;
                    cout <<  "Student's year level : " << endl;
                    cin >> s.yr;
                    //z=check_valid_level(s);
                    if(!z) {
                        cout << endl << "Invalid year level format." << endl;
                        cin.get();
                    }

                } while(!z);

                do
                {
                    z = 0;
                    cout << "Student's gender : " <<endl ;
                    cin.ignore();
                    cin >> s.gender;
                    //z=check_valid_gender(s);
                    if(!z) {
                        cout << endl << "Invalid gender format." << endl;
                        cin.get();
                    }

                } while(!z);

                //append(&l,s);
                cout << endl << "Student successfully enrolled in CMSC21." << endl;
                //save(l,s);//save
                cin.get();
                break;

            case 2:
                //load
                //system("cls");
                cout << "Drop a Student" << endl;
                cout << "Enter student number : ";
                cin.ignore();
                getline(cin,s.number,'\0');
                //x=found_studNums(l,s);

                if(!x) {
                    cout << "Student number " << s.number <<  "does not exist in the database." << endl;
                    cin.get();
                    break;
                }

                i = l.give_pos(s);
                i = l.deleteItem(i);
                cout << endl << s.number << "is officially dropped from CMSC21." << endl;
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

            case 5:
                //load
                //system("cls");
                cout << "The following students are currently enrolled in CMSC21 : " << endl << endl;
                l.display();
                //printf("\n");
                //save(l,s);//save
                cin.get();
                break;

            case 6:
                //load
                //system("cls");
                cout << "Display all Students by Year Level " << endl;
                cout << "Enter student year level : ";
                cin >> s.yr;
                l.display_by_year(s);
                //save(l,s);//save
                cin.get();
                break;

            case 7:
                //load
                cout << "Student Search " << endl;
                cout << "Please enter student family name for search : ";
                getline(cin,s.lname,'\0');
                l.student_search(s);
                //save(l,s);//save
                cin.get();
            default:
                break;
        }
    }
    while(c!=8);
    l.emptyList();
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
