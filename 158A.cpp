#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int arr[n];
    int cont = 0;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (arr[i] == 0) cont++;
    }
    if (n-cont < k) {
        cout << n-cont << endl;
        return 0;
    }
    while (k < n && arr[k-1] == arr[k] && arr[k] != 0) k++;
    cout << k << endl;
}