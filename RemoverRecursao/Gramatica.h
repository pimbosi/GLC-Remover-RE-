#ifndef GRAMATICA_H
#define GRAMATICA_H

#include "NaoTerminal.h"

class Gramatica {
private:
    vector<NaoTerminal> naoTerminais;

public:
    // Adiciona uma regra à gramática
    void adicionarRegra(string regra);
    // Aplica o algoritmo para eliminar recursão à esquerda
    void aplicarAlgoritmo();
    // Resolve a recursão à esquerda não imediata entre A e B
    void resolverNaoImediataLR(NaoTerminal& A, NaoTerminal& B);
    // Resolve a recursão à esquerda imediata para A
    void resolverImediataLR(NaoTerminal& A);
    // Imprime todas as regras da gramática
    void imprimirRegras();
};

#endif
