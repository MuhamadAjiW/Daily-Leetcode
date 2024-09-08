#include <iostream>

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

        int idx1 = 0;
        int idxmax = 0;
        int maxval = INT_MIN;

        for(int j = 0; j < numbers; j++){
            cin >> array[j];
            if(array[j] == 1){
                idx1 = j;
            }
            if(array[j] > maxval){
                idxmax = j;
                maxval = array[j];
            }
        }

        if(idx1 == 0){
            cout <<  2 << " " << idxmax + 1 << endl;
        }
        else if(idx1 == numbers-1){
            cout << numbers-2 << " " << idxmax + 1 << endl;
        }
        else{
            if(array[1] > array[numbers-1]){
                cout << 1 << " " << idx1 + 1 << endl;
            }
            else{
                cout << numbers << " " << idx1 + 1 << endl;
            }
        }

        delete[] array;
    }

    return 0;
}