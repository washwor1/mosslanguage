// Program to encode and decode the moss language.(the code is a secret though!!)

#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

//function that decodes the moss speak
int decode(string &input,const map<char,char> &convert);

//function that encodes the moss speak
int encode(string &input,const map<char,char> &convert);

//function that prints out the usage
void help();

int main() {
    map<char,char> encodev;
    map<char,char> decodev;
    string input;

    encodev.insert(make_pair('0','*'));
    encodev.insert(make_pair('1','.'));
    encodev.insert(make_pair('2',','));
    encodev.insert(make_pair('3','\''));
    encodev.insert(make_pair('4','\"'));
    encodev.insert(make_pair('5',':'));
    encodev.insert(make_pair('6','#'));
    encodev.insert(make_pair('7','-'));

    decodev.insert(make_pair('*','0'));
    decodev.insert(make_pair('.','1'));
    decodev.insert(make_pair(',','2'));
    decodev.insert(make_pair('\'','3'));
    decodev.insert(make_pair('\"','4'));
    decodev.insert(make_pair(':','5'));
    decodev.insert(make_pair('#','6'));
    decodev.insert(make_pair('-','7'));

    cout<<'\n';
    help();

    while(getline(cin,input)) {
        if(input[0] == 'e') encode(input,encodev);
        else if (input[0] == 'd') decode(input,decodev);
        else help();
    }
}

void help() {
    cout << "Usage:[d,e] \"String of text\"\n\ne - encode\nd - decode\n\n";
}

int encode(string &input,const map<char,char> &convert) {
    string output,tmp = "";
    stringstream ss;
    ss.fill('0');
    ss.width(3);

    for (int i = 2;i<input.size();i++) {
        ss << oct << int(input[i]);
        tmp += ss.str();
        ss.str("");
        ss.fill('0');
        ss.width(3);
    }
    
    for (int i = 0; i < tmp.size(); i++) {
        output += convert.find(tmp[i])->second;
    }
    cout<<output<<'\n';
    return 0;
}

int decode(string &input,const map<char,char> &convert) {
    string output, tmp = "";
    int bruh;

    for(int i = 2; i<input.size();i+=3) {
        tmp+=convert.find(input[i])->second;
        tmp+=convert.find(input[i+1])->second;
        tmp+=convert.find(input[i+2])->second;
        bruh = stoi(tmp,0,8);
        output+=bruh;
        tmp="";
    }
    cout << output << '\n';

    return 0;
}