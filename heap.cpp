#include <stdio.h>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#define DIR(x) (2*(x)+1)
#define ESQ(x) (2*(x))

using namespace std;

class heap
{
private:
    vector<int> it;
    
public:
    heap(){
    }

    void inserir(int x){
        if (it.size() == 0){
            it.push_back(0);
        }
        it.push_back(x);
        bubble_up(it.size()-1);
    }

    int pop(){
        int temp = it[1];
        it[1] = it[it.size()-1];
        it.pop_back();
        bubble_down(1);
        return temp;
    }

    void bubble_up(int position){
        if (position <= 1){
            return;
        }
        int maior_atual = it[position];
        int pai = it[position/2];
        if (maior_atual > pai){
            it[position] = pai;
            it[position/2] = maior_atual;
            bubble_up(position/2);
        }
    }
    
    int size(){
        return it.size()-1;
    }

    void bubble_down(int position){
        if (ESQ(position) >= it.size()){ // trabalhar
            return;
        }
        int atual = it[position];
        int filho_esq = it[ESQ(position)];
        int filho_dir = NULL;
        int m = max(atual, filho_esq);

        if (DIR(position) < it.size()) {
            filho_dir = it[DIR(position)];
            m = max(m, filho_dir);
        }

        if (m == atual){
            return;
        } else if (m == filho_esq){
            it[position] = filho_esq;
            it[ESQ(position)] = atual;
            bubble_down(ESQ(position));
        } else if (m == filho_dir) {
            it[position] = filho_dir;
            it[DIR(position)] = atual;
            bubble_down(DIR(position));
        }
    }

};


int main(){
    heap var;
    priority_queue<int> pri;
    int arr[] = {2, -3, 8, 14, -3, 98, 76, 0, 7, 54, 39, 3, 87, 5, 5, 23, 2, 10, 11, 9, 7, 5, 3, 98};

    for (int i = 0; i < 24; i++){
       var.inserir(arr[i]);
       pri.push(arr[i]);
    }
    while (var.size() > 0){
        cout << var.pop() << " - " << pri.top() << endl;
        pri.pop();
    }

}