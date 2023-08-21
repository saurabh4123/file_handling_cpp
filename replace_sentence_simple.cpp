#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    string ori_sen,rep_sen;
    getline(cin,ori_sen);
    getline(cin,rep_sen);


    //open a file
    ifstream in;
    in.open("rep_file.txt");
    string st;
    while(in.eof()==0)
    {
        string temp;
        getline(in,temp);
        if(temp==ori_sen)  //replace if temp equal to original sentence
        temp=rep_sen;
        temp+='\n';
        st+=temp;
    }
    in.close();

    //now write to file
    ofstream out;
    out.open("rep_file.txt");
    out<<st;
    out.close();
    return 0;
}