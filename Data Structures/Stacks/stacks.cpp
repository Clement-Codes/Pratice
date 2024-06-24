#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<int> s ;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<< s.top();
    s.pop();
    cout<<"length: "<<s.size()<<endl;
    cout<<"empty: "<<s.empty()<<endl;
    while(s.empty()!=1){
        cout<< s.top();
        s.pop();
    }
    return 0;
}