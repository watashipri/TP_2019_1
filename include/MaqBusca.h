#ifndef MAQBUSCA_H
#define MAQBUSCA_H

#include <iostream>
#include <fstream>

#include <string>
#include <cmath>
#include <iomanip>

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
using std::pair;
using std::sqrt;
using std::pow;
using std::setprecision;
using std::fixed;

class MaqBusca{
    public:
        MaqBusca();
        ~MaqBusca();
        void Abrearquivo();
        void Fechaaquivo();
        void Contagemlinhas();
        void Getlinhas();
        string Tratamento(string palavra);
        void IndiceInvertido();
        void ImprimirMap(map<string, int> m);
        void ImprimirMap(map<string, vector<string>> m);
        void Pesquisa(string palavra);
        void Coordenadas(string palavra, int ndocs);
        double Ranking();

    private:
        string nomearquivo_;
        ifstream leitura;
        int linhas_;
        map <string, vector<string>> indiceinvertido;
        map <string, int> contagempalavra;
        double coordenadaW;

//        friend class Teste;
};

#endif // MAQBUSCA_H
