#include <bits/stdc++.h>
#define N 100
#define W 100

int matriz[W+1][N+1];

using namespace std;

vector<int> backtracking(int valor[], int custo[], int n, int w){
    int currW = w;
    vector<int> itens;
    for (int i = n; i > 0; i--){
        if (matriz[i][currW] != matriz[i-1][currW]){
            currW -= custo[i-1];
            itens.push_back(i-1);
        }
    }
    return itens;
}

void computa_matriz(int valor[], int custo[], int n, int w){
    for (int i = 0; i <= n; i++){
        for (int x = 0; x <= w; x++){
            if(i==0){
                matriz[i][x] = 0;
                continue;
            }
            int j = i-1, val;
            val = valor[j];
            int cost = custo[j];
            if (x - cost >= 0) {
                matriz[i][x] = max(matriz[j][x], matriz[j][x-cost]+val);
            } else matriz[i][x] = matriz[j][x];
            
        }
    }
}

int main(){
    int t, w, n;
    cin >> t;

    while (t--) {
        cin >> w >> n;
        int valor[n], custo[n];
        for (int i = 0; i < n; i++){
            cin >> valor[i] >> custo[i];
        }
        computa_matriz(valor, custo, n, w);
        cout << "\t";
        for (int x = 0; x < w+1; x++){
            cout << "w=" << x <<"   ";
        }
        cout << endl;
        for (int i = 0; i < n+1; i++){
            cout << "i= " << i << "\t";
            for (int x = 0; x < w+1; x++){
                cout << matriz[i][x] <<"  |  ";
            }
            cout << endl;
        }
        vector<int> a = backtracking(valor, custo, n, w);
        for (int y : a){
            cout <<"i:"<< y+1 << " -> ";
        }
        cout << "fim" << endl;
        
    }


    return 0;
}