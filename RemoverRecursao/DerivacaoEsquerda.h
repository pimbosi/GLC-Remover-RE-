#ifndef DERIVACAO_ESQUERDA_H
#define DERIVACAO_ESQUERDA_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class DerivacaoEsquerda {
private:
    vector<string> terminal;
    vector<string> producoes;

public:
    void adicionarRegra(string regra);
    string derivaraEsquerda();
};


#endif