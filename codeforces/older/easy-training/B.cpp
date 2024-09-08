#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm> 
using namespace std;

// main is usually like this
int main(){
    int n, a, b, min, min_idx, sum;
    vector<int> vec;

    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> a;
        vec.clear();
        sum = 1;
        min = 10;
        min_idx = 0;
        
        for (int j = 0; j < a; j++){
            cin >> b;
            vec.push_back(b);
            if(min > b){
                min = b;
                min_idx = j;
            } 
        }
        vec[min_idx] += 1;

        for (int j = 0; j < a; j++){
            sum *= vec[j];
        }
        cout << sum << endl;
        
    }
    
}