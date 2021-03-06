/*I, Christian R. Mante, upon my honor, do solemnly swear that I have made this MP all by myself.
  This program implements the student enrollment system using linked lists.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

void display(list l);
void displayStudent(student s);
void display_by_year(list l, student s);
int give_pos(list l, student s);
int check_valid_studNum(list l, student s);
int found_studNums(list l, student s);
int check_valid_first_name(student s);
int check_valid_middle_name(student s);
int check_valid_family_name(student s);
int check_valid_level(student s);
int check_valid_gender(student s);
int check_program(student s);
void sort_snum(list l);
void sort_lname(list l);
void student_search(list l, student s);
int getSize(list l);

main()
{
    list l;
    int c=0, i=0, z=0, x=0;
    student s;

    initList(&l);

    do
    {
        system("cls");
        fflush(stdin);
        printf("\n\t1. Enroll a Student\n\t2. Drop a Student\n\t3. Sort by ID\n\t4. Sort by Name");
        printf("\n\t5. Display all Students\n\t6. Display all Students by year\n\t7. Search by Name\n\t8. Exit");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                system("cls");
                fflush(stdin);
                printf("Please fill in the appropriate info:\n");

                do {
                    printf("Student's First name : ");
                    gets(s.fname);
                    z=check_valid_first_name(s);
                    if(!z) {
                        printf("\nInvalid first name format.\n");
                        system("pause");
                    }

                } while(!z);

                do {
                    z=0;
                    printf("Student's Middle name : ");
                    gets(s.mname);
                    z=check_valid_middle_name(s);
                    if(!z) {
                        printf("\nInvalid middle name format.\n");
                        system("pause");
                    }

                } while(!z);

                do {
                    z=0;
                    printf("Student's Family name : ");
                    gets(s.lname);
                    z=check_valid_family_name(s);
                    if(!z) {
                        printf("\nInvalid family name format.\n");
                        system("pause");
                    }

                } while(!z);

                printf("Student's Full Name is : %s %s %s\n",s.fname,s.mname,s.lname);

                do {
                    printf("Student's student number : ");
                    gets(s.number);
                    z=check_valid_studNum(l,s);
                    x=found_studNums(l,s);
                    if(!z) {
                        printf("\nInvalid student number input.\n");
                        system("pause");
                    }

                    else if(x) {//x means tells a duplicate of the student number exists in the database
                        printf("\nStudent Number already exists in the database.\n");
                        system("pause");
                    }

                }while(!z || x);

                do
                {
                    printf("Program : ");
                    gets(s.program);
                    z=check_progam(s);
                    if(!z) {
                        printf("\nInvalid program input.\n");
                        system("pause");
                    }
                } while(!z);

                do
                {
                    z=0;
                    printf("Student's year level : ");
                    scanf("%d",&s.yr);
                    z=check_valid_level(s);
                    if(!z) {
                        printf("\nInvalid year level format.\n");
                        system("pause");
                    }

                } while(!z);

                do
                {
                    z=0;
                    printf("Student's gender : ");
                    fflush(stdin);
                    scanf("%c",&s.gender);
                    z=check_valid_gender(s);
                    if(!z) {
                        printf("\nInvalid gender format.\n");
                        system("pause");
                    }

                } while(!z);

                append(&l,s);
                printf("\nStudent successfully enrolled in CMSC21.\n");
                system("pause");
                break;

            case 2:
                system("cls");
                printf("Drop a Student\n");
                printf("Enter student number : ");
                fflush(stdin);
                gets(s.number);
                x=found_studNums(l,s);

                if(!x) {
                    printf("Student number %s does not exist in the database.\n",s.number);
                    system("pause");
                    break;
                }

                i=give_pos(l,s);
                i=deleteItem(&l,i);
                printf("\n%s is officially dropped from CMSC21.\n",s.number);
                system("pause");
                break;

            case 3:
                printf("Student list sorted by order of Student Number.\n");
                sort_snum(l);
                system("pause");
                break;

            case 4:
                printf("Student list sorted by order of Family Name\n");
                sort_lname(l);
                system("pause");
                break;

            case 5:
                system("cls");
                printf("The following students are currently enrolled in CMSC21 : \n\n");
                display(l);
                printf("\n");
                system("pause");
                break;

            case 6:
                system("cls");
                printf("Display all Students by Year Level \n");
                printf("Enter student year level : ");
                scanf("%d",&s.yr);
                display_by_year(l,s);
                printf("\n");
                system("pause");
                break;

            case 7:
                printf("Student Search \n");
                printf("Please enter student family name for search : ");
                scanf("%s",s.lname);
                student_search(l,s);
                system("pause");
            default:
                break;
        }
    }
    while(c!=8);
    emptyList(&l);
    return 0;
}

void display(list l) {
    int i;
    for(i=1; i<=l.size;i++){
        printf("%d. ",i);
        displayStudent(getItem(l,i));
    }
}

void displayStudent(student s) {
    printf("Student Number : %s\n",s.number);
    printf("Student Full Name : %s %s %s\n",s.fname,s.mname,s.lname);
    printf("Student Program & Year Level : %s %d\n\n",s.program,s.yr);
}

int check_valid_studNum(list l, student s) {//checks validity of studnum
    int i=0, x=0;

    if(s.number[0]=='\0')
        return 0;

    for(;s.number[i]!='\0';i++){
        if(!((s.number[i]>='0' && s.number[i]<='9') || s.number[4]=='-' || s.number[10]=='\0'))
           return 0;
    }
    return 1;
}

int found_studNums(list l, student s) {//traverse the list while checking the studNums
    int i=0;
    node *tmp = l.head;
    while(tmp!=NULL) {
        if(strcmp(tmp->item.number,s.number)==0)
            return 1;
        tmp = tmp->next;
    }
    return 0;
}

int give_pos(list l, student s) {
    int pos=1;

    node *tmp = l.head;
    while(strcmp(tmp->item.number,s.number)!=0){
        tmp = tmp->next;
        pos++;
    }
    return pos;
}

int check_valid_first_name(student s) {
    int i=0, size=0;

    if(s.fname[0]=='\0') {
        return 0;
    }

    for(;s.fname[i]!='\0';i++)//check if student name contains unnecessary characters
    {
        if(!((s.fname[i]>='A' && s.fname[i]<='Z') || (s.fname[i]>='a' && s.fname[i]<='z') || s.fname[i]=='-')) {
            return 0;
        }
    }

    return 1;
}

int check_valid_middle_name(student s)//check if student name contains unnecessary characters
{
    int i=0;

    if(s.mname[0]=='\0') {
        return 0;
    }

    for(;s.mname[i]!='\0';i++)
    {
        if(!((s.mname[i]>='A' && s.mname[i]<='Z' || s.mname[i]>='a' && s.mname[i]<='z') || s.mname[i]=='-')) {
            return 0;
        }
    }

    return 1;
}

int check_valid_family_name(student s)//check if student name contains unnecessary characters
{
    int i=0;

    if(s.lname[0]=='\0'){
        return 0;
    }

    for(;s.lname[i]!='\0';i++) {
        if(!((s.lname[i]>='A' && s.lname[i]<='Z' || s.lname[i]>='a' && s.lname[i]<='z') || s.lname[i]=='-')) {
            return 0;
        }
    }

    return 1;
}

int check_valid_level(student s) { //check if student level have not exceeded maximum residency
    if(!(s.yr>=0 && s.yr<=6)) {
        return 0;
    }
    return 1;
}

int check_valid_gender(student s) { //check if gender is M, F, L, G, B, or T
    if(!(s.gender=='M' || s.gender=='F' || s.gender=='L' || s.gender=='G' || s.gender=='B' || s.gender=='T' )) {
        return 0;
    }

    if(s.gender>='0' && s.gender <='9' || s.gender=='\0' ) {
        return 0;
    }

    return 1;
}

int check_progam(student s) {
    int i=0;

    if(s.program[0]=='\0') {
        return 0;
    }

    for(; s.program[i]!='\0'; i++) {
        if(!((s.program[i]>='A' && s.program[i]<='Z') || (s.program[i]>='a' && s.program[i]<='z'))){
            return 0;
        }

        if(s.program[i]>='0' && s.program[i]<='9') {
            return 0;
        }
    }

    return 1;
}

void display_by_year(list l, student s) {//Assume that the maximum yr level is 6
    node *tmp = l.head;
    int i=1;

    printf("Year Level : %d.\n\n",s.yr);
    while(tmp!=NULL){
        if(tmp->item.yr==s.yr){
            displayStudent(getItem(l,i));
        }
        tmp = tmp->next;
        i++;
    }
}

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

int getSize(list l) {//helper function
    node *tmp = l.head;
    int size = 0;
    while(tmp!=NULL){
        tmp = tmp->next;
        size++;
    }
    return size;
}
