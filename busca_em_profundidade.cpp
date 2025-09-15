#include <bits/stdc++.h>

//BFS implementada com um grafo não-direcional
// mas o tipo de grafo não influencia 
// (só muda a leitura do grafo e a forma de adicionar arestas)

using namespace std;

void DFS_recursiva(vector<vector<int>> &grafo, vector<bool> &visitados, vector<int> &caminho, int no_atual){
    // se já foi visitado, não explora novamente
    if (visitados[no_atual]){
        return;
    }
    // se não foi visitado, marca como visitado
    visitados[no_atual] = true;
    //adiciona o nó no caminho
    caminho.push_back(no_atual);
    //e para cada nó vizinho, aplica DFS recursivamente
    for (auto vizinho : grafo[no_atual]){
        DFS_recursiva(grafo, visitados, caminho, vizinho);
    }
}

void DFS_pilha(vector<vector<int>> &grafo, vector<bool> &visitados,vector<int> &caminho, int primeiro_no = 0){
    //também é possível substituir a recursão por uma pilha,
    // implementada a partir da estrutura própria do c++
    stack<int> S;
    //insere o primeiro nó na pilha e marca como visitado
    S.push(primeiro_no);
    visitados[primeiro_no] = true;
    // realiza a busca enquanto a pilha não estiver vazia
    while (!S.empty()) {
        // retira o nó do topo da pilha para visitar o próximo
        int no_atual = S.top();
        caminho.push_back(no_atual);
        S.pop();
        // coloca todos os vizinhos (não-visitados) do nó atual na stack
        for (int vizinho : grafo[no_atual]){
            //se o nó vizinho ainda não foi visitado, coloca na pilha e marca como visitado
            if (!visitados[vizinho]) {
                S.push(vizinho);
                visitados[vizinho] = true;
            }
        }
    }

}

vector<int> DFS(vector<vector<int>> &grafo){
    //cria um vetor de visitados com todos os nós do grafo
    // e inicializa todos como falso
    vector<bool> visitados(grafo.size(), false);
    //vetor a ser retornado: grava a ordem em que os nós foram visitados
    // durante o DFS
    vector<int> caminho;
    // está sendo usada a implementação recursiva, para mudar é só alterar a versão comentada
    //DFS_recursiva(grafo, visitados, caminho, 0);
    DFS_pilha(grafo, visitados, caminho, 0);
    return caminho;
}

void inserirAresta(vector<vector<int>> &grafo, int a, int b, bool direcionado){
    grafo[a].push_back(b);
    if (!direcionado){
        grafo[b].push_back(a);
    }
}

int main(){
    int n, m; // n = número de nós, m = número de arestas
    cin >> n >> m;
        /* representando o grafo como uma lista de adjacência:
        os índices do primeiro vetor correspondem aos nós e
        cada valor do vetor bidimensional é um nó adjacente;
        representação:
        nó 1 -> 2, 4, 6
        nó 2 -> null;
        etc */
    vector<vector<int>> grafo(m);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        inserirAresta(grafo, a, b, false); // para grafos direcionados, mudar o 4° parametro para true
    }
    vector<int> caminho = DFS(grafo);
    for (int no : caminho){
        cout << no << " -> ";
    }
    cout << "fim\n";
}