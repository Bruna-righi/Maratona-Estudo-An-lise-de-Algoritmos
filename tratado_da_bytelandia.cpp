#include <bits/stdc++.h>

using namespace std;

#define EPS (1e-9);

typedef pair<int, int> pt;

int orientation(pt a, pt b, pt c) {
    double v = a.first*(b.second-c.second)+b.first*(c.second-a.second)+c.first*(a.second-b.second);
    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}

bool cw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}
bool collinear(pt a, pt b, pt c) { return orientation(a, b, c) == 0; }

vector<pt> convex_hull(vector<pt>& a, bool include_collinear = true) {
    pt p0 = *min_element(a.begin(), a.end(), [](pt a, pt b) {
        return make_pair(a.second, a.first) < make_pair(b.second, b.first);
    });
    sort(a.begin(), a.end(), [&p0](const pt& a, const pt& b) {
        int o = orientation(p0, a, b);
        if (o == 0)
            return (p0.first-a.first)*(p0.first-a.first) + (p0.second-a.second)*(p0.second-a.second)
                < (p0.first-b.first)*(p0.first-b.first) + (p0.second-b.second)*(p0.second-b.second);
        return o < 0;
    });
    if (include_collinear) {
        int i = (int)a.size()-1;
        while (i >= 0 && collinear(p0, a[i], a.back())) i--;
        reverse(a.begin()+i+1, a.end());
    }

    vector<pt> st;
    for (int i = 0; i < (int)a.size(); i++) {
        while (st.size() > 1 && !cw(st[st.size()-2], st.back(), a[i], include_collinear))
            st.pop_back();
        st.push_back(a[i]);
    }

    if (include_collinear == false && st.size() == 2 && st[0] == st[1])
        st.pop_back();

    return st;
}

int main(){
    int t;
    cin >> t;
    vector<pt> pontos(t);
    map<pt, int> mapa;
    for(int i = 0; i <t; i++) {
        int x, y;
        cin >> x >> y;
        pontos[i] = pt(x, y);
        mapa[{x,y}] =i+1;
    }
    vector<pt> pontosInf = convex_hull(pontos, true);
    vector<int> idxP;
    for (auto p:pontosInf){
        idxP.push_back(mapa[p]);
    }
    sort(idxP.begin(), idxP.end());
    for(auto v: idxP) {
        cout << v << ' ';
    }
    cout << endl;

    return 0;
}