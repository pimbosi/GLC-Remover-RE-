#ifndef NAO_TERMINAL_H
#define NAO_TERMINAL_H

#include <string>
#include <vector>

using namespace std;

class NaoTerminal {
private:
    string nome;
    vector<string> regrasProducao;

public:
    // Construtor
    NaoTerminal(string nome);
    // Métodos de acesso
    string getNome() const;
    void setRegras(vector<string> regras);
    vector<string> getRegras() const;
    // Adiciona uma regra à produção
    void adicionarRegra(string regra);
    // Imprime a regra no formato "Nome -> regra1 | regra2 | ..."
    void imprimirRegra() const;
};

#endif
