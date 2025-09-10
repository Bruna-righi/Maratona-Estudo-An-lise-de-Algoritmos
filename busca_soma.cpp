#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    //o array abaixo é só um exemplo
    vector<int> arr = {2,4,34,54,23,234,65,4,35,6,47,68,32,5,4,7,6,2,65,34,7,87,54,32,3,43,5,46,74,67,7,645,3,45,43,1,123,96};
    int i = 0, j = arr.size()-1;
    int x = 67;
    sort(arr.begin(), arr.end()); // tempo: O(nlogn)
    while (i <= j){
        if (arr[i] + arr[j] == x){
            break;
        }
        if (arr[i] + arr[j] < x) {
            i++;
        }
        if (arr[i] + arr[j] > x) {
            j--;
        }
    } // tempo: O(n)
}