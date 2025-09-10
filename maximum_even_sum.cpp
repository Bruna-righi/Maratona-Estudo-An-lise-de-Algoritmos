#include <bits/stdc++.h>

using namespace std;

int main(){
    long long a, b, t;
    cin >> t;
    
    while(t--){
        cin >> a >> b;
        if (b%2 == 0){
            long long k = b/2;
            if (a % 2 ==1 && k%2 == 0){
                cout << a*(k) + 2 << endl;
            } else if (a%2 == 0){
                cout << a*(b/2)+2 << endl;
            } else cout << "-1" << endl;
        } else if (b%2 == 1){
            if (a %2 == 1){
                cout << a*b+1 << endl;
            }
            else cout << "-1\n";
        }
    }
}