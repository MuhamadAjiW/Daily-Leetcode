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
    long long a, b, c, sum;
    vector<long long> price_a;
    vector<long long> price_b;

    cin >> a >> b;
    for (int i = 0; i < a; i++){
        cin >> c;
        price_a.push_back(c);
    }
    for (int i = 0; i < a; i++){
        cin >> c;
        price_b.push_back(c);
    }

    sum = 0;
    
    sum += price_a[b - 1];
    for (int i = b; i < a; i++){
        sum += min(price_a[i], price_b[i]);
    }

    long long price = sum;
    for (int i = b - 1; i > 0; i--){
        sum += price_a[i - 1] + price_b[i] - price_a[i];
        if(price > sum) price = sum;
    }

    cout << price << endl;
}

// main is usually like this
int main(){
    int n; cin >> n;

    for (int i = 0; i < n; i++){
        // cout << "--------" << endl;
        solve();
    }
    
}