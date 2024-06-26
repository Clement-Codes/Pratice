#include<iostream>
#include<cmath>
using namespace std;


void merge(int array [] , int left, int middle, int right){
    int i = left, j = middle;
    while (i<(left+middle-1) && j<(middle+right)){
        if(array[i] > array[j]){
            int temp = array[j];
            array[j] = array[i];
            array[i] = temp;
            j++;
        }
        else{

            i++;
        }
    }
}

void mergesort(int array [] , int left, int right){

    if (left >= right) {
        return;
    }
    int mid = left + (right - left)/2;

    mergesort(array, left, mid);
    mergesort(array, mid+1, right);

    merge(array, left, mid, right);
}


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

    mergesort(array, 0 , sizeof(array)/sizeof(array[0]));

    cout << "After: ";
    for(int i: array){
        cout << i << ',';
    }
    cout << endl;

    return 0;
}