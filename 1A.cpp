#include <bits/stdc++.h>

using namespace std;

int main(){
    double m, n, a;
    cin >>m >> n>>a;
    long long t = ceil(m/a) * ceil(n/a);
    cout << t << endl;
}