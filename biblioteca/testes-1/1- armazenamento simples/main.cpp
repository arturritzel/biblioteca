#include <iostream>
#include <fstream>
#include <string>
//#include <string.h>
#include <locale>
#include <cmath>

using namespace std;

#define MAXCHAR 200

struct item{
    string fruta;
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

int leitura(char arquivo_leitura[]){
    ifstream inFile; // cria variavel para o arquivo para leitura de dados
    inFile.open(arquivo_leitura, ios::in); // abre o arquivo em modo de leitura

    if(!inFile){ // testa se o arquivo foi aberto corretamente
        cerr << "erro ao abrir o arquivo " << arquivo_leitura << endl;
        return -1;
    }

    else cout << "deu" << endl;

    char linha[MAXCHAR];
    int linhas = 0;
    while (inFile.getline(linha,MAXCHAR)) linhas++; // conta a quantidade de linhas no arquivo

    inFile.clear(); // volta o ponteiro de leitura do arquivo para a posicao inicial
    inFile.seekg(0);

    cerr << "1";

    int contagem = 0;

    item itens[(int)(ceil(linhas/3))]; // cria 'itens' de acordo com a quantidade de linhas (um item a cada 3 linhas)

    cerr << "2";

    while(inFile.getline(linha,MAXCHAR)){
            if(contagem%3 == 2) itens[(int)(ceil(contagem/3))].fruta = linha;

            cout << contagem << ": " << linha << endl;
            contagem++;
    }

    cerr << "3";

    cout << endl;

    for(int i = 0; i < linhas/3; i++){
        cout << itens[i].fruta << endl;
    }

    return 0;
}

int main(){
    char arquivo[] = "dados.txt";

    int temp = 0;

    cerr << "0";
    while(temp < 3);
        cout << "digite 1 para ler itens, 2 para criar itens ou 3 para fechar" << endl;
        cin >> temp; cout << endl;

        if(temp == 1){
            if(leitura(arquivo) == -1){ // testa se o arquivo foi aberto corretamente
                cerr << "erro ao abrir o arquivo " << arquivo << endl;
                return 0;
            }
        }

        if(temp == 2){
            //escrita();
        }

        if(temp == 3){
            return 0;
        }

}
