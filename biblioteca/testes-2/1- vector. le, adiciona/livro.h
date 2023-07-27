#ifndef LIVRO_H
#define LIVRO_H

#include <string>
#include <ctime>

class Livro
{
    public:
        Livro(std::string entradaTitulo, std::string entradaAutor);
        Livro(std::string entradaTitulo, std::string entradaAutor, unsigned int entradaIdadeMinima);
        Livro(std::string entradaTitulo, std::string entradaAutor, unsigned int entradaIdadeMinima, time_t entradaDataRetirada, int entradaQuemTem);
        ~Livro();

        std::string to_string();

        std::string getTitulo() { return titulo; }
        std::string getAutor() { return autor; }
        unsigned int getIdadeMinima() { return idadeMinima; }
        time_t getDataRetirada() { return dataRetirada; }
        int getQuemTem() { return quemTem; }

    protected:

    private:
        std::string titulo;
        std::string autor;
        unsigned int idadeMinima;
        time_t dataRetirada;
        int quemTem;
};

#endif // LIVRO_H
