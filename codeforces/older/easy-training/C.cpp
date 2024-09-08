#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm> 
using namespace std;

// main is usually like this
int main(){
    int n, a, row, col;
    bool found;
    vector<string> matrix;
    string in;

    cin >> n;

    for (int i = 0; i < n; i++){
        matrix.clear();

        for (int j = 0; j < 8; j++){
            cin >> in;
            matrix.push_back(in);
        }
        
        row = 0;
        found = false;
        while (row < 8){
            col = 0;
            while (col < 8){
                if(matrix[row][col] != '.') {
                    found = true;
                    break;
                }
                col++;
            }

            if(found) break;
            row++;
        }
        
        while (row < 8 && matrix[row][col] != '.'){
            cout << matrix[row][col];
            row++;
        }
        cout << endl;
    }
    
}