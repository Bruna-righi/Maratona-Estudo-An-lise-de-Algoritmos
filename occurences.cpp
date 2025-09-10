#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;
    bool at;

    while(t--){
        int a;
        at = true;
        vector<pair<int,int>> x;
        cin >> a;
        int v[a];
        for (int i= 0; i <a; i++){
            cin >> v[i];
        }
        int cont = 1;
        for (int i= 0; i <a-1; i++){
            if (v[i] == v[i+1]){
                cont++;
            } else {
                x.push_back({v[i], cont});
                cont = 1;
            }
        }
        
        x.push_back({v[a-1], cont});
        
        for (int i = 0; i+1 < x.size(); i++){
            if (x[i].first < x[i].second){
                cout << "-1\n";
                at = false;
                break;
            }
            if (x[i].second == x[i+1].second){
                cout << "-1\n";
                at = false;
                break;
            }
        }
        if (at == false){
            continue;
        }
        for (int i = 0; i < x.size(); i++){
            int h = x[i].second;
            while(h--){
                cout << i+1 << " ";
            }
        }
        cout << endl;
    }
}

