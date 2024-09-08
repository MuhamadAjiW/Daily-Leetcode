#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm> 
using namespace std;

// Do actual solving here
void solve(){
    int a;
    cin >> a;

    if(a % 3 == 0){
        cout << "Second" << endl;
    } else{
        cout << "First" << endl;
    }
}

// main is usually like this
int main(){
    int n; cin >> n;

    for (int i = 0; i < n; i++){
        solve();
    }
    
}