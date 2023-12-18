#include "DerivacaoEsquerda.h"

void DerivacaoEsquerda::adicionarRegra(string regra) {
    // Encontrar a posição de "->" na regra
    size_t posicao = regra.find("->");
    string substring;

    // Adicionar o terminal ao vetor de terminais
    if (regra[1] == '\'')
        terminal.push_back(regra.substr(0, 2));
    else
        terminal.push_back(string(1, regra[0]));

    // Adicionar a produção ao vetor de produções
    if (posicao != string::npos) {
        substring = regra.substr(posicao + 3);
        producoes.push_back(substring);
    }
}

string DerivacaoEsquerda::derivaraEsquerda() {
    size_t tamanho = terminal.size();
    string saida = "";
    string temporario = "";
    string derivada = "";
    size_t posicao;
    bool tenhoUmaProducao = false;

    for (size_t i = 0; i < tamanho; i++) {
        for (size_t l = 0; l < producoes[i].size(); l++) {
            char c = producoes[i][l];

            if (c != ' ' && c != '|' && tenhoUmaProducao == false) {
                // Construir a string 'saida' até encontrar um espaço, barra vertical ou produção
                saida += c;
            } else if (!saida.empty()) {
                derivada = saida;
                tenhoUmaProducao = true;

                for (size_t j = 0; j < tamanho; j++) {
                    string& str = terminal[j];

                    // Lidar com o caractere especial ' (apóstrofo)
                    if (derivada.find('\'') != string::npos) {
                        posicao = terminal[j].find('\'');

                        if (posicao != string::npos) {
                            if (derivada.find(terminal[j]) != string::npos) {
                                posicao = derivada.find(terminal[j]);
                            }
                        }
                    } else {
                        // Encontrar a posição da produção atual no derivada
                        posicao = derivada.find(str);
                    }

                    if (posicao != string::npos) {
                        for (size_t k = 0; k < producoes[j].size(); k++) {
                            char p = producoes[j][k];

                            if (p != ' ' && p != '|') {
                                // Construir temporario até encontrar um espaço ou barra vertical
                                temporario += p;
                            }

                            if (p == ' ' || k == producoes[j].size() - 1) {
                                // Se a produção não estiver na derivada, substituir
                                if (derivada.find(temporario) == string::npos) {
                                    derivada.replace(posicao, str.size(), temporario);
                                    temporario.clear();
                                    j = 0;  // Reiniciar o loop externo
                                }

                                temporario.clear();
                            }
                        }
                    }
                    // Break após derivar completamente a string
                    break;
                }
            }

            if (l == producoes[i].size() - 1 && !saida.empty()) {
                tenhoUmaProducao = true;
                derivada = saida;

                for (size_t j = 0; j < tamanho; j++) {
                    string& str = terminal[j];

                    // Lidar com o caractere especial ' (apóstrofo)
                    if (derivada.find('\'') != string::npos) {
                        posicao = terminal[j].find('\'');

                        if (posicao != string::npos) {
                            if (derivada.find(terminal[j]) != string::npos) {
                                posicao = derivada.find(terminal[j]);
                            }
                        }
                    } else {
                        // Encontrar a posição da produção atual no derivada
                        posicao = derivada.find(str);
                    }

                    if (posicao != string::npos) {
                        for (size_t k = 0; k < producoes[j].size(); k++) {
                            char p = producoes[j][k];

                            if (p != ' ' && p != '|') {
                                // Construir temporario até encontrar um espaço ou barra vertical
                                temporario += p;
                            }

                            if (p == ' ' || k == producoes[j].size() - 1) {
                                // Se a produção não estiver na derivada, substituir
                                if (derivada.find(temporario) == string::npos) {
                                    derivada.replace(posicao, str.size(), temporario);
                                    temporario.clear();
                                    j = 0;  // Reiniciar o loop externo
                                }

                                temporario.clear();
                            }
                        }
                    }
                }
            }
        }
    }

    terminal.clear();
    producoes.clear();

    return derivada;
}