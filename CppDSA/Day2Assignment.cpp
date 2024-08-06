// Create a function that will return the sum of 3 numbers
// create a function which will retrun sqrt/square of a number

#include<bits/stdc++.h>
using namespace std;

int sum(int a, int b, int c){
    return a+b+c;
}

int SquareRoot(int a){
    return sqrt(a);
}

int main(){

    cout<<"The sum of Three number is: "<<endl;
    cout<<sum(7, 3, 4)<<endl;
    cout<<"The square root of the number is: "<<endl;
    cout<<SquareRoot(8);
    return 0;
}