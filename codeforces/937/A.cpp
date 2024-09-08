#include <iostream>
using namespace std;

int main(){
    int a, b, c, n;

    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> a;
        cin >> b;
        cin >> c;


        if(b > a && c > b){
            cout << "STAIR"<< endl;
        }
        else if (b > a && b > c){
            cout << "PEAK" << endl;
        } else{
            cout << "NONE" << endl;
        }

    }
    
}