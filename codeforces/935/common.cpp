#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <cstdint>
#include <cfloat>
#include <algorithm> 
using namespace std;

typedef long long ll;

// Get all divisors
vector<ll> divisors;
void getdiv(ll n){
    for (ll i = 1; i*i < n; i++){
        if(n%i == 0){
            divisors.push_back(i);
            if((n/i) != i){
                divisors.push_back(n/i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());
}

// ceil(a,b) but faster
ll ceiling(ll a, ll b){
    return (a + b - 1)/b;
}

// greatest common divisor
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

// largest common multiplier
ll lcm(ll a, ll b) 
{ 
    return (a / gcd(a, b)) * b; 
} 

void solve(){

}

int main(){
    ll n; cin >> n;

    for (ll i = 0; i < n; i++){
        // cout << "case: " << i + 1 << endl;
        solve();
    }
    
}