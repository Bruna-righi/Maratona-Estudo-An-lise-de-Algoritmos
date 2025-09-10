    #include <iostream>
    #include <vector>
    #include <cmath>
    #include <algorithm>

    using namespace std;

    void printVector(vector<int>& v){
        for (int i = v.size()-1; i >= 0; i--){
            cout <<  v[i];
        }
        cout << endl;
    }

    vector<int> inteiroParaBinario(int n) {
        vector<int> binario;
        while (n > 0) {
            binario.push_back(n % 2);
            n /= 2;
        }
        return binario;
    }

    int main(){
        int a, b;
        cin >> a >> b;
        vector<int> aBinario = inteiroParaBinario(a);
        vector<int> bBinario = inteiroParaBinario(b);
        int tam = max(aBinario.size(), bBinario.size());
        aBinario.resize(tam);
        bBinario.resize(tam);
        vector<int> cBinario(tam+1, 0);
        for (int i = 0; i<tam; i++){
            if (aBinario[i] && bBinario[i] || (aBinario[i] && cBinario[i]) || (bBinario[i] && cBinario[i])){
                cBinario[i+1] = 1;
            }
            cBinario[i] = aBinario[i]^bBinario[i]^cBinario[i];
        }
        printVector(cBinario);
        
    }