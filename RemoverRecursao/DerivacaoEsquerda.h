#ifndef DERIVACAO_ESQUERDA_H
#define DERIVACAO_ESQUERDA_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class DerivacaoEsquerda {
private:
    // Vetor de terminais
    vector<string> terminal; 
     // Vetor de producoes
    vector<string> producoes;

public:
    // Separa os terminais e as producoes
    void adicionarRegra(string regra); 
    // Aplica o algoritmo de derivacao mais a esquerda
    string derivaraEsquerda();  
};


#endif