#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test;
    cin >> test;
    
    for(int i = 0; i < test; i++){
        int* inputs = new int[3];

        for(int j = 0; j < 3; j++){
            cin >> inputs[j];
        }

        int len = inputs[0];
        int days = inputs[1];
        int limit = inputs[2];
        int* array = new int[len];

        for(int j = 0; j < len; j++){
            cin >> array[j];
        }

        int retval = 0;

        int j = 0;
        while(j < len){
            int counter = 0;
            if(array[j] <= limit){
                counter++;
                if(counter >= days) retval++;
                while (j + counter < len){
                    if(array[j + counter] > limit) break;
                    counter++;
                    if(counter >= days) retval += counter - days + 1;
                }
            }
            j += max(counter, 1);
        }


        cout << retval << endl;

        delete[] array;
        delete[] inputs;
    }

    return 0;
}