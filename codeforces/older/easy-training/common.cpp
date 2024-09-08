#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm> 
using namespace std;

// Get all divisors
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

// greatest common divisor
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

// largest common multiplier
int lcm(int a, int b) 
{ 
    return (a / gcd(a, b)) * b; 
} 

// Do actual solving here
void solve(){

}

// main is usually like this
int main(){
    int n; cin >> n;

    for (int i = 0; i < n; i++){
        solve();
    }
    
}