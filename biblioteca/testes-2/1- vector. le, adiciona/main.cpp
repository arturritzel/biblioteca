#include <iostream>


#include "biblioteca.h"
#include <vector>

#define ARQUIVO_LIVROS "livros.txt"

/// transformar isso em sobrecarga de operador
void displayLivros(std::vector<Livro> livros){
    for(Livro livro : livros){
        time_t data = livro.getDataRetirada();
        std::cout << "Titulo: " << livro.getTitulo()
                  << " / Autor: " << livro.getAutor()
                  << " / Idade Minima: " << livro.getIdadeMinima()
                  << " // " << livro.getQuemTem()
                  << " em " << ctime(&data);
                  /* << std::endl; */ /// tirando a nova linha pq o ctime termina em \n (tem q colocar dnv dps q fazer um metodo pra formatar essa data em ptbr)
    }
}

int main()
{
    int comando = -2;
    while(comando != -1){
        std::cout << std::endl << "-1 para encerrar / 0 para ler / 1 para adicionar / 2 para limpar" << std::endl;

        std::cout << "entrada: ";
        std::string input;
        getline(std::cin, input);

        try{ comando = std::stoi(input); }
        catch(const std::invalid_argument& e){ std::cout << "erro: entrada invalida (" << e.what() << ")" << std::endl; }
        catch(...){ std::cout << "erro desconhecido" << std::endl; }

        switch(comando){
        case 0:
            { // para nao surgirem problemas com variaveis ja declaradas
                std::vector<Livro> livros = Biblioteca::ArquivoParaLivros(ARQUIVO_LIVROS);
                displayLivros(livros);

                break;
            }
        case 1:
            {
                std::vector<Livro> livros = Biblioteca::ArquivoParaLivros(ARQUIVO_LIVROS);
                std::string inpTitulo, inpAutor;

                std::cout << "titulo: ";
                getline(std::cin, inpTitulo);

                std::cout << "autor: ";
                getline(std::cin, inpAutor);
                std::cout << std::endl;

                livros.emplace_back(inpTitulo, inpAutor);
                Biblioteca::LivrosParaArquivo(livros, ARQUIVO_LIVROS);

                break;
            } // case 2
        } // switch
    } // while
} // main
