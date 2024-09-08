#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
using namespace std;

vector<int> divisors;
void getdiv(int n){
    for (int i = 1; i*i < n; i++){
        if(n%i == 0){
            divisors.push_back(i);
            if((n/i) != i){
                divisors.push_back(n/i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());
}
int checkStringDiv(string a, string b){
    int c = 0;
    for (int i = 0; i < a.length(); i++){
        if(a[i] != b[i]){
            c++;
        }
    }
    return c;
}

int main(){
    int n, a;
    string str;


    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> a;
        cin >> str;


    }
    
}