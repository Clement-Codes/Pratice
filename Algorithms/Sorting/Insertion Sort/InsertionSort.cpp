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
    cout << endl;

    for(int i = 0; i<(sizeof(array)/sizeof(array[0])); i++){
        int key = i;
        int j = key - 1;
        while(j>=0 && array[key]<array[j]){
            int temp = array[key];
            array[key] = array[j];
            array[j] = temp;
            key = j;
            j -= 1;
        }
    }

    cout << "After: ";
    for(int i: array){
        cout << i << ',';
    }
    cout << endl;

    return 0;
}