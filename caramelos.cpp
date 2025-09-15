#include <bits/stdc++.h>

#define N 101
#define M 1000001

int mat[N+1][M+1] = {};

using namespace std;

vector<int> naoCaminho;

vector<int> backtracking(int n, int w, int custo[]){
    int currW = w;
    vector<int> a;
    for (int i = n; i > 0; i--) {
        if (mat[i][currW] != mat[i-1][currW]){
            a.push_back(i-1);
            currW -= custo[i-1];
        } else naoCaminho.push_back(i-1);
    }
    return a;
}

void calcular_matriz(int n, int w, int custo[]){

    for (int i = 0; i <= n; i++){
        for (int x = 0; x<=w; x++){
            if(i==0){
                mat[i][x]=0;
                continue;
            }
            mat[i][x] = max(
                mat[i-1][x],
                ((x - custo[i-1])>=0) ? (mat[i-1][x - custo[i-1]] + custo[i-1]) : 0
            );
        }
    }
}

int main(){
    int t;
    cin >> t;
    int arr[t];
    int soma = 0;
    for (int i = 0; i < t; i++){
        cin >> arr[i];
        soma += arr[i];
    }
    calcular_matriz(t, soma/2, arr);
    if (mat[t][soma/2] != soma/2 || soma%2==1){
        cout << "-1" << endl;
    }else {
        vector<int> caminho = backtracking(t, soma/2, arr);
        int contA = 0, contB = 0;
        int m = 0, n=0;
        while (caminho.size() > 0 && naoCaminho.size() > 0){
            if (contA <= contB){
                int a = caminho[caminho.size() - 1];
                cout << arr[a] << " ";
                contA += arr[a];
                caminho.pop_back();
            } else {
                int b = naoCaminho[naoCaminho.size()-1];
                cout << arr[b] << ' ';
                naoCaminho.pop_back();
                contB += arr[b];
            }
        }
        while(caminho.size() > 0){
            int a = caminho[caminho.size() - 1];
            cout << arr[a] << " ";
            caminho.pop_back();
        }
        while(naoCaminho.size() > 0){
            int a = naoCaminho[naoCaminho.size() - 1];
            cout << arr[a] << " ";
            naoCaminho.pop_back();
        }
        cout << endl;
    }

    return 0;
}