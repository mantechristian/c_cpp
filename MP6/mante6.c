//I, Christian R. Mante, upon my honor, do solemnly swear that I have made this MP all by myself.
//This program is an implementation of a horoscope using file handling

#include <stdio.h>
#include <stdlib.h>

typedef struct user{
    int day;
    int month;
    char zodiac[20];
    char date[15];
}user;

int check_birth(user u);
int getMonth(user u);
int getDay(user u);
int horoscope(user u);
void displayZodiac(int x);

main(){
    FILE *fp;
    char arr[12][500], line[500];
    int isValid=0, x=0, count=0, choice=0, y=0, prev=0, n=0;
    user u;

    do{
        do{
            printf("\n\n\n\t\tWELCOME TO FORTUNE TELLER SIMULATOR v1.0\n\t\t");
            system("pause");
            printf("\n\nNow tell me, when were you born?(I'm expecting you to enter a complete date.)\n");
            scanf("%s",u.date);
            isValid = check_birth(u);
            system("cls");
        }while(!isValid);

        u.day = getDay(u);//extracts birth date and converts it to integer
        u.month = getMonth(u);//extracts birth month and convers it to integer

        if(y%5==0 && y!=0)//prints the first line corresponding to the zodiac
            n=0;

        prev=x;
        x = horoscope(u);//return values signifies zodiac sign
        displayZodiac(x);//displays corresponding zodiac sign
        if(x==prev && y%5!=0)
            n+=12;//adds variations of input for the corresponding zodiac sign
        y++;//every five prints of the same zodiac sign, return to the first one
        fp = fopen("data.fort.txt", "r");//opens data.fort.txt

        if(fp == NULL)//if file isn't found. display error message
            printf("\n\nOh no! Such file does not exist.\n");

        while (fgets(line, sizeof line, fp) != NULL){//prints out specific line from data.fort.txt corresponding to zodiac sign
            if (count == x-1+n)//prints line corresponding to zodiac sign, x-1 since we started with 1 in the zodiac list
            {
                printf("\n\n%s\n\n", line);
                break;
            }
            count++;//increment count if line does not match corresponding zodiac sign return number
        }
        count=0;
        fclose(fp);
        fp = fopen("data.in.txt", "a");//appends date to file.

        if (fp == NULL)
            printf("\n\nOh no! Such file does not exist.\n");

        fprintf(fp, "%s\n", u.date);
        fclose(fp);
        printf("Type in any number to re-use the program. Otherwise, press zero '0'\n");
        scanf("%d",&choice);
        system("cls");
    }while(choice);//if choice is 0, leave, else redo loop
    return 0;
}

int check_birth(user u){//valid inputs consist of numerical digits and front slashes '/'
    int i=0;
    for(;u.date[i]!='\0';i++){
        if(!(u.date[i]>='0' && u.date[i]<='9' || u.date[i]=='/' || u.date[0]!='\0')){
            printf("\n\nI'm sorry, but the date you have entered is unknown!\n\n");
            system("pause");
            return 0;
        }
    }
    if(!((getDay(u)>=1 && getDay(u)<=31) && (getMonth(u)>=1 && getMonth(u)<=12))){
        printf("\n\nI'm sorry, but the date you have entered is unknown!\n\n");
        system("pause");
        return 0;
    }
    return 1;
}

int getMonth(user u){
    int i=0,num=0;

    for(;u.date[i]!='/';i++){
        num=num+(u.date[i]-'0');
        if(u.date[i+1]=='/')
            return num;
        num*=10;
    }
    return num;
}

int getDay(user u){
    int i=0, num=0, count=0;

    for(;count!=2;i++){
        if(u.date[i]=='/')
            count++;
    }

    if(u.date[i-2]!='/'){
        num=u.date[i-3]-'0';
        num*=10;
        num=num+(u.date[i-2]-'0');
    }

    else
        num=u.date[i-1]-'0';
    return num;
}

int horoscope(user u){
    if(u.month == 1 && u.day>=20 || u.month == 2 && u.day<=18)
        return 1;
    else if(u.month == 2 && u.day>=19 || u.month == 3 && u.day<=20)
        return 2;
    else if(u.month == 3 && u.day>=21 || u.month == 4 && u.day<=19)
        return 3;
    else if(u.month == 4 && u.day>=20 || u.month == 5 && u.day<=20)
        return 4;
    else if(u.month == 5 && u.day>=21 || u.month == 6 && u.day<=20)
        return 5;
    else if(u.month == 6 && u.day>=21 || u.month == 7 && u.day<=22)
        return 6;
    else if(u.month == 7 && u.day>=23 || u.month == 8 && u.day<=22)
        return 7;
    else if(u.month == 8 && u.day>=23 || u.month == 9 && u.day<=22)
        return 8;
    else if(u.month == 9 && u.day>=23 || u.month == 10 && u.day<=22)
        return 9;
    else if(u.month == 10 && u.day>=23 || u.month == 11 && u.day<=21)
        return 10;
    else if(u.month == 11 && u.day>=22 || u.month == 12 && u.day<=21)
        return 11;
    else if(u.month == 12 && u.day>=22 || u.month == 1 && u.day<=19)
        return 12;
}

void displayZodiac(int x){

    switch(x){
        case 1:
            printf("Aquarius ( January 20 - February 18 )");
            break;
        case 2:
            printf("Pisces ( February 19 - March 20)");
            break;
        case 3:
            printf("Aries ( March 21 - April 19 )");
            break;
        case 4:
            printf("Taurus ( April 20 - May 20 )");
            break;
        case 5:
            printf("Gemini ( May 21 - June 20 )");
            break;
        case 6:
            printf("Cancer ( June 21 - July 22 )");
            break;
        case 7:
            printf("Leo ( July 23 - August 22 )");
            break;
        case 8:
            printf("Virgo ( August 23 - September 22 )");
            break;
        case 9:
            printf("Libra ( September 23 - October 22 )");
            break;
        case 10:
            printf("Scorpio ( October 23 - November 21 )");
            break;
        case 11:
            printf("Sagittarius ( November 22 - December 21 )");
            break;
        case 12:
            printf("Capricorn ( December 22 - January 19 )");
            break;
    }
    printf("\n");
    return;
}
