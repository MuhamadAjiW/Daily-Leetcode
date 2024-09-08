#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        int len;
        string str;
        cin >> len;
        cin >> str;

        for(int j = 0; j < len; j++){
            cout << str[j];
            char temp = str[j];

            if(j < len) j++;

            while (true){

                if(j < len){
                    if(str[j] != temp){
                        j++;
                    }
                    else{
                        break;
                    };
                
                }
                else break;
            }
        }
        cout << endl;

    }

    return 0;
}