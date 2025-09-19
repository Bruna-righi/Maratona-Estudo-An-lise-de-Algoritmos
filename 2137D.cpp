#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main(){
    int n, t;
    cin >> t;
    while(t--){
        cin >> n;
        bool valido = true;
        int k = 1;
        vector<int> a;
        map<int, pii> mapa;
        for (int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            /*
            if(mapa.find(temp) != mapa.end()){  // checa se existe temp

            }*/

            auto curr = mapa[temp]; //= {0,0}
            mapa[temp] = {curr.first == 0 ? k++ : curr.first, curr.second + 1};
            //cout << mapa[temp].first << " " << mapa[temp].second << endl;
            
            a.push_back(mapa[temp].first);
            
            if (curr.second+1 == temp){
                mapa[temp] = {k++, 0};
            }
        }
        for (auto o : mapa){
            // o.f = key =  temp
            // o.s = pii
            if (o.second.second != 0){
                cout << "-1";
                valido = false;
                break;
            }
        }
        if (valido)
        for (int i :a){
            cout << i << " ";
        } 
        cout << endl;

    }

    return 0;
}