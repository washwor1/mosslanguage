// Program to encode and decode the moss language.(the code is a secret though!!)

#include <iostream>
#include <string>
#include <map>
#include <moss.h>

using namespace std;

//function that decodes the moss speak
int decode(string &input);

//function that encodes the moss speak
int encode(string &input);

//function that prints out the usage
void help();

int main() {
    map<int,char> conversions;
    bool exit = false;
    string input;

    conversions.insert(make_pair(0,'*'));
    conversions.insert(make_pair(1,'.'));
    conversions.insert(make_pair(2,','));
    conversions.insert(make_pair(3,'\''));
    conversions.insert(make_pair(4,'\"'));
    conversions.insert(make_pair(5,':'));
    conversions.insert(make_pair(6,'#'));
    conversions.insert(make_pair(7,'-'));

    help();

    while(!exit && getline(cin,input)) {
        if(input[0] == 'e') encode(input);
        else if (input[0] == 'd') decode(input);
        else help();
    }
}

void help() {
    cout << "Usage:[d,e] \"String of text\"\n\ne - encode\nd - decode\n";
}