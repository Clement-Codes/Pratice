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

    int min = 0;
    for(int i = 0; i<(sizeof(array)/sizeof(array[0])); i++){
        min = i;
        for(int j = i; j<(sizeof(array)/sizeof(array[0])); j++){
            if(array[min]>array[j]){
                min = j;
            }
        }
        if(i!=min){
            int temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
    }

    cout << "After: ";
    for(int i: array){
        cout << i << ',';
    }
    cout << endl;

    return 0;
}