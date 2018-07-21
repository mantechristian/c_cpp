#include <stdlib.h>
#include <string.h>
typedef struct{
    char number[11];
    char fname[30];
    char mname[30];
    char lname[30];
    char program[30];
    int yr;
    char gender;
}student;

typedef struct myNode{
    student item;
    struct myNode *next;
}node;

typedef struct{
    node *head, *tail;
    int size;
}list;

void init(node *n, student x){

    /*strcpy(n->item.number, x.number);
    strcpy(n->item.name, x.name);
    strcpy(n->item.program, x.program);
    n->item.gender = x.gender;
    n->item.yr = x.yr;*/

    memcpy(&n->item, &x,sizeof(student));
    n->next = NULL;
}

void initList(list *l){
    l->head = l->tail = NULL;
    l->size = 0;
}

void append(list *l, student x){
    node *n = malloc(sizeof(node));
    init(n,x);

    if(l->size==0)
        l->head = l->tail = n;
    else{
        l->tail->next = n;
        l->tail = n;
    }
    l->size++;
}

void insertFront(list *l, student x){
    node *n = malloc(sizeof(node));
    init(n,x);
    if(l->size == 0)
        l->head = l->tail = n;
    else{
        n->next = l->head;
        l->head = n;
    }
    l->size++;
}

int insert(list *l, student x, int pos){
    int p;
    node *n, *tmp;
    if(pos<1 || pos>l->size+1)
        return 0;
    else{
        if(pos==1)
            insertFront(l,x);
        else
        if(pos==l->size+1)
            append(l,x);
        else{
            n = malloc(sizeof(node));
            init(n,x);
            tmp = l->head;
            p = 1;
            while(p < pos-1){
                tmp = tmp->next;
                p++;
            }
            n->next = tmp->next;
            tmp->next = n;
            l->size++;
        }
        return 1;
    }
}

int deleteItem(list *l, int pos){
    node *tmp, *del;
    int p;
    if(pos<1 || pos>l->size)
        return 0;

    if(pos==1){
        del = l->head;
        l->head = del->next;
    }
    else{
        tmp = l->head;
        p = 1;

        while(p < pos - 1){
            tmp = tmp->next;
            p++;
        }
        del = tmp->next;
        tmp->next = del->next;

        if(del == l->tail)
            l->tail = tmp;
    }
    del->next = NULL;
    free(del);
    l->size--;
    return 1;
}

student getItem(list l, int pos){
    node *tmp = l.head;
    int p = 1;
    while(p < pos){
        tmp = tmp->next;
        p++;
    }
    return tmp->item;
}

void emptyList(list *l){
    while(l->size!=0)
        deleteItem(l,1);
}
