// GCD with/without recursion

//with recursion

#include <iostream>
using namespace std;

int W_GCD(int a,int b){
    if(b==0){
        return a;
    }
    else{
        return W_GCD(b,a%b);
    }
}

int GCD(int a, int b){

    while(b!=0){
        int temp=b;
        b=a%b;
        a=temp;
    }

    return a;
}



int main(){
    int a,b;
    cout<<"enter the 1st digit: ";
    cin>>a;
    cout<<"enter the 2nd digit: ";
    cin>>b;

    int w_recursion=W_GCD(a,b);

    cout<<"GCD OF THESE 2 NUMBER WITH RECURSION IS: "<<w_recursion<<endl;

    int without_recursion=GCD(a,b);

    cout<<"GCD OF THESE 2 NUMBER WITHOUT RECURSION IS: "<<without_recursion;
    
    return 0;
}