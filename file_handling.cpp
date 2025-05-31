/*
Copy the contents of one text file to another file, after removing all whitespaces.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    string newline;
    
    ifstream inputFile("test.txt");

    if(inputFile.is_open()){

        string line;
    while (getline(inputFile, line))
    {
        cout << line << "/n";

        for(int i = 0; i< line.length(); ++i){
            if(line[i] != ' '){
               newline+= line[i];
            }
        }
    }

    cout << "after removing the white space: "<< newline << endl;
    inputFile.close();
}

else{
    cout<<"it is not open";
}


ofstream outputFile("test_copy.txt");
if(outputFile.is_open()){
    outputFile << newline; 
    outputFile.close();
    cout<< "copied to the file 'test_copy.txt' ";
}
else{
    cout<<"error opening the file";
}

return 0;
}