#include "NaoTerminal.h"
#include <iostream>

// Implementação dos métodos da classe NaoTerminal

NaoTerminal::NaoTerminal(string nome) {
    this->nome = nome;
}

string NaoTerminal::getNome() const {
    return nome;
}

void NaoTerminal::setRegras(vector<string> regras) {
    regrasProducao.clear();
    for (const auto& regra : regras) {
        regrasProducao.push_back(regra);
    }
}

vector<string> NaoTerminal::getRegras() const {
    return regrasProducao;
}

void NaoTerminal::adicionarRegra(string regra) {
    regrasProducao.push_back(regra);
}

void NaoTerminal::imprimirRegra() const {
    string imprimir = "";
    imprimir += nome + " ->";

    for (const auto& s : regrasProducao) {
        imprimir += " " + s + " |";
    }

    imprimir.pop_back();
    cout << imprimir << endl;
}
