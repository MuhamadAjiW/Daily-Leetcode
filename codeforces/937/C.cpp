#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    string time;
    string hour;

    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> time;
        hour = time.substr(0, 2);

        int hour_i = stoi(hour);
        if(hour_i >= 12){
            if(hour_i > 12){
                hour_i -= 12;
                hour = to_string(hour_i);
                if(hour_i < 10) hour.insert(0, "0");

                time.replace(0, 2, hour);
            }

            cout << time << " PM" << endl;

        } else{
            if(hour_i == 0){
                hour_i += 12;
                hour = to_string(hour_i);
                if(hour_i < 10) hour.insert(0, "0");

                time.replace(0, 2, hour);
            }
            cout << time << " AM" << endl;
        }

    }
    
}
