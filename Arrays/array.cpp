#include <iostream>
using namespace std;


int main(){
    int size;
    
    cin >> size;

    cout<< size;
    
    int array[10];


    //traversal
    for(int i: array){
        cout << i;
    }
    
    return 0;
}