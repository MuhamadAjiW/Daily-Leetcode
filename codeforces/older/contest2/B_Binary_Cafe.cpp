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
        int n, k;
        cin >> n >> k;

        int counter = 0;
        int retval = 1;

        while(n){
            if(n & 1){
                retval += (1 << counter);
            }
            counter++;
            n = n >> 1;
        }
        if(counter > min(k, 31)){
            cout << (1 << k) << endl;
        }
        else{
            cout << retval << endl;
        }

    }

    return 0;
}