#include "NaoTerminal.h"

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

string NaoTerminal::novasRegras() const {
    string novaRegra = "";
    novaRegra += nome + " ->";

    for (const auto& s : regrasProducao) {
        novaRegra += " " + s + " |";
    }

    novaRegra.pop_back();
    return novaRegra;
}