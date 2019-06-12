#ifndef ABRE_ARQUIVO_H
#define ABRE_ARQUIVO_H

#include <iostream>
#include <fstream>
#include <string>

#include <cctype>
#include <algorithm>

#include <map>

using std::iostream;
using std::ifstream;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ptr_fun;
using std::map;
using std::pair;

class Abre_arquivo{
    public:
        Abre_arquivo();
        ~Abre_arquivo();
        void Abrearquivo();
        void Fechaaquivo();
        void Contagemlinhas();
        void Getlinhas();
        string Tratamento(string palavra);
        void ListaDocumentos();
        void ImprimirMap(map<string, int> m);
        void ImprimirMap(map<string, string> m);
        void Pesquisa(string palavra);
        void Coordenadas(string palavra_user);
//        void Ranking();


    private:
        string nomearquivo_;
        ifstream leitura;
        int linhas_;
        map <string, string> indiceinvertido;
        map <string, int> contagempalavra;
};

#endif // ABRE_ARQUIVO_H
