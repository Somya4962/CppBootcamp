#include<iostream>
using namespace std;


int main(){

    //Declare three integer variables: a, b, and c.
    int a = 20, b = 40, c = 60;


    //Declare three pointers: p1, p2, and p3.
    //Use the pointers to assign values to a, b, and c.
    int *p1 = &a;
    int *p2 = &b;
    int *p3 = &c;


    //Assign the address of a to p1, the address of b to p2, and the address of c to p3.
    cout<<"Address of a: "<<p1<<endl;
    cout<<"Address of b: "<<p2<<endl;
    cout<<"Address of c: "<<p3<<endl;


    //Calculate the sum of a, b, and c using the pointers and store the result in a variable sum.
    int sum = *p1 + *p2 + *p3;


    //Print the values of a, b, c, and sum.
    cout<<sum<<endl;

    return 0;
}