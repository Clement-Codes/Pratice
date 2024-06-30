#include<iostream>
using namespace std;


int main(){
    int array[5] = {0,0,0,0,0};

    for(int i = 0; i<(sizeof(array)/sizeof(array[0])); i++){
        cin >> array[i]; 
    }

    int x;

    cin >> x;

    bool found = false;

    for (int i: array){
        if (x == i){
            found = true;
            break;
        }
    }

    cout << found;
}