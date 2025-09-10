#include <bits/stdc++.h>

using namespace std;

int calcula(int k, int n, int t){
    if (k == 0){
        return t;
    }
    t *= 2;
    return calcula(k-1, n, t);
}

int main(){
    int t, x, k;
    cin >> t;
    while(t--){
        cin >> k >> x;
        cout << calcula(k, x, x) << endl;
    }
    return 0;
}