#include<iostream>
#include<fstream> //library that has classes to do read/write in file
using namespace std;




// Useful classes in cpp for r/w are:
// 1.fstreambase
// 2.ifstream  --derived from fstreambase class
// 3.ofstream  --derived from fstreambase class

// Inorder to work with files in cpp you have to first open it,primarily,there are 2 ways to open it-
// 1.Using the constructor
// 2.Using to memner function open() of the class

int main()
{
    ofstream out;
    out.open("file2.txt"); //open the file //this will also open and write from start
    out<<"This is Sandy!!";  //write to file
    out<<"\nThis is sassy!!";//write in next line
    out.close();

    ifstream in;
    string st,st2;
    in.open("file2.txt");
    in>>st>>st2;
    cout<<st<<st2; //will print two words Thisis

    //now to print all lines
    //will print after st2
    while(in.eof()==0)  //as soon as we reach eof it will return 0
    {
        getline(in,st);
        cout<<st<<endl;
    }
    in.close();
    return 0;
}