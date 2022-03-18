
  
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

struct item
{
    int id;
    double peso;
    double valor;
};

bool my_compare_id(item a, item b)
{
    return a.id < b.id; // ordenando pelo id
}

int main()
{
    int n = 0;
    int W = 0;

    vector<item> mochila;
    vector<item> melhorMochila;
    vector<item> items;

    int melhorValor = 0;
    int melhorPeso = 0;

    cin >> n >> W;
    items.reserve(n);

    double peso, valor;
    for (int i = 0; i < n; i++)
    {
        cin >> peso;
        cin >> valor;
        items.push_back({i, peso, valor});
    }

    std::default_random_engine eng(123);
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    double r = 0;
    peso = 0;
    valor = 0;

    for (int g = 0; g < 500; g++)
    {
        for (auto &el : items)
        {
            r = distribution(eng);
            if (el.peso + peso <= W)
            {
                if (r <= 0.5)
                {
                    mochila.push_back(el);
                    peso += el.peso;
                    valor += el.valor;
                }
            }
        }
        if (valor > melhorValor)
        {
            melhorValor = valor;
            melhorMochila = mochila;
            melhorPeso = peso;
        }

        peso = 0;
        valor = 0;
        mochila.clear();
    }

    // ordenando para imprimir
    sort(melhorMochila.begin(), melhorMochila.end(), my_compare_id);
    cout << "peso: " << melhorPeso << " valor: " << melhorValor << endl;
    cout << "itens ids :" << endl;
    for (auto &el : melhorMochila)
    {
        cout << el.id << " ";
    }
    cout << endl;
    return 0;
}

// g++ -Wall -O3 aleatoria.cpp -o aleatoria
// ./aleatoria < in3.txt