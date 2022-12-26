#include "livro.h"
#include <iostream>

using namespace std;

livro::livro() // construtor
{
    id = -1;
    nome = "temp";
    autor = "temp";
    idadeMinima = -1;

    quemTem = -1; // nao ta com ninguem
    dataRetirada = 0; // qualquer valor; nao importa, já que ninguem tem o livro
}

livro::livro(int idLivro, string nomeLivro, string autorLivro, int idadeMinimaLivro) // construtor
{
    id = idLivro;
    nome = nomeLivro;
    autor = autorLivro;
    idadeMinima = idadeMinimaLivro;

    quemTem = -1; // nao ta com ninguem
    dataRetirada = 0; // qualquer valor; nao importa, já que ninguem tem o livro
}

void livro::verDados(){
    cout << endl;
    cout << nome << ", por " << autor << " [ID " << id << "]" << endl;

    if(idadeMinima > 0);
        cout << "idade mínima para retirada: " << idadeMinima << " anos." << endl;
    if(quemTem > -1)
        cout << "Livro retirado por " << quemTem << " em " << ctime(&dataRetirada) << endl;
    else cout << "Esse livro não está retirado." << endl;
}

bool livro::atualizar(){ // atualizacao com cin e auxilio
}

bool livro::atualizar(int idLivro, string nomeLivro, string autorLivro, int idadeMinimaLivro){ // atualizacao sem cin e auxilio
}

bool livro::atualizar(int idLivro, string nomeLivro, string autorLivro, int idadeMinimaLivro, int quemTemLivro, time_t dataRetiradaLivro){
    id = idLivro;
    nome = nomeLivro;
    autor = autorLivro;
    idadeMinima = idadeMinimaLivro;
    quemTem = quemTemLivro;
    dataRetirada = dataRetiradaLivro;
}

int livro::getQuemTem(){
    return quemTem;
}

bool livro::retirar(int idUsuario){
}

bool livro::devolver(int idUsuario){
}
