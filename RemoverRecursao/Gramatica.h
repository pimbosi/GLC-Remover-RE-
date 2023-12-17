#ifndef GRAMATICA_H
#define GRAMATICA_H

#include <iostream>
#include <string>
#include <cstddef>
#include "NaoTerminal.h"
#include "DerivacaoEsquerda.h"

class Gramatica {
private:
    vector<NaoTerminal> naoTerminais;

public:
    // Adiciona uma regra à gramática
    void adicionarRegra(string regra);
    // Aplica o algoritmo para eliminar recursão à esquerda
    void aplicarAlgoritmo();
    // Resolve a recursão à esquerda não imediata entre A e B
    void resolverNaoImediataRE(NaoTerminal& A, NaoTerminal& B);
    // Resolve a recursão à esquerda imediata para A
    void resolverImediataRE(NaoTerminal& A);
    // Imprime todas as regras da gramática
    pair<string, string> novasRegras();

};

#endif
