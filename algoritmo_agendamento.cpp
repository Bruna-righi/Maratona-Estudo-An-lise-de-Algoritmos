#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int main(){
    int prioridade;
    float tempo;
    priority_queue<tuple<double, double, int>> razoes;
    vector<tuple<double, double, int>> vec;
    while (scanf("%d %f", &prioridade, &tempo) != EOF){
        razoes.push(make_tuple(prioridade/tempo, tempo, prioridade));
    }
    while (!razoes.empty()) {
        cout << get<2>(razoes.top()) <<" "<< get<1>(razoes.top()) << endl;
        razoes.pop();
    }
    return 0;
}