// Resolver usando matriz de adjacencia (usando djikstra)
// Resolver usando ma + dfs
// Resolver usando ma + bds (notar algo especial)

// Resolver usando lista de adjacencia (usar qlq um dos algo anterior)

#include <bits/stdc++.h>

using namespace std;

class MatrizAdjacencia
{
private:
    int** matriz;
    //int matriz[101][101]
    //vector<vector<int>> matriz;
    //map<pair<int,int>,int> matriz;    // map[makepair(i,j)] = ator
    int tam;
public:
    // node == filme
    MatrizAdjacencia(int qtdNodes){
        tam = qtdNodes;
        // matriz.resize(qtdNodes);
        matriz = (int**) malloc(qtdNodes*(sizeof(int*)));
        for (int i = 0; i < qtdNodes; i++){
            // matriz[i].resize(qtdNodes);
            matriz[i] = (int*) malloc(qtdNodes*sizeof(int));
        }
    }

    ~MatrizAdjacencia(){
        for (int i = 0; i < tam; i++){
            free(matriz[i]);
        }
        free(matriz);
    }

    void insereAresta(int nodeA, int nodeB, int ator){
        matriz[nodeA][nodeB] = ator;
    }

    vector<int> buscaCaminho(int nodeA, int nodeB);

};





int main(){
    int n,m;
    cin >> n >> m;
    for(int x=0;x<n;x++){
        int aux;
        cin >> aux;
        for(int y=0;y<aux;y++){
            int ator;
            cin >> ator;
            
        }
    }
    return 0;
}
