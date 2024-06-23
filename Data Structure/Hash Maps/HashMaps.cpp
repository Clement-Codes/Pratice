#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map <char, int> hashmap;
    // insert
    hashmap['a'] = 1;
    hashmap['b'] = 2;
    hashmap['c'] = 3;

    //traverse
    for(const auto &temp: hashmap){
        cout << temp.first <<":" <<temp.second<<endl;
    }

    //search
    if(hashmap.find('b') != hashmap.end()){
        cout<<hashmap['b'];
    }
    
    //delete
    hashmap.erase('b');

    //traverse
    for(const auto &temp: hashmap){
        cout << temp.first <<":" <<temp.second<<endl;
    }
    
    return 0 ;
}