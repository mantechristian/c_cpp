/*I, Christian R. Mante, upon my honor, do solemnly swear that I have made this MP all by myself.
  This program implements the student enrollment system using linked lists.
*/

#include <stdio.h>
#include <string.h>
#include "list.h"

void display(list l);
void displayStudent(student s);
void display_by_year(list l, student s);
int check_studNum(list l, student s);
int give_pos(list l, student s);
int check_valid_first_name(student s);
int check_valid_middle_name(student s);
int check_valid_family_name(student s);
int check_valid_level(student input);
int check_valid_gender(student input);
int check_studNum2(list l, student s);

main()
{
    list l;
    int c=0, i=0, z=0;
    student s;

    initList(&l);
    do
    {
        system("cls");
        fflush(stdin);
        printf("\n\t1. Enroll a Student\n\t2. Drop a Student\n\t3. Display all Students\n\t4. Display all Students by year\n\t5. Exit");
        scanf("%d",&c);
        switch(c)
        {
            case 1://Enrolls student having a valid student number and contains name, program, year level, and gender
                system("cls");
                fflush(stdin);
                printf("Please fill in the appropriate info:\n");
                do
                {
                    printf("Student's First name : ");
                    gets(s.fname);
                    z=check_valid_first_name(s);
                }while(!z);

                do
                {
                    z=0;
                    printf("Student's Middle name : ");
                    gets(s.mname);
                    z=check_valid_middle_name(s);
                }while(!z);

                do
                {
                    z=0;
                    printf("Student's Family name : ");
                    gets(s.lname);
                    z=check_valid_family_name(s);
                }while(!z);

                printf("Student's Full Name is : %s %s %s\n",s.fname,s.mname,s.lname);

                do
                {
                    z=0;
                    printf("Student's student number : ");
                    gets(s.number);
                    z=check_studNum(l,s);
                    if(!z)
                        printf("Student number already exists in the database.\n");
                    else if(s.number[0]=='\0')
                        printf("Invalid student number input.\n");
                }while(!z || s.number[0]=='\0');

                do
                {
                    printf("Program : ");
                    gets(s.program);
                    if(s.program[0]=='\0'){
                        printf("Invalid student program input.\n");
                        z=0;
                    }
                    else
                        z=1;
                }while(!z);

                do
                {
                    z=0;
                    printf("Student's year level : ");
                    scanf("%d",&s.yr);
                    z=check_valid_level(s);
                }while(!z);

                do
                {
                    z=0;
                    printf("Student's gender : ");
                    fflush(stdin);
                    scanf("%c",&s.gender);
                    z=check_valid_gender(s);
                }while(!z);
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
                z=check_studNum2(l,s);
                if(!z){
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
                system("cls");
                printf("The following students are currently enrolled in CMSC21 : \n\n");
                display(l);
                printf("\n");
                system("pause");
                break;

            case 4:
                system("cls");
                printf("Display all Students by Year Level \n");
                printf("Enter student year level : ");
                scanf("%d",&s.yr);
                display_by_year(l,s);
                printf("\n");
                system("pause");
                break;

            default:
                break;
        }
    }
    while(c!=5);
    emptyList(&l);
    return 0;
}

void display(list l){
    int i;
    for(i=1; i<=l.size;i++){
        printf("%d. ",i);
        displayStudent(getItem(l,i));
    }
}

void displayStudent(student s){
    printf("Student Number : %s\n",s.number);
    printf("Student Full Name : %s %s %s\n",s.fname,s.mname,s.lname);
    printf("Student Program & Year Level : %s %d\n\n",s.program,s.yr);
}

int check_studNum(list l, student s){
    int i=0;
    node *tmp = l.head;
    while(tmp!=NULL){
        if(strcmp(tmp->item.number,s.number)==0)
            return 0;
        for(;s.number[i]!='\0';i++){
            if(s.number[4]!='-')
            {
                printf("\nInvalid student student number input.\n");
                system("pause");
                return 0;
            }
            else if(!(s.number[i]>='0' || s.number[i]<='9'))
            {
                printf("\nInvalid student student number input.\n");
                system("pause");
                return 0;
            }
            else if(s.number[10]!='\0' || s.number[i]=='\0')
            {
                printf("\nInvalid student student number input.\n");
                system("pause");
                return 0;
            }
        }
        tmp = tmp->next;
    }
    return 1;
}

int give_pos(list l, student s){
    int pos=1;
    node *tmp = l.head;
    while(strcmp(tmp->item.number,s.number)!=0){
        tmp = tmp->next;
        pos++;
    }
    return pos;
}

int check_valid_first_name(student s)
{
    int i=0, size=0;

    for(;s.fname[i]!='\0';i++)///check if student name contains unnecessary characters
    {
        if(!((s.fname[i]>='A' && s.fname[i]<='Z') || (s.fname[i]>='a' && s.fname[i]<='z') || s.fname[i]==' ' || s.mname[i]=='-' || s.fname[0]!='\0'))
        {
            printf("\nInvalid student first name input.\n");
            system("pause");
            return 0;
        }
    }
    return 1;
}

int check_valid_middle_name(student s)///check if student name contains unnecessary characters
{
    int i=0;

    for(;s.mname[i]!='\0';i++)
    {
        if(!((s.mname[i]>='A' && s.mname[i]<='Z') || (s.mname[i]>='a' && s.mname[i]<='z') || s.mname[i]==' ' || s.mname[i]=='-' || s.mname[0]!='\0'))
        {
            printf("\nInvalid student middle name input.\n");
            system("pause");
            return 0;
        }
    }
    return 1;
}

int check_valid_family_name(student s)///check if student name contains unnecessary characters
{
    int i=0;

    for(;s.lname[i]!='\0';i++)
    {
        if(!((s.lname[i]>='A' && s.lname[i]<='Z') || (s.lname[i]>='a' && s.lname[i]<='z') || s.lname[i]==' ' || s.lname[i]=='-' || s.mname[0]!='\0'))
        {
            printf("\nInvalid student family name input.\n");
            system("pause");
            return 0;
        }
    }
    return 1;
}

int check_valid_level(student s)///check if student level have not exceeded maximum residency
{
    if(!(s.yr>=0 && s.yr<=6))
    {
        printf("\nInvalid student year level input.\n");
        system("pause");
        return 0;
    }
    return 1;
}

int check_valid_gender(student s)///check if gender is M, F, L, G, B, or T
{
    if(!(s.gender=='M' || s.gender=='F' || s.gender=='L' || s.gender=='G' || s.gender=='B' || s.gender=='T' || s.gender!='\0'))
    {
        printf("\nInvalid student gender input.\n");
        system("pause");
        return 0;
    }

    return 1;
}

void display_by_year(list l, student s){//Assume that the maximum yr level is 6
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

int check_studNum2(list l, student s){
    int i=0;
    node *tmp = l.head;
    while(tmp!=NULL){
        if(strcmp(tmp->item.number,s.number)==0)
            return 1;
        for(;s.number[i]!='\0';i++){
            if(s.number[4]!='-')
            {
                printf("\nInvalid student student number input.\n");
                system("pause");
                return 0;
            }
            else if(!(s.number[i]>='0' || s.number[i]<='9'))
            {
                printf("\nInvalid student student number input.\n");
                system("pause");
                return 0;
            }
            else if(s.number[10]!='\0' || s.number[i]=='\0')
            {
                printf("\nInvalid student student number input.\n");
                system("pause");
                return 0;
            }
        }
        tmp = tmp->next;
    }
}
