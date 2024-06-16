#include <iostream>
using namespace std;


int main(){
    int size;
    
    cin >> size;
    cin.ignore();
    cout<< size;

    string* array = new string[size];

    //insertion
    for(int i =0; i< size; i++)
    {
        std::getline(cin, array[i]);
    }
    
    //traversal
    for(int i =0; i< size; i++)
    {
        cout << array[i];
    }
    
    return 0;
}