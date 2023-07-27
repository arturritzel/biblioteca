#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "livro.h"

#include <fstream>
#include <sstream> // std:: istringstream
#include <vector>

class Biblioteca
{
    public:
        static void LivrosParaArquivo(std::vector<Livro> livros, std::string filename);
        static std::vector<Livro> ArquivoParaLivros(std::string filename);

    private:
        static std::vector<std::string> LinhaParaDados(std::string linha, char divisor);

    protected:
};

#endif // BIBLIOTECA_H
