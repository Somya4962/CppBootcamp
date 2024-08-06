#include<iostream>
using namespace std;


int main(){
    int a, b;

    cout<<"Enter element a: "<<endl;
    cin>>a;

    cout<<"Enter element b: "<<endl;
    cin>>b;


    int sum = a+b;
    int subtract = a-b;
    int multiply = a*b;
    int divide = a/b;

   
    cout<<"The sum of a and b is "<<sum<<endl;
    cout<<"The substraction of a and b is "<<subtract<<endl;
    cout<<"The multiplication of a and b is "<<multiply<<endl;
    cout<<"The division of a and b is "<<divide<<endl;
}