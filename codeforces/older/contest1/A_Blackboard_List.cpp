#include <bits/stdc++.h>



using namespace std;

int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        int numbers;
        cin >> numbers;
        int* array = new int[numbers];

        int negative = 0;
        int maxval = INT_MIN;
        for(int j = 0; j < numbers; j++){
            cin >> array[j];
            if(array[j] > maxval){
                maxval = array[j];
            }
            if(array[j] < 0){
                negative = array[j];
            }
        }
        if (negative){
            cout << negative << endl;
        }
        else{
            cout << maxval << endl;
        }
        
        delete[] array;
    }

    return 0;
}