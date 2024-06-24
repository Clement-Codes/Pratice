#include<iostream>
using namespace std;

int main(){
    int array[5] = {0,0,0,0,0};

    for(int i = 0; i<(sizeof(array)/sizeof(array[0])); i++){
        cin >> array[i]; 
    }

    cout << "Before: ";
    for(int i: array){
        cout << i << ',';
    }

    for(int i = 0; i<(sizeof(array)/sizeof(array[0])); i++){
        int done = 1;
        for(int j = i; j<(sizeof(array)/sizeof(array[0])); j++){
            if(array[i]>array[j]){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                done = 0;
            }
        }
        if(done){
            break;
        }
    }

    cout << "After: ";
    for(int i: array){
        cout << i << ',';
    }
}