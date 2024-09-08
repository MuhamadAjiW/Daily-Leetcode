#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm> 
using namespace std;

typedef long long ll;

// Do actual solving here
void solve(){
    ll a, b, m;
    cin >> a >> b >> m;

    ll intersect;

    intersect = m / a + 1 + m / b + 1;
    
    cout << intersect << endl;
}

// main is usually like this
int main(){
    ll n; cin >> n;

    for (ll i = 0; i < n; i++){
        solve();
    }
}