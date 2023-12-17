#include "Gramatica.h"

// Implementação dos métodos da classe Gramatica

void Gramatica::adicionarRegra(string regra) {
    bool nt = false;
    string parse = "";

    for (char c : regra) {
        if (c == ' ') {
            if (nt == false) {
                // Adiciona novo não terminal à lista
                NaoTerminal novoNaoTerminal(parse);
                naoTerminais.push_back(novoNaoTerminal);
                nt = true;
                parse = "";
            } else if (!parse.empty()) {
                // Adiciona regra ao não terminal atual
                naoTerminais.back().adicionarRegra(parse);
                parse = "";
            }
        } else if (c != '|' && c != '-' && c != '>') {
            // Constrói o nome do não terminal ou regra
            parse += c;
        }
    }
    if (!parse.empty()) {
        naoTerminais.back().adicionarRegra(parse);
    }
}

void Gramatica::resolverNaoImediataRE(NaoTerminal& A, NaoTerminal& B) {
    string nomeA = A.getNome();
    string nomeB = B.getNome();

    vector<string> regrasA, regrasB, novasRegrasA;
    regrasA = A.getRegras();
    regrasB = B.getRegras();

    for (const auto& regra : regrasA) {
        if (regra.substr(0, nomeB.size()) == nomeB) {
            // Substitui regras em A que começam com B pelas regras de B
            for (const auto& regra1 : regrasB) {
                novasRegrasA.push_back(regra1 + regra.substr(nomeB.size()));
            }
        } else {
            novasRegrasA.push_back(regra);
        }
    }
    A.setRegras(novasRegrasA);
}

void Gramatica::resolverImediataRE(NaoTerminal& A) {
    string nome = A.getNome();
    string novoNome = nome + "'";

    vector<string> alphas, betas, regras, novasRegrasA, novasRegrasA1;
    regras = A.getRegras();

    for (const auto& regra : regras) {
        if (regra.substr(0, nome.size()) == nome) {
            // Separa as regras que têm recursão à esquerda (alphas) e as demais (betas)
            alphas.push_back(regra.substr(nome.size()));
        } else {
            betas.push_back(regra);
        }
    }

    if (!alphas.size()) {
        // Se não há recursão à esquerda, sai da função
        return;
    }

    if (!betas.size()) {
        // Se não há betas, adiciona novo não terminal ao final das regras de A
        novasRegrasA.push_back(novoNome);
    }

    for (const auto& beta : betas) {
        // Adiciona novo não terminal ao final das regras de beta
        novasRegrasA.push_back(beta + novoNome);
    }

    for (const auto& alpha : alphas) {
        // Adiciona novo não terminal ao final das regras de alpha
        novasRegrasA1.push_back(alpha + novoNome);
    }

    // Atualiza as regras de A
    A.setRegras(novasRegrasA);
    novasRegrasA1.push_back("ε");  // Adiciona regra vazia

    // Adiciona novo não terminal com as regras alpha + novoNome
    NaoTerminal novoNaoTerminal(novoNome);
    novoNaoTerminal.setRegras(novasRegrasA1);
    naoTerminais.push_back(novoNaoTerminal);
}

void Gramatica::aplicarAlgoritmo() {
    size_t size = naoTerminais.size();
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < i; j++) {
            // Para cada par (A, B) onde i > j, resolve recursão à esquerda não imediata
            resolverNaoImediataRE(naoTerminais[i], naoTerminais[j]);
        }
        // Para cada não terminal, resolve recursão à esquerda imediata
        resolverImediataRE(naoTerminais[i]);
    }
}

pair<string, string> Gramatica::novasRegras() {
    string gramatica = "";
    string derivada = "";
    DerivacaoEsquerda derivacao;
    for (const auto& naoTerminal : naoTerminais) {
        // Adicione as novas regras
        gramatica += naoTerminal.novasRegras();
        derivacao.adicionarRegra(naoTerminal.novasRegras());
        gramatica += "\n";
    }
    derivada = derivacao.derivaraEsquerda();
    return make_pair(gramatica, derivada);
}
