#include <iostream>
using namespace std;

int main(){
    int n, a;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a;

        for (int j = 0; j < a; j++)
        {
            for (int k = 0; k < a; k++)
            {
                if( (k + j) & 1) cout << "..";
                else cout << "##";
            }
            cout << endl;
            for (int k = 0; k < a; k++)
            {
                if( (k + j) & 1) cout << "..";
                else cout << "##";
            }
            cout << endl;

        }
        
    }
    
}