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

    ERR_SUCESSO, // sucesso
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

int leituraLivro(char arquivo_leitura[]){
    ifstream inFile; // cria variavel para o arquivo para leitura de dados

    inFile.open(arquivo_leitura, ios::in); // abre o arquivo em modo de leitura

    if(!inFile){ // testa se o arquivo foi aberto corretamente
        cerr << "erro ao abrir o arquivo " << arquivo_leitura << endl;
        return ERR_OPEN;
    }

    char linha[MAXCHAR];
    int linhas = 0;
    while (inFile.getline(linha,MAXCHAR)) linhas++; // conta a quantidade de linhas no arquivo

    inFile.clear(); // volta o ponteiro de leitura do arquivo para a posicao inicial
    inFile.seekg(0);

    int contagem = 0;

    livro livros[(int)(ceil(linhas/QuantidadeDadosLivro))]; // cria 'livros' de acordo com a quantidade de linhas (um livro a cada ciclo completo de dados)

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

        /// *debugging
        cout << contagem << ": " << linha << endl;
        contagem++;
    }

    cout << endl;

    cout << "linhas no arquivo: " << linhas << endl << endl;
    /// debugging*

    for(int i = 0; i < (int)(ceil(linhas/QuantidadeDadosLivro)); i++){
        livros[i].verDados();
    }

    cout << endl;
    inFile.close();
    return ERR_SUCESSO;
}

int gravuraLivro(char arquivo_gravura[]){

    ofstream outFile; // cria variavel para o arquivo para leitura de dados
    outFile.open(arquivo_gravura, ios::out|ios::app); // abre o arquivo em modo de gravacao

    if(!outFile){ // testa se o arquivo foi aberto corretamente
        cerr << "erro ao abrir o arquivo " << arquivo_gravura << endl;
        return ERR_OPEN;
    }

    string temp;
    getline(cin, temp); // pega lixo da ultima entrada

    string digitar[sizeof(entradaDado)/sizeof(entradaDado[0])]; // cria strings para a quantidade de dados de entrada
    for(int i = 0; i < sizeof(entradaDado)/sizeof(entradaDado[0]); i++){
        cout << "entre " << entradaDado[i] << " do livro: ";
        getline(cin, digitar[i]);
    }

    for(int i = 0; i < sizeof(entradaDado)/sizeof(entradaDado[0]); i++)
        outFile << digitar[i] << endl;

    outFile << -1 << endl << -1 << endl;

    outFile.close();
    return ERR_SUCESSO;
}

int atualizaLivro(char arquivo_leitura[]){

    ofstream outFile; // cria variavel para o arquivo para gravacao de dados
    ifstream inFile; // cria variavel para o arquivo para leitura de dados

    inFile.open(arquivo_leitura, ios::in); // abre o arquivo em modo de leitura

    // definindo o nome do arquivo de saida
    string arquivo_gravura = arquivo_leitura; // copia o nome do arquivo para outra string
    arquivo_gravura.insert(arquivo_gravura.rfind("."), "_temp"); // adiciona '_temp' antes do ultimo '.' no nome do arquivo
    // exemplo: 'arquivo.wav' ira se tornar 'arquivo_temp.wav'

    outFile.open(arquivo_gravura, ios::out); // abre o arquivo em modo de gravacao

    if(!inFile || !outFile){ // testa se os arquivos foram abertos corretamente
        cerr << "erro ao abrir os arquivos de leitura/gravacao" << endl;
        return ERR_OPEN;
    }

    int linha = 0;
    cout << "atualizar o livro com qual id?" << endl;
    cout << "id: "; cin >> linha;
    linha *= QuantidadeDadosLivro; // cada livro ocupa 5 linhas no arquivo dos dados

    int atual = 0; // contagem atual de linhas

    char temp1[MAXCHAR]; // variavel temporaria
    while(atual < linha){ // copia as linhas do arquivo original para o arquivo temporario ate chegar nas linhas que devem ser modificadas
            inFile.getline(temp1, MAXCHAR);
            outFile << temp1 << endl;
            atual++;
    }

    string temp;
    getline(cin, temp); // pega lixo da ultima entrada

    string digitar[sizeof(entradaDado)/sizeof(entradaDado[0])]; // cria strings para a quantidade de dados de entrada
    for(int i = 0; i < sizeof(entradaDado)/sizeof(entradaDado[0]); i++){ // recebe no codigo os dados
        cout << "entre " << entradaDado[i] << " do livro: ";
        getline(cin, digitar[i]);
    }

    for(int i = 0; i < sizeof(entradaDado)/sizeof(entradaDado[0]); i++) // entra no arquivo os dados
        outFile << digitar[i] << endl;

    outFile << -1 << endl << -1 << endl; // entra no arquivo os dados de quem esta com o livro

    for(int i = 0; i < 5; i++) inFile.getline(temp1,MAXCHAR); // le as linhas antigas no arquivo original (pra passar o ponteiro pra frente)

    while(inFile.getline(temp1,MAXCHAR)) outFile << temp1 << endl; // copia as linhas finais do arquivo (mesmo método do inicio do arquivo

    outFile.close(); // fecha os arquivos
    inFile.close();

    if(remove(arquivo_leitura) != 0) // apaga o arquivo original
        perror("erro deletando o arquivo de leitura");
    if(rename(arquivo_gravura.c_str(), arquivo_leitura) != 0) // renomeia o arquivo temporario para o arquivo original (substituindo)
        perror("erro renomeando o arquivo de gravacao");
    return ERR_SUCESSO;
}

int main(){

    /*
    pegar data atual
    time_t now = time(0);
    char* date_time = ctime(&now);
    cout << "now> " << now << endl;
    cout << "The current date and time is: " << date_time << endl;
    */


    char arquivo[] = "dadosLivros.txt";

    int temp = 0;

    while(temp != 9){
        cout << endl << "digite 1 para ler livros, 2 para criar livros ou 9 para fechar" << endl;
        cin >> temp; cout << endl;

        if(temp == 1){
            if(leituraLivro(arquivo) == ERR_OPEN){ // testa se o arquivo foi aberto corretamente
                return ERR_OPEN;
            }
        }

        if(temp == 2){
            if(gravuraLivro(arquivo) == ERR_OPEN){ // testa se o arquivo foi aberto corretamente
                return ERR_OPEN;
            }
        }

        if(temp == 3){
            if(atualizaLivro(arquivo) == ERR_OPEN){ // testa se o arquivo foi aberto corretamente
                return ERR_OPEN;
            }
        }
    }

    return ERR_SUCESSO;
}
