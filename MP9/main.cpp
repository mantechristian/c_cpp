/*I, Christian R. Mante, do solemnly swear that I have made this MP all by myself
This program has a class named Ballpen which emulates the function of a ballpen in real life*/

#include "mante9.cpp"

main(){
    string s, b;
    int c;
    Ballpen pen;
    int choice = 0, erase = 0, defective = 0;
    defective = defective_pen();
    system("color F9");

    do{
        system("cls");
        float ink = pen.get_inkLevel();
        cout << "\n--------------- : Pen Writing Simulator : ---------------" << endl;
        cout << "Using " << pen.getbrand() << " with " << pen.getcolor() << " ink.";
        cout << "\nYou wrote : ";
        show(s);
        cout << "\n\n\n\n\n";
        cout << "\n\t1.)Write\n\t2.)Refill\n\t3.)Erase\n\t4.)Create a pen\n\t5.)Exit"
                "\n\tCurrent Ink-Level : " << fixed << showpoint << setprecision(2)  << ink <<
                "\n\tChoice : ";
        cin >> choice;
        switch(choice){
            case 1:
                if(defective){
                    cout<< endl << "*System : Defective pen*" << endl;
                    getch();
                    break;
                }
                cout << "\nType in your message : ";
                cin.ignore();
                getline(cin,s,'\n');
                cout << "You wrote : ";
                pen.write(s);
                cout << endl;
                getch();
                break;

            case 2:
                cout << "\nInk Color of your choice : " << endl;
                cout << "\n\t1.Red\n\t2.Blue\n\t3.Yellow" << endl;
                //9 - light blue, C - light red, 6 - yellow
                cin >> choice;
                pen.setcolor(choice);
                pen.refill();
                cout << "\nPen ink-level is back to 20.00\n" << endl;
                defective = defective_pen();
                getch();
                break;

            case 3:
                if(defective){
                    cout<< endl << "*System : Defective pen*" << endl;
                    getch();
                    return 0;
                }
                cout << "\nEnter number of digits you would like to erase : " << endl;
                cin >> erase;
                s = pen.erase(erase,s);
                getch();
                break;

            case 4:
                cout << "\nCreate a pen : "<<endl;
                cout << "\nEnter pen brand : ";
                cin.get();
                getline(cin,b,'\n');
                cout << "Choose pen color : \n1.)Red\n2.)Blue\n3.)Yellow\nChoice : ";
                cin >> c;
                //Ballpen(b,c);
                pen.refill();
                pen.setbrand(b);
                pen.setcolor(c);
                cout << "Pen created." << "\nBrand : " << pen.getbrand() << "\nInk color : " << pen.getcolor() << endl;
                defective = defective_pen();
                getch();
                break;

            default:
                break;
        }
    }while(choice!=5);
    return 0;
}
