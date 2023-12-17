#include <iostream>
#include <limits>
#include <cstdlib>

using namespace std;

#include "Gramatica.h"
#include "DerivacaoEsquerda.h"

using namespace std;

void limparTerminal() {
    system("cls");
}

void menu() {
    int input = 0;
    string producoes;
    string producoesInseridas;
    pair<string, string> producoesSemREStrDerivada;
    Gramatica gramatica;
    DerivacaoEsquerda derivacao;

    while (input != 2) {
        limparTerminal();
        cout << "1) Digitar producoes" << endl;
        cout << "2) Encerrar programa" << endl;

        // Verificar se a entrada é válida
        while (!(cin >> input) || (input < 1 || input > 2)) {
            cin.clear();  // Limpar o estado do cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descartar entrada inválida
            cout << "Entrada inválida. Digite novamente: ";
        }

        while (input == 1) {
            limparTerminal();
            cout << "Digite a producao no seguinte formato: S -> Aa | b\n";

            // Limpar o buffer antes de receber a entrada
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            getline(cin, producoes);

            producoesInseridas += producoes+"\n";

            derivacao.adicionarRegra(producoes);

            gramatica.adicionarRegra(producoes);

            limparTerminal();

            cout << "Deseja adicionar outra producao? (1, 0): ";

            // Verificar se a entrada é válida
            while (!(cin >> input) || (input < 0 || input > 1)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Entrada inválida. Digite novamente: ";
            }

            limparTerminal();

            if(input==0){
                limparTerminal();
                cout<<"Gramatica Inserida"<<endl;
                cout<<producoesInseridas;

                cout<<"String derivada mais a esquerda da gramática inserida"<<endl;
                cout << derivacao.derivaraEsquerda() << endl;

                cout<<"\nGramatica sem Recursao a Esquerda"<<endl;
                gramatica.aplicarAlgoritmo();
                producoesSemREStrDerivada = gramatica.novasRegras();
                cout << producoesSemREStrDerivada.first;
                cout<<"String derivada mais a esquerda da gramática inserida (desconsidere o ε)"<<endl;
                cout << producoesSemREStrDerivada.second << endl;
    
                cout<<"\n3)Voltar ao menu"<<endl;
                 // Verificar se a entrada é válida
                while (!(cin >> input) || (input != 3)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada inválida. Digite novamente: ";
                }
            }

        }
        if (input == 2){
            limparTerminal();
            cout<<"Encerrando..."<<endl;
        }
    }
}

int main() {
    menu();
    return 0;
}
