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

    int low = 0, high = sizeof(array)/sizeof(array[0]) - 1;
    int mid;
    while (low<=high){
        mid = low + (high - low)/2;
        if (array[mid] == x){
            found = true;
            break;
        }
        else if(array[mid] < x){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }


    cout << found;
}