#include<iostream>
using namespace std;

//Define a Book class
class Book{
    public:
    string tit;
    string aut;
    int ye;

    //constructor to initialise its properties (title, author, year)
    Book(string title, string author, int year){
        tit = title;
        aut = author;
        ye = year;
    }

    //method displayInfo
    void displayInfo(){
        cout<<"Title of the book: "<<tit<<endl;
        cout<<"Author of the book: "<<aut<<endl;
        cout<<"Year of the bool: "<<ye<<endl;
    }
};


int main(){

    Book b1("MAKING INDIA AWESOME", "Chetan Bhagat", 2006);
    Book b2("A MILLION MUTINIES NOW", "V.S. Naipaul", 2007);
    Book b3("A PASSAGE TO ENGLAND", "Nirad C. Chaudhuri", 2009);

    b1.displayInfo();
    b2.displayInfo();
    b3.displayInfo();
    return 0;
}