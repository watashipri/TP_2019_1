#include <iostream>
#include "Abre_arquivo.h"

using namespace std;

int main(){

    Abre_arquivo A;

    int qtd_arquivos;
    cout << "Quantos arquivos deseja abrir?" << endl;
    cin >> qtd_arquivos;

    for(int i = 1; i <= qtd_arquivos; i++){
        A.Abrearquivo();
        A.ListaDocumentos();

        A.Fechaaquivo();
    }
//    A.Contagemlinhas();
//    A.Getlinhas();


//    string palavra;
//    cin>>palavra;
//    A.Tratamento(palavra);



    cout << "palavra buscada:" << endl;
    string palavra_user;
    cin >> palavra_user;
    A.Pesquisa(palavra_user);
//
//    A.Coordenadas(palavra_user);
//
//    A.Ranking();



    return 0;
}
