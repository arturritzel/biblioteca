#include "biblioteca.h"

std::vector<std::string> Biblioteca::LinhaParaDados(std::string linha, char divisor) {
    std::vector<std::string> dados;
    std::string dado;
    std::istringstream entradaDado(linha);
    while(std::getline(entradaDado, dado, divisor)) {
        dados.push_back(dado);
    }
    return dados;
}

void Biblioteca::LivrosParaArquivo(std::vector<Livro> livros, std::string filename){
    std::ofstream file(filename);

    if(file.is_open()){
        for(Livro livro : livros){
            file << livro.to_string() << std::endl;
        }
        file.close();
    }
    else{
        // nao deu pra abrir o arquivo?
    }
}

std::vector<Livro> Biblioteca::ArquivoParaLivros(std::string filename){
    std::vector<Livro> livros;
    std::ifstream file(filename);

    if(file.is_open()){
        std::string linha;
        while (std::getline(file, linha)) {
            std::vector<std::string> livroDados = LinhaParaDados(linha, ','); // assumindo q seja separado por virgula
            if (livroDados.size() == 5) {
                livros.emplace_back(livroDados[0], livroDados[1], std::stoul(livroDados[2]), std::stoll(livroDados[3]), std::stoi(livroDados[4]));
            }
        }
        file.close();
    }
    else{
        // nao abriu o arquivo ?
    }

    return livros;
}
