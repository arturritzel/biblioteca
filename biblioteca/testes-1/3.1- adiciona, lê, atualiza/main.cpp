#include <iostream>
#include <fstream>
#include <string>
//#include <string.h>
#include <locale>
#include <cmath>
#include <ctime>

#include "livro.h"

using namespace std;

#define MAXCHAR 200
#define QuantidadeDadosLivro 5 // nome, autor, idade minima, quemTem, data retirada

string entradaDado[3] = {"nome", "autor", "idade minima"};

enum biblioErro{

    ERR_SUCESSO = -10, // sucesso
    ERR_OPEN, // erro de abertura do arquivo
    ERR_INPUT, // erro de entrada do usuario

};

/*
Modos de abertura Descrição
ios::in Abre para leitura (default de ifstream).
ios::out Abre para gravação (default de ofstream),
ios::ate Abre e posiciona no final do arquivo.
(Este modo trabalha com leitura e gravação)
ios::app Grava a partir do fim do arquivo
ios::trunc Abre e apaga todo o conteúdo do arquivo
ios::nocreate Erro de abertura se o arquivo não existe
ios::noreplace Erro de abertura se o arquivo existir
ios::binary Abre em binário (default é texto)
*/

int qtdObjetos(char arquivo_leitura[], int qtdItensPorObjeto){

    ifstream inFile; // cria variavel para o arquivo para leitura de dados
    inFile.open(arquivo_leitura, ios::in); // abre o arquivo em modo de leitura

    if(!inFile) return ERR_OPEN;

    char linha[MAXCHAR];
    int linhas = 0;
    while (inFile.getline(linha,MAXCHAR)) linhas++; // conta a quantidade de linhas no arquivo

    return (int)(ceil(linhas/qtdItensPorObjeto));
}

int leituraLivro(char arquivo_leitura[], livro *livros){

    ifstream inFile; // cria variavel para o arquivo para leitura de dados
    inFile.open(arquivo_leitura, ios::in); // abre o arquivo em modo de leitura

    if(!inFile){ // testa se o arquivo foi aberto corretamente
        cerr << "erro ao abrir o arquivo " << arquivo_leitura << endl;
        return ERR_OPEN;
    }

    char linha[MAXCHAR];
    int contagem = 0;

    int tempIdade, tempQuem, tempData; // variaveis temporarias
    string tempNome, tempAutor;

    while(inFile.getline(linha,MAXCHAR)){

        if(contagem%QuantidadeDadosLivro == 0) tempNome = linha; // caso seja a primeira linha do livro atual
        if(contagem%QuantidadeDadosLivro == 1) tempAutor = linha; // caso seja a segunda linha do livro atual
        if(contagem%QuantidadeDadosLivro == 2) tempIdade = atoi(linha); // etc
        if(contagem%QuantidadeDadosLivro == 3) tempQuem = atoi(linha);
        if(contagem%QuantidadeDadosLivro == 4){tempData = atoi(linha);

            livros[(int)(ceil(contagem/QuantidadeDadosLivro))].atualizar((int)(ceil(contagem/QuantidadeDadosLivro)), tempNome, tempAutor, tempIdade, tempQuem, tempData);
        }
        contagem++;


        /// * debugging
        //cout << contagem << ": " << linha << endl;
        /// *
    }

    return ERR_SUCESSO;
}

int gravuraLivro(char arquivo_gravura[]){

    string temp;
    getline(cin, temp); // pega lixo da ultima entrada

    string digitar[sizeof(entradaDado)/sizeof(entradaDado[0])]; // cria strings para a quantidade de dados de entrada
    for(int i = 0; i < sizeof(entradaDado)/sizeof(entradaDado[0]); i++){
        cout << "entre " << entradaDado[i] << " do livro: ";
        getline(cin, digitar[i]);
    }



    ofstream outFile; // cria variavel para o arquivo para leitura de dados
    outFile.open(arquivo_gravura, ios::out|ios::app); // abre o arquivo em modo de gravacao

    if(!outFile){ // testa se o arquivo foi aberto corretamente
        cerr << "erro ao abrir o arquivo " << arquivo_gravura << endl;
        return ERR_OPEN;
    }

    for(int i = 0; i < sizeof(entradaDado)/sizeof(entradaDado[0]); i++)
        outFile << digitar[i] << endl;

    outFile << -1 << endl << -1 << endl;

    outFile.close();
    return ERR_SUCESSO;
}

int atualizaLivro(char arquivo_gravura[], livro *livros, int qtdLivros){

    int id_para_atualizar;
    cout << "atualizar o livro com qual id?" << endl;
    cout << "id: "; cin >> id_para_atualizar;

    string digitar[sizeof(entradaDado)/sizeof(entradaDado[0])]; // cria strings para a quantidade de dados de entrada
    getline(cin, digitar[0]); // pega lixo da ultima entrada

    for(int i = 0; i < sizeof(entradaDado)/sizeof(entradaDado[0]); i++){ // recebe no codigo os dados
        cout << "entre " << entradaDado[i] << " do livro: ";
        getline(cin, digitar[i]);
    }

    livros[id_para_atualizar].atualizar(id_para_atualizar, digitar[0], digitar[1], stoi(digitar[2]));



    ofstream outFile; // cria variavel para o arquivo para leitura de dados
    outFile.open(arquivo_gravura, ios::out|ios::trunc); // abre o arquivo em modo de gravacao

    if(!outFile){ // testa se os arquivos foram abertos corretamente
        cerr << "erro ao abrir o arquivos de leitura" << endl;
        return ERR_OPEN;
    }

    for(int i = 0; i < qtdLivros; i++)
        outFile << livros[i];

    outFile.close();
    cout << "livro atualizado com sucesso." << endl;
    return ERR_SUCESSO;

}

int deletaLivro(char arquivo_gravura[], livro *livros, int qtdLivros){

    int id_para_deletar;
    cout << "deletar o livro com qual id?" << endl;
    cout << "id: "; cin >> id_para_deletar;

    ofstream outFile; // cria variavel para o arquivo para leitura de dados
    outFile.open(arquivo_gravura, ios::out|ios::trunc); // abre o arquivo em modo de gravacao e trunc (limpa o arquivo)

    if(!outFile){ // testa se os arquivos foram abertos corretamente
        cerr << "erro ao abrir o arquivos de leitura" << endl;
        return ERR_OPEN;
    }

    for(int i = 0; i < qtdLivros; i++){
        if(i != id_para_deletar) outFile << livros[i]; // grava o livro no arquivo caso nao seja o livro a ser deletado
    }


    outFile.close();
    cout << "livro deletado com sucesso." << endl;
    return ERR_SUCESSO;

}

int main(){

    /* conversao de tempo (utilizado no momento da retirada)
    pegar data atual
    time_t now = time(0);
    char* date_time = ctime(&now);
    cout << "now> " << now << endl;
    cout << "The current date and time is: " << date_time << endl;
    */


    char arquivo[] = "dadosLivros.txt";

    int temp = -1;
    while(temp != 9){

        /// leitura dos livros no arquivo
        int qtdLivros = qtdObjetos(arquivo, QuantidadeDadosLivro);
        if(qtdLivros == ERR_OPEN)
                return ERR_OPEN;

        livro livros[qtdLivros];
        if(leituraLivro(arquivo, livros) == ERR_OPEN)
            return ERR_OPEN;
        /// /////////////////////

        cout << endl
             << "digite 0 para ler um livro, 1 para ler todos os livros" << endl
             << "digite 2 para adicionar um livro, 3 para atualizar um livro, 4 para deletar um livro" << endl;

        cin >> temp; cout << endl;

        if(temp == 0){

            int x;
            cout << "digite o id do livro a ser lido: "; cin >> x; cout << x;
            while(x >= qtdLivros || x < 0){
                cout << "impossivel ler o livro com id " << x << ": o id deve ser um numero entre 0 e " << qtdLivros-1 << "." << endl;
                cout << "digite o id novamente: "; cin >> x;
            }
            livros[x].verDados();
        }

        if(temp == 1){

            for(int i = 0; i < sizeof(livros)/sizeof(livros[0]); i++)
                livros[i].verDados();
        }

        if(temp == 2){

            if(gravuraLivro(arquivo) == ERR_OPEN)
                return ERR_OPEN;
        }

        if(temp == 3){

            if(atualizaLivro(arquivo, livros, qtdLivros) == ERR_OPEN)
                return ERR_OPEN;
        }

        if(temp == 4){

            if(deletaLivro(arquivo, livros, qtdLivros) == ERR_OPEN)
                return ERR_OPEN;
        }
    }

    return ERR_SUCESSO;
}
