#include <stdio.h>
#include <string.h>
#include "list.h"

void display(list);
void displayStudent(student);

int main(){
    list l;
    student s,t,u,v,w,x,h;
    int c = 1;
    initList(&l);
    do{
        scanf("%s",&s.number);
        scanf("%s",&s.fname);
        scanf("%s",&s.program);
        fflush(stdin);
        scanf("%c",&s.gender);

        scanf("%d",&s.yr);

        /*if(c==3)
            insertFront(&l,s);
        else
        if(c==5)
            insert(&l,s,3);
        else*/
            append(&l,s);
        printf("size---->%d\n",l.size);
        c++;
        display(l);
    }while(c<=5);
    emptyList(&l);
    display(l);

    return 0;
}

void display(list l){
    int i;
    for(i=1; i<=l.size;i++)
        displayStudent(getItem(l,i));
}

void displayStudent(student s){
    printf("%s\n",s.number);
    printf("%s\n",s.fname);
    printf("%s %d\n",s.program,s.yr);
}
