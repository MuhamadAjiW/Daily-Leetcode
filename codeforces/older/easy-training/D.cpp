#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm> 
using namespace std;


char vika[] = {'a', 'k', 'i', 'v'};
void solve(){
    int n, m;
    vector<string> matrix;
    string in;

    cin >> n;
    cin >> m;

    // cout << n << m << endl;

    for (int i = 0; i < n; i++){
        cin >> in;
        matrix.push_back(in);
    }
    
    if(m < 4){
        cout << "NO" << endl;
        return;
    }

    int found = 3;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            // cout << matrix[j][i] << endl;
            if(matrix[j][i] == vika[found]){
                found--; break;
            }
        }
    }

    if(found == -1){
        cout << "YES" << endl;
    }
    else{
        // cout << "NO" << found << endl;
        cout << "NO" << endl;
    }
}

// main is usually like this
int main(){
    int t; cin >> t;

    for (int i = 0; i < t; i++){
        // cout << "case: " << i << endl;
        solve();
    }
    
}