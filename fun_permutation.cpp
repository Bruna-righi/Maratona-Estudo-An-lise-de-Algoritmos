#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        for (int i = 0; i < x; i++){
            int val;
            cin >> val;
            cout << x - val + 1 << " ";
        }
        cout << endl;
    }
}