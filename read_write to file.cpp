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
    //open using constructor
    ofstream out("file.txt");

    //write to that file
    out<<"Saurabh is a cool dude!!!";
    //now inorder to read in next code lines we must first close the file,since the file is locked by that stream until it is closed. This lock prevents other operations, like reading from the same file, from occurring simultaneously.
    out.close();

    //reading from that file
    string st="";
    ifstream in("file.txt");
    in>>st; //reads only first character till blank
    getline(in,st);
    cout<<st<<endl;//prints "is a cool dude!!!" why?? its bcz in>>st changes file descriptor to blank after Saurabh and " is a cool dude!!!" is printed since getline is used now to get every line you must do getline again and again.
    in.close();

    //since we were overwriting from start in files,if we want to append in it without overwriting previous content use ios::app,open in append mode
    ofstream out1("file.txt",ios::app);
    out1<<"Saurabh is from INDIA!!";
    out1<<"\nSaurabh is a foodie!!"; //to append from new line
    out1.close();


    //now read whole file using getline
    ifstream in1("file.txt");
    string line;
    while (getline(in1, line)) //getline() function in C++ returns false when it reaches the end of the file (EOF), indicating that there are no more lines to read
    {
        cout << line << endl;
    }
    return 0;
}