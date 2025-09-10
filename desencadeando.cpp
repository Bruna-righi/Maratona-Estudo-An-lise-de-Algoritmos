#include <bits/stdc++.h>

using namespace std;

int soma(int a, int b){
    return (a+b)%10;
}

int subtrai(int a, int b){
    return (a-b+10)%10;
}

int main(){
    cout << (-3%10);
    return 0;
    int t, acu=0, answer = 0;
    cin >> t;
    int in[t], out[t];
    for (int i = 0; i < t; i++){
        cin>>in[i];
    }
    for (int i = 0; i < t; i++){
        cin>>out[i];
    }
    for (int i = t-1; i >= 0; i--){
        in[i] = (in[i]-acu)%10;
        if(in[i] == out[i]){
            continue;
        }
        acu+= (in[i]-out[i])%10;
        answer += abs((in[i]-out[i])%10);
    }
    cout << answer;

}