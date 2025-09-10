#include <stdio.h>
#include <iostream>
#include <vector>
#define INF INT32_MAX

using namespace std;

class SegTree
{
public:
    vector<pair<int, int>> innit;
    int tam;
    SegTree(vector<int>&arr){
        innit.resize(4*arr.size());
        tam = arr.size();
        build(arr, 1, 0, arr.size()-1);
    }

    pair<int,int> build(vector<int>& arr, int p, int l, int r){
        if (l == r) {
            innit[p].second = 1;
            innit[p].first = arr[l];
            return innit[p];
        }
        int m = (l+r)/2;
        pair<int, int> filho_esq = build(arr, 2*p, l, m);
        pair<int, int> filho_dir = build(arr, 2*p+1, m+1, r);

        if (filho_dir.first == filho_esq.first) {
            innit[p] = {filho_dir.first, filho_dir.second + filho_esq.second};
        } else if (filho_dir.first < filho_esq.first) {
            innit[p] = filho_dir;
        } else innit[p] = filho_esq;
        return innit[p];
        
    }

    pair<int,int> busca(int a, int b){
        return query(a, b, 1, 0, tam-1);
    }

    pair<int,int> atualizar(int x, int i){
        return update(x, i, 1, 0, tam-1);
    }

    pair<int,int> query(int a, int b, int p, int l, int r){
        if (a > r || b < l) return {INF, 0};
        if (l >= a && r <= b) return innit[p];
        int m = (l+r)/2;
        pair<int, int> filho_esq = query(a, b, 2*p, l, m);
        pair<int, int> filho_dir = query(a, b, 2*p+1, m+1, r);
        if (filho_dir.first == filho_esq.first) {
            return {filho_dir.first, filho_dir.second + filho_esq.second};
        } else if (filho_dir.first < filho_esq.first) {
            return filho_dir;
        } else return filho_esq;
    }

    pair<int,int> update(int x, int i, int p, int l, int r){
        if (i < l || i > r) return innit[p];
        if (l == i && r == i) return innit[p] = {x,1};
        int m = (l+r)/2;
        pair<int, int> filho_esq = update(x, i, 2*p, l, m);
        pair<int, int> filho_dir = update(x, i, 2*p+1, m+1, r);
        if (filho_dir.first == filho_esq.first) {
            innit[p] = {filho_dir.first, filho_dir.second + filho_esq.second};
        } else innit[p] = min(filho_dir,filho_esq);
        return innit[p];
    }

};


int main(){
    int n, m;
    vector<int> arr;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    SegTree segTree = SegTree(arr);
    while (m--){
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1){
            segTree.atualizar(b, a);
        }
        if (op == 2){
            pair<int,int> t = segTree.busca(a, b-1);
            cout << t.first << " " << t.second << endl;
        }

    }
}