#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm> 
using namespace std;

// main is usually like this
int main(){
    int n;
    string str;

    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> str;

        for (int i = 1; i <= 8; i++){
            if(str[1] - '0' != i){
                cout << str[0] << i << endl; 
            }
            char a = 'a' - 1 + i;
            if(a != str[0]){
                cout << a << str[1] << endl; 
            }
        }
                
    }
    
}