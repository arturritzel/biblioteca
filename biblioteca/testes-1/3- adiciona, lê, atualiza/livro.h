#ifndef LIVRO_H
#define LIVRO_H

#include <fstream>
#include <string>
#include <ctime>

using namespace std;


class livro
{
    public:
        livro();
        livro(int idLivro, string nomeLivro, string autorLivro, int idadeMinimaLivro); // construtor basico (define quemTem como -1 )
        // define dataRetirada com um valor aleatório, talvez 0. como ninguém retirou, esse valor não importa de fato
        void verDados(); // printa todos os dados do livro
        bool atualizar();
        bool atualizar(int idLivro, string nomeLivro, string autorLivro, int idadeMinimaLivro);
        bool atualizar(int idLivro, string nomeLivro, string autorLivro, int idadeMinimaLivro, int quemTemLivro, time_t dataRetiradaLivro);
        // atualiza os dados do livro (precisa de protecao caso o usuario coloque um dado errado)
        int getQuemTem(); // printa os dados da retirada: usuario, data, atrasado ou nao, multa, etc.
        bool retirar(int idUsuario);
        bool devolver(int idUsuario);


    private:
        int id;
        string nome; // nome do livro
        string autor; // nome do autor
        int idadeMinima; // caso o livro nao seja livre para todos
        int quemTem; // id do usuario
        time_t dataRetirada; // data armazenada
        // (get usando time(0))
        // precisa converter usando ctime(&dataRetirada) se for dar display


};

#endif // LIVRO_H
