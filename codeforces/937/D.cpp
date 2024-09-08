#include <iostream>
#include <string>
using namespace std;


int possible[] = {
    1, 0,
    10, 11, 
    101, 110, 111, 
    1000, 1001, 1010, 1100, 1011, 1110, 1101, 1111,
    10000, 10001, 10010, 10011, 10100, 10101, 10110, 10111, 11000, 11001, 11010, 11011, 11100, 11101, 11110, 11111

};
int p_count = 31;

int divisors[] = {
    10, 11, 
    101, 110, 111, 
    1000, 1001, 1010, 1100, 1011, 1110, 1101, 1111,
    10000
};
int d_count = 14;

int calc(int val){
    if(val == 1) return 1;

    else{
        int divisible = 0;
        for (int i = 0; i < d_count; i++){
            if(val % divisors[i] == 0){
                divisible = 1 && calc(val / divisors[i]);
            }
        }
        return divisible;
    }

}

int main(){
    int n, str_i;
    string str;

    cin >> n;

    for (int i = 0; i < n; i++){
        int binary = 0;
        cin >> str_i;
        str = to_string(str_i);
        
        for (int i = 0; i < p_count; i++){
            if(str_i == possible[i]){
                cout << "YES" << endl;        
                binary = 1;
                break;
            }
        }
        
        if(!binary){
            if(calc(str_i)){
                cout << "YES" << endl;        
            }
            else{
                cout << "NO" << endl;        
            }
        }

    }
    
}