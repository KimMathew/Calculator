#include <iostream>
#include <string>
using namespace std;

struct MathExpression{ //struct
    int n1;
    int n2;
    char operation;
    int answer;
    string equationString;
};

void add(MathExpression& equation){ //assigned struct to the "equation" to have access to the variables
    equation.answer = equation.n1 + equation.n2;
    equation.equationString = to_string(equation.n1) + " + " + to_string(equation.n2) + " = " + to_string(equation.answer);
    cout << equation.equationString;
}

void substract(MathExpression& equation){
    equation.answer = equation.n1 - equation.n2;
    equation.equationString = to_string(equation.n1) + " - " + to_string(equation.n2) + " = " + to_string(equation.answer);
    cout << equation.equationString;
}

void multiply(MathExpression& equation){
    equation.answer = equation.n1 * equation.n2;
    equation.equationString = to_string(equation.n1) + " * " + to_string(equation.n2) + " = " + to_string(equation.answer);
    cout << equation.equationString;
}

void divide(MathExpression& equation, bool& isValid){
    if(equation.n2 == 0){
        cout << "The answer is undefined";
        isValid = false;
    }
    else{
        equation.answer = equation.n1 / equation.n2;
        equation.equationString = to_string(equation.n1) + " / " + to_string(equation.n2) + " = " + to_string(equation.answer);
        cout << equation.equationString;
    }
}

void isHistory(MathExpression* history[], int size){ //pointer to an array of string pointers
    cout << "\n\nHistory:" << endl;
    for(int i = 0; i < size; i++){
        cout << history[i]->equationString << " || Address: " << history[i] << endl;
    }
    cout << endl;
}

void title(){
    cout << "\t\t\t\t\t\t ++=================++" << endl;
    cout << "\t\t\t\t\t\t ||    Calculator   ||" << endl;
    cout << "\t\t\t\t\t\t ++=================++" << endl << endl;
}

int main()
{
    const int isMaxS = 9;
    MathExpression* history[isMaxS]; //array of string pointers
    int historySize = 0;
    MathExpression equation;
    string isBack;

    bool isMain = true;
    while(isMain){
        system("CLS");
        title();
        cout << "Input below the arithmetic operations you want to do:" << endl;

        while(!(cin >> equation.n1 >> equation.operation >> equation.n2)){ //error handler for invalid input of n1 and n2
            cout << "\nInvalid Input!" << endl << endl;
            cout << "Please input again: " << endl;
            cin.clear();
            while(cin.get() != '\n');
        }

        bool isSuccessful = true;
        bool isValid = true;

        switch(equation.operation){
            case '+':
                add(equation);
                break;
            case '-':
                substract(equation);
                break;
            case '*':
                multiply(equation);
                break;
            case '/':
                divide(equation, isValid);
                break;
        default:
            cout << "\nInvalid Operator! Please Try Again!"; //error handler for invalid operator inputted by the user
            isSuccessful = false;
        }

        if(isSuccessful){
            if(historySize == isMaxS){
                delete history[0];
                for(int i = 0; i < isMaxS - 1; i++){
                    history[i] = history[i + 1];
                }
                if(isValid){
                    history[isMaxS - 1] = new MathExpression(equation);
                }
        }
            else{
                if(isValid){
                    history[historySize] = new MathExpression(equation);
                    historySize++;
                }
            }
        }

        isHistory(history, historySize);

        bool isTryagain = true; //asks the user to if he/she wants to input again
        while(isTryagain){
            cout << "Do you want to try again? [Y/N]: ";
            cin >> isBack;
            if(isBack == "Y" || isBack == "y"){
                isTryagain = false;
            }
            else if(isBack == "N" || isBack == "n"){
                isTryagain = false;
                isMain = false;
            }
            else{
                cout << "\nInvalid Input! Please Try Again!" << endl << endl; //error handler for invalid input
            }
        }
    }
    return 0;
}
