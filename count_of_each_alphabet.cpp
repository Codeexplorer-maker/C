#include <iostream>
using namespace std;

int count(string, char);

int main(int argc, char* argv[]) {
    string str;
    if(argc >1)
        str = argv[1];

    for (char ch='a' ;ch<='z'; ch++){
        cout<<ch<<": "<<count(str,ch)<<"\n";
    }
    return 0; 
}

int count(string str, char ch){
    int count=0;
    for(int i = 0; i<str.length(); i++) {
        if(ch == str[i] || str[i] == ch-32)
            count++;
    }
    return count;
}

