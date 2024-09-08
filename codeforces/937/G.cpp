#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(){
    int n, a;
    string genre_in, singer_in;
    map<string, vector<string>>::iterator it_map;
    vector<string>::iterator it_vec;

    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> a;

        map<string, vector<string>> genre;
        map<string, vector<string>> singer;

        for (int j = 0; j < a; j++){
            cin >> genre_in;
            genre[genre_in].push_back(genre_in);

            cin >> singer_in;
            singer[singer_in].push_back(singer_in);
        }

        if(a == 1 || genre.size() == 1 || singer.size() == 1){
            cout << 0 << endl;
            continue;
        } else{

        }
    }
    
}