#include <bits/stdc++.h>

using namespace std;

int main(){
    int k;
    cin >> k;
    int res = 0;
    while(k--){
        int cont = 0;
        int temp = 0;
        for (int i = 0; i < 3; i++) {
            cin >> temp;
            cont += temp;
        }
        if (cont>= 2){
            res++;
        }
    }
    cout << res << endl;
}