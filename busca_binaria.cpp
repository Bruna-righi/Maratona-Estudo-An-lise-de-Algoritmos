#include <iostream>

int busca_binaria_recursiva(int* arr, int valor, int low, int high) {
    if (low > high) {
        return -1; //equivalente a NULL
    }
    int meio = (high+low)/2;
    if (arr[meio] == valor) {
        return meio;
    }
    if (arr[meio] > valor) {
        return busca_binaria_recursiva(arr, valor, low, meio-1);
    }
    if (arr[meio] < valor) {
        return busca_binaria_recursiva(arr, valor, meio+1, high);
    }
}

int busca_binaria_iterativa(int* arr, int valor, int low, int high) {
    while (low <= high) {
        int meio = (high+low)/2;
        if (arr[meio] == valor){
            return meio;
        }
        if (arr[meio] > valor) {
            high = meio-1;
        }
        if (arr[meio] < valor) {
            low = meio+1;
        }
    }
    return -1; //equivalente a NULL

}