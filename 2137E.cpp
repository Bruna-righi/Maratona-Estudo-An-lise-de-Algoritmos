//desisti :/
#include <bits/stdc++.h>

using namespace std;

long long somatorio(vector<int>&arr){
    long long cont = 0;
    for (int i = 0; i < arr.size(); i++){
        cont += arr[i];
    }
    return cont;

}

int main(){
    int n, t;
    long long k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        vector<int> a, b, c;
        for (int i = 0; i <n; i++){
            int temp;
            cin >> temp;
            a.push_back(temp);
        }
        sort(a.begin(), a.end());
        while (k-- && a != b){
            c = b;
            b = a;
            vector<int> x(n+1);
            for (int i : a){
                x[i]++;
            }
            vector<int> res;
            int mex = 0;
            while (x[mex]) mex++;
            int mm = 0;
            for ( int i : a){
                if (x[i] > 1) res.push_back(mex);
                else res.push_back(mm);
                if (i == mm) mm++;
            }
            sort(res.begin(), res.end());
            a = res;
            if (a == c){
                k&=1;
            }
        }
        cout << somatorio(a) << endl;
    }

}