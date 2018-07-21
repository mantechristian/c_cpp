#include "list.h"

void list::append(student x) {
    node *n = new node;

    if(this->size==0)
        this->head = this->tail = n;
    else{
        this->tail->next = n;
        this->tail = n;
    }
    this->size++;
}

void list::insertFront(student x) {
    node *n = new node;
    if(this->size == 0)
        this->head = this->tail = n;
    else{
        n->next = this->head;
        this->head = n;
    }
    this->size++;
}


student list::getItem(int pos) {
    node *tmp;//*tmp = list.getHead();
    this->setHead(tmp);
    int p = 1;
    while(p < pos){
        tmp = tmp->next;
        p++;
    }
    return tmp->item;
}

int list::deleteItem(int pos){
    node *tmp, *del;
    int p;
    if(pos<1 || pos>size)
        return 0;

    if(pos==1){
        del = this->head;
        this->head = del->next;
    }
    else{
        tmp = this->head;
        p = 1;

        while(p < pos - 1){
            tmp = tmp->next;
            p++;
        }
        del = tmp->next;
        tmp->next = del->next;

        if(del == this->tail)
            this->tail = tmp;
    }
    del->next = NULL;
    delete(del);
    this->size--;
    return 1;
}

void list::emptyList() {
    while(this->size!=0)
        deleteItem(1);
}

void list::display() {
    int i;
    for(i=1; i<=size;i++){
        cout << i;
        displayStudent(this->getItem(i));
    }
}

void list::displayStudent(student s) {
    cout << "Student Number : " << s.number << endl;
    cout << "Student Full Name : " << s.fname << s.mname << s.lname << endl;
    cout << "Student Program & Year Level : " << s.program << s.yr << endl;
}

int list::check_valid_studNum(student s) {//checks validity of studnum
    int i=0, x=0;

    if(s.number[0]=='\0')
        return 0;

    for(;s.number[i]!='\0';i++){
        if(!((s.number[i]>='0' && s.number[i]<='9') || s.number[4]=='-' || s.number[10]=='\0'))
           return 0;
    }
    return 1;
}

int list::found_studNums(student s) {//traverse the list while checking the studNums
    int i=0;
    node *tmp;
    this->setHead(tmp);
    while(tmp!=NULL) {
        if((tmp->item.number.compare(s.number))==0)
            return 1;
        tmp = tmp->next;
    }
    return 0;
}

int list::give_pos(student s) {
    int pos=1;
    node *tmp;
    this->setHead(tmp);
    while((tmp->item.number.compare(s.number))!=0) {
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

int check_program(student s) {
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



void list::display_by_year(student s) {//Assume that the maximum yr level is 6
    node *tmp;
    this->setHead(tmp);
    int i=1;

    cout << "Year Level : " << s.yr << endl << endl;
    while(tmp!=NULL){
        if(tmp->item.yr==s.yr){
           displayStudent(this->getItem(i));
        }
        tmp = tmp->next;
        i++;
    }
}

void list::student_search(student s) {
    node *tmp;
    this->setHead(tmp);
    int found = 0;
    while(tmp!=NULL) {
        if((tmp->item.number.compare(s.number))==0) {
            found == 1;
            //system("cls");
            cout << endl << "Student Number : " << tmp->item.number << endl;
            cout << "Student Full Name : " << tmp->item.fname << tmp->item.mname << tmp->item.lname << endl;
            cout << "Student Program & Year Level : " << tmp->item.program << tmp->item.yr << endl;
            return;
        }
        tmp = tmp->next;
    }
    if(!found)
        cout << endl << "Student not found." << endl;
    return;
}

