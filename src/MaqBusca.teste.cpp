#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "MaqBusca.h"
#include "doctest.h"

#include <algorithm>
#include <iostream>
#include <limits>
#include <cmath>

using std::string;

class Teste {
public:
    static string* arquivo(const MaqBusca &c) {
        return  c.nomearquivo_;
    }
    static int linha(const MaqBusca &c) {
        return  c.linhas_;
    }
//    static map indice(const MaqBusca &c) {
//        return  c.indiceinvertido;
//    }
//    static map contagem(const MaqBusca &c) {
//        return  c.contagempalavra;
//    }
    static double coordenada(const MaqBusca &c) {
        return  c.coordenadaW;
    }
    static ifstream leitura(const MaqBusca &c) {
        return  c.leitura;
    }
};


TEST_SUITE("MaqBusca") {
  TEST_CASE("MaqBusca") {
    MaqBusca m;
    CHECK(Teste::linhas_(m)==0);
    CHECK(Teste::coordenadaW(m) = 0);
  }

  TEST_CASE("Abrearquivo"){

  }
  TEST_CASE("Fechaaquivo"){}


  TEST_CASE("Tratamento"){
  }

  TEST_CASE("IndiceInvertido"){}
  TEST_CASE("ImprimirMap - int"){}
  TEST_CASE("ImprimirMap - vector"){}
  TEST_CASE("Pesquisa"){}
  TEST_CASE("Coordenadas"){}
  TEST_CASE("Ranking"){}
}
