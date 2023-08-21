#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    string word,rep_word;
    cin>>word>>rep_word;
    //open a file
    ifstream in;
    in.open("rep_file.txt");
    string st;
    while(in.eof()==0)
    {
        string temp;
        getline(in,temp);
        temp+='\n';
        st+=temp;
    }
    in.close();


    //replace all words from the string
    int index;
    while((index = st.find(word)) != string::npos) 
    {
        //for each location where Hello is found
        st.replace(index, word.length(), rep_word); //remove and replace from that position
    }

    //now write to file
    ofstream out;
    out.open("rep_file.txt");
    out<<st;
    out.close();
    return 0;
}