#include <bits/stdc++.h>

using namespace std;

int main(){
    int x = 0;
    int t;
    cin >> t;
    while (t--){
        string a;
        cin >> a;
        if (a.find('-') != string::npos){
            x--;
        }else x++;
    }
    cout << x << endl;
}