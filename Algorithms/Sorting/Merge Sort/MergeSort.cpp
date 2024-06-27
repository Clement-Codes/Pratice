#include<iostream>
#include<cmath>
#include<vector>
using namespace std;


void merge(int array [] , int left, int middle, int right){
    int leftSize = middle - left + 1;
    int rightSize = right - middle;

    vector<int> leftArr(leftSize), rightArr(rightSize);
    
    int l = 0;
    int r = 0;

    for(int i=left; i<=middle;i++){
        leftArr[l] = array[i];
        l++;

        cout << array[i];
    }

    cout << endl;

    for(int i=middle+1; i<=right;i++){
        rightArr[r] = array[i];
        r++;
        cout << array[i];
    }

    int ll = 0, rr = 0, cc = left;

    while(ll<leftSize && rr<rightSize){
        if(leftArr[ll] <= rightArr[rr]){
            array[cc]=leftArr[ll];
            ll++;
        }
        else if(leftArr[ll] >= rightArr[rr]){
            array[cc]=rightArr[rr];
            rr++;
        }
        cc++;
    }

    while(ll<leftSize){
        array[cc]=leftArr[ll];
        ll++;
        cc++;
    }

    while(rr<rightSize){
        array[cc]=rightArr[rr];
        rr++;  
        cc++;
    }

    
    // cout << ' ' << left <<  ' ' << middle <<  ' ' << right <<  ' ' << leftSize <<  ' ' << rightSize << endl;
    // int i = left, j = middle;
    // while (i<(left+middle-1) && j<(middle+right)){
    //     if(array[i] > array[j]){
    //         int temp = array[j];
    //         array[j] = array[i];
    //         array[i] = temp;
    //         j++;
    //     }
    //     else{

    //         i++;
    //     }
    // }
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

    mergesort(array, 0 , sizeof(array)/sizeof(array[0]) - 1);

    cout << "After: ";
    for(int i: array){
        cout << i << ',';
    }
    cout << endl;

    return 0;
}