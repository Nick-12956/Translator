#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
void cs(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
int main(){
    bool error;
    int input,i,j;
    string number, text, temp;
    cs();
    cout << "-----{ Welcome to Translator }-----\n\n";
    do{
        cout << "-----< Menu >-----\n\n1. Text to Number\n2. Number to Text\n3. Exit\nEnter Option : ";
        do{
            cin >> input;
            if((input < 1)||(input > 3)) cout << "---< Wrong Option >---\nEnter Option : ";
        }while((input < 1)||(input > 3));
        switch(input) {
            case 1:
                cs();
                cout << "Text : ";
                cin.ignore();
                getline(cin, text);
                number = "";
                for(i = 0; i < text.length(); i++) {
                    j = text.at(i);
                    if(j < 10) number = number + "0" + to_string(j);
                    else number = number + to_string(j);
                }
                cout << "\n\nNumber : " << number << "\n\n---{ Press Enter to access Menu }---";
                cin.ignore();
                cs();
                break;
            case 2:
                cs();
                cout << "Number : ";
                cin.ignore();
                getline(cin, number);
                text = "";
                error = false;
                if((number.length() % 3) != 0) {
                    error = true;
                    cout << "\n\n---< Not valid Numeric Code >---";
                }
                else {
                    for(i = 0; i < number.length(); i++) {
                        if((number.at(i) < 48)||(number.at(i) > 57)) {
                            error = true;
                            cout << "\n\n---< Does not contain Number >---";
                        }
                    }
                }
                if(error == 0) {
                    for(i = 0; i < number.length(); i += 3) {
                        temp = "";
                        temp += number.at(i);
                        temp += number.at(i+1);
                        temp += number.at(i+2);
                        j = stoi(temp);
                        text = text + char(j);
                    }
                    cout << "Text : " << text;
                }
                cout << "\n\n---{ Press Enter to access Menu }---";
                cin.ignore();
                cs();
                break;
        }
    }while(input != 3);
    cout << "\n-----< Exit Successful >-----";
    return 0;
}