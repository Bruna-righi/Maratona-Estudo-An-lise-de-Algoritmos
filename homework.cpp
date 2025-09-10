#include <bits/stdc++.h>

using namespace std;

int main(){
    int t, n, m;
    cin >> t;
    while(t--){
        cin >> n;
        deque<char> a(n);
        for (int i = 0; i <n; i++){
            cin >> a[i];
        }
        cin >> m;
        char b[m];
        for (int i = 0; i <m; i++){
            cin >> b[i];
        }
        for (int i = 0; i <m; i++){
            char vez;
            cin >> vez;
            if (vez == 'V'){
                a.push_front(b[i]);
            }
            else a.push_back(b[i]);
        }
        for (int i = 0; i <n+m; i++){
            cout << a[i];
        }
        cout << endl;
    }
    return 0;
}