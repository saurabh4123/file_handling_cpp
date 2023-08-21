#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int main()
{
    string word,rep_word;
    cin>>word>>rep_word;
    //open a file
    ifstream in;
    in.open("rep_file.txt");
    vector<string> vst;
    while(in.eof()==0)
    {
        string temp;
        getline(in,temp);
        vst.push_back(temp);
    }
    in.close();
    int index;
    for(int i=0;i<vst.size();i++)
    {
        string st=vst[i];
        while((index = st.find(word)) != string::npos) 
        {
            //for each location where Hello is found
            st.replace(index, word.length(), rep_word); //remove and replace from that position
        }
        vst[i]=st+'\n';
    }

    //now write to file
    ofstream out;
    out.open("rep_file.txt");
    for(auto i:vst)
    out<<i;
    out.close();
    return 0;
}