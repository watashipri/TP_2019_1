#include <iostream>
#include "MaqBusca.h"

using namespace std;

int main(){
    MaqBusca A;

    int qtd_arquivos;
    cout << "Quantos arquivos deseja abrir?" << endl;
    cin >> qtd_arquivos;

    while(qtd_arquivos < 0){
        cout << "Quantidade nao valida. Insira um numero maior que zero" << endl;
        cin >> qtd_arquivos;
    }

    for(int i = 1; i <= qtd_arquivos; i++){
        A.Abrearquivo();
        A.IndiceInvertido();
        A.Fechaaquivo();
    }

    cout << "Palavra Buscada: ";
    string palavra_user;
    cin >> palavra_user;
    A.Pesquisa(A.Tratamento(palavra_user));

    A.Coordenadas(palavra_user, qtd_arquivos);

    A.Ranking();

    return 0;
}
