#include <iostream>
#include "Abre_arquivo.h"

using namespace std;

int main(){

    Abre_arquivo A;
    A.Abrearquivo();
//    A.Contagemlinhas();
//    A.Getlinhas();


//    string palavra;
//    cin>>palavra;
//    A.Tratamento(palavra);

    A.ListaDocumentos();

    cout << "palavra buscada:" << endl;
    string palavra_user;
    cin >> palavra_user;
//    A.Pesquisa(palavra_user);

    A.Coordenadas(palavra_user);

    A.Fechaaquivo();

    return 0;
}
