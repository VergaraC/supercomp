#include <iostream>
#include <vector>
#include <cmath>

struct itens {
        int indice;
        int peso;
        int valor;
};
int main() {
        std::vector<itens> itensVec;
        int pesoMax;
        int nItems;
        std::cin >> nItems >> pesoMax;
        itensVec.reserve(nItems);
        for(int i=0; i<nItems; i++){
            itens loop;
            int valorL;
            int pesoL;
            std::cin >> valorL >> pesoL;
            loop.valor =valorL;
            loop.peso =pesoL;

            itensVec.push_back(loop);
        } 
        std::sort(v.begin(), v.end(), greater<int>());
        int valorFinal = 0;
        int pesoFinal = 0;
        std::vector <itens> vetorFinal;
        for(int i=0;i<nItems; i++){
            if(pesoFinal + itensVec[i].peso < pesoMax){
                vetorFinal.push_back(itensVec[i]);
                pesoFinal += itensVec[i].peso;
                valorFinal += itensVec[i].valor;
            }
        }
        std::cout << pesoFinal << " " << valorFinal << " " << std::endl;
        std::cout << vetorFinal << std::endl;
        return 0;
}