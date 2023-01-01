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
        livro(int idLivro, string nomeLivro, string autorLivro, int idadeMinimaLivro); // construtor basico (define quemTem/dataRetirada como -1 )
        void verDados(); // printa todos os dados do livro (e da retirada, caso esteja retirado)

        //inutil?::: bool atualizar();
        bool atualizar(int idLivro, string nomeLivro, string autorLivro, int idadeMinimaLivro);
        bool atualizar(int idLivro, string nomeLivro, string autorLivro, int idadeMinimaLivro, int quemTemLivro, time_t dataRetiradaLivro);
        // atualiza os dados do livro (precisa de protecao caso o usuario coloque um dado errado)


        bool retirar(int idUsuario);
        bool devolver(int idUsuario);

        int getId(); // id do livro
        string getNome(); // nome do livro
        string getAutor(); // nome do autor
        int getIdadeMinima(); // caso o livro nao seja livre para todos
        int getQuemTem(); // id do usuario
        time_t getDataRetirada(); // data armazenada


    private:
        int id; // id do livro
        string nome; // nome do livro
        string autor; // nome do autor
        int idadeMinima; // caso o livro nao seja livre para todos
        int quemTem; // id do usuario
        time_t dataRetirada; // data armazenada
        // (get usando time(0))
        // precisa converter usando ctime(&dataRetirada) se for dar display


};

// sobrecarga de operador para mostrar objeto
std::ostream& operator << (std::ostream&saida,livro &l);

#endif // LIVRO_H
