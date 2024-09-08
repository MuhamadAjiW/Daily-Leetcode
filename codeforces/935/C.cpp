#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <cstdint>
#include <cfloat>
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
// void solve(){
//     int n;
//     string house;

//     cin >> n >> house;
    

//     float distance = FLT_MAX;
//     int location = -1;
//     for (int i = 0; i <= n; i++){
//         int left = 0;
//         for (int j = 0; j < i; j++){
//             if(house[j] == '0') left++;
//         }
//         // cout << "left: " << left  << "/" << i << endl;
//         if(left >= (i + 2 - 1)/2){
//             int right = 0;
//             for (int j = i; j < n; j++){
//                 if(house[j] == '1') right++;
//             }
//             // cout << "right: " << right << "/" << (n-i)  << endl;
//             if(right >= (n-i + 2 - 1)/2){
//                 float temp_dist = abs(i - n/2.0);
//                 // cout << "Potential: " << i << "; dist: " << temp_dist << endl;
//                 if(temp_dist < distance){
//                     location = i;
//                     distance = temp_dist;
//                 }
//                 else break;
//             }
//         }
//     }
//     cout << location << endl;

// }

void solve(){
    int n;
    string house;

    cin >> n >> house;
    

    float distance = FLT_MAX;
    int location = -1;

    int right1 = 0;
    int right0 = 0;
    int left1 = 0;
    int left0 = 0;
    for (int i = 0; i < n; i++){
        if(house[i] == '1') right1++;
    }
    right0 = n - right1;

    for (int i = 0; i < n; i++){
        if(left0 >= (i + 2 - 1)/2 && right1 >= (n-i + 2 - 1)/2){
            float temp_dist = abs(i - n/2.0);
            if(temp_dist < distance){
                location = i;
                distance = temp_dist;
            }
        }

        if(house[i] == '1'){
            right1--;
        } else{
            left0++;
        }
    }
    if(left0 >= (n + 2 - 1)/2){
        float temp_dist = abs(n/2.0);
        if(temp_dist < distance){
            location = n;
            distance = temp_dist;
        }
    }
    
    cout << location << endl;

}

// main is usually like this
int main(){
    int n; cin >> n;

    for (int i = 0; i < n; i++){
        // cout << "case: " << i + 1 << endl;
        solve();
    }
    
}