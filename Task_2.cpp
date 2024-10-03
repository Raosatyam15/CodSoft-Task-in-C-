#include<iostream>
#include<math.h>
using namespace std;

int main(){
    double num1,num2;
    char operation;
    cout<<"Welcome to the Simple Calculator!"<<endl;
    cout<<"Enter the first number: ";
    cin>>num1;
    cout<<"Enter the second number: ";
    cin>>num2;
    cout<<"Enter the operation you want to perform (+, -, *, /): ";
    cin>>operation;

    switch(operation){
        case '+':
          cout<<"Result: "<<num1<<" + "<<num2<<" = "<<(num1 + num2)<<endl;
          break;
        case '-':  
          cout<<"Result: "<<num1<<" - "<<num2<<" = "<<(num1 - num2)<<endl;
          break;
        case '*':  
          cout<<"Result: "<<num1<<" * "<<num2<<" = "<<(num1 * num2)<<endl;
          break;
        case '/':
          if(num2 != 0){
          cout<<"Result: "<<num1<<" / "<<num2<<" = "<<(num1 / num2)<<endl;
          }
          else{
            cout<<"Error: Division by zero is undefined."<<endl;
          }
          break;
        default:
            cout<<"Error: Invalid operation."<<endl;
          break;
    }
    return 0;
}