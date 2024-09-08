#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm> 
using namespace std;

// Do actual solving here
void solve(){
    int introverts, extroverts, universal;
    cin >> introverts >> extroverts >> universal;


    int extrovert_remain = extroverts % 3;
    int remain = extrovert_remain + universal;
    if(extrovert_remain != 0 && remain < 3){
        cout << -1 << endl;
    }
    else{
        int tents = introverts + extroverts / 3 + remain / 3;
        if(remain % 3 != 0) tents++;
        cout << tents << endl;
    }

}

// main is usually like this
int main(){
    int n; cin >> n;

    for (int i = 0; i < n; i++){
        solve();
    }
    
}