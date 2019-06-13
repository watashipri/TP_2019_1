#ifndef ABRE_ARQUIVO_H
#define ABRE_ARQUIVO_H

#include <iostream>
#include <fstream>

#include <string>
#include <cmath>

#include <cctype>
#include <algorithm>

#include <map>
#include <vector>

using std::iostream;
using std::ifstream;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ptr_fun;
using std::map;
using std::vector;
//using std::push_back;
using std::pair;
using std::sqrt;
using std::pow;

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
        void ImprimirMap(map<string, vector<string>> m);
        void Pesquisa(string palavra);
        void Coordenadas(string palavra_user);
        double Ranking();


    private:
        string nomearquivo_;
        ifstream leitura;
        int linhas_;
        map <string, vector<string>> indiceinvertido;
        map <string, int> contagempalavra;
        double coordenadaW;
};

#endif // ABRE_ARQUIVO_H
