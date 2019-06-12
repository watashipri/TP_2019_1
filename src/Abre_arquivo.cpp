#include "Abre_arquivo.h"

Abre_arquivo::Abre_arquivo(){
    linhas_ = 0;
}

Abre_arquivo::~Abre_arquivo(){

}


void Abre_arquivo::Abrearquivo(){

            cout << "---------------------------------------------" << endl;
            cout << "Digite o nome do arquivo a ser aberto: \n" << "-> ";
            cin >> nomearquivo_;

           nomearquivo_ = nomearquivo_ + ".txt";

            leitura.open(nomearquivo_.c_str());
}

void Abre_arquivo::Fechaaquivo(){
    leitura.close();
    cout << "---->Fechamento do arquivo realizado com sucesso!" << endl;
}

// Verifica quantos linhas est�o no arquivo de entrada
void Abre_arquivo::Contagemlinhas(){
    ifstream contagem;
    string logs_;

    contagem.open(nomearquivo_.c_str());

    while(!contagem.eof()) {
        getline(contagem, logs_);
        linhas_++;
    }
    contagem.close();
}

void Abre_arquivo::Getlinhas(){
    cout << linhas_ << endl;
}

// Troca caixa alta para caixa baixa e remove caracteres
string Abre_arquivo::Tratamento(string palavra){
    transform(palavra.begin(), palavra.end(), palavra.begin(), ptr_fun <int, int> ( tolower ) );
    palavra.erase(remove_if(palavra.begin(), palavra.end(), [](char c){ return c==','||c=='.'|| c=='!'||
                            c=='-'|| c=='?'||c== ':' ||c== ';' ||c== 39 ||c== '[' ||c== ']' ||c== '{' ||c== '}' ||
                            c== '<' ||c== '>' ||c== '(' ||c== ')' ||c== '*' ||c== '%'||c== '&'; }), palavra.end());

    return palavra;
}


//
void Abre_arquivo::ListaDocumentos(){
    Abre_arquivo A;

    string palavra;
    string palavra_tratada;

    int i = 1;

    while (leitura >> palavra){
        palavra_tratada = A.Tratamento(palavra);

        indiceinvertido.insert(pair<string, string>(palavra_tratada, "doc1"));

        if (contagempalavra.find(palavra_tratada) == contagempalavra.end()){
            contagempalavra[palavra_tratada] = 1;
        } else {
            contagempalavra[palavra_tratada]++;
        }
    }
//    A.ImprimirMap(contagempalavra);
//    A.ImprimirMap(indiceinvertido);

}

void Abre_arquivo::ImprimirMap(map<string,int> m){
    for (auto itr = m.begin(); itr != m.end(); ++itr) {
        cout << itr->first << '\t' << itr->second << '\n';
    }
}

void Abre_arquivo::ImprimirMap(map<string,string> m){
    for (auto itr = m.begin(); itr != m.end(); ++itr) {
        cout << itr->first << '\t' << itr->second << '\n';
    }
}

void Abre_arquivo::Pesquisa(string palavra){
    map<string,string>::iterator it;

    it = indiceinvertido.find(palavra);
    if (it->first == palavra){
        cout << "Documento " << it->second << endl;
    } else {
        cout << "Palavra nao encontrada" << endl;
    }
}

void Abre_arquivo::Coordenadas(string palavra){
    int N;
    map<string,int>::iterator it;
    it = contagempalavra.find(palavra);

    N = it->second;

    cout << "QTD " << N << endl;

    int ndocs;
    ndocs = 1;

    float idf;
    idf = log10(N/ndocs);

    cout << "log estranho " << idf << endl;

    // coordenadas de um vetor
    float W;
    W = (N * idf);

    cout << "W esquisito " << W << endl;
}
