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

//    vector<string> vetor_teste;
    vector<string>::iterator it;

    while (leitura >> palavra){
        palavra_tratada = A.Tratamento(palavra);

        // testa se a palavra existe no indice, se nao, adiciona
        if (indiceinvertido.find(palavra_tratada) == indiceinvertido.end()){
                indiceinvertido[palavra_tratada].push_back(nomearquivo_);
        } else { // palavra ja existe
            it = find(indiceinvertido[palavra_tratada].begin(), indiceinvertido[palavra_tratada].end(), nomearquivo_);

            // testa se o arquivo ja foi adicionado
            if (it == indiceinvertido[palavra_tratada].end()){
                indiceinvertido[palavra_tratada].push_back(nomearquivo_);

            }
        }

        if (contagempalavra.find(palavra_tratada) == contagempalavra.end()){
            contagempalavra[palavra_tratada] = 1;
        } else {
            contagempalavra[palavra_tratada]++;
        }
    }
//    A.ImprimirMap(contagempalavra);
    A.ImprimirMap(indiceinvertido);

}

void Abre_arquivo::ImprimirMap(map<string,int> m){
    for (auto itr = m.begin(); itr != m.end(); ++itr) {
        cout << itr->first << '\t' << itr->second << '\n';
    }
}

void Abre_arquivo::ImprimirMap(map<string,vector<string>> m){
        for( auto itr = m.begin(); itr != m.end(); ++itr) {
            cout << itr->first << ": ";
            for( auto eptr=itr->second.begin(); eptr!=itr->second.end(); eptr++){
                cout << *eptr << " ";
            }
            cout << endl;
        }
}

void Abre_arquivo::Pesquisa(string palavra){
    map<string,vector<string>>::iterator it;

    it = indiceinvertido.find(palavra);
    if (it->first == palavra){
        cout << "Documentos: " << endl;
        for( auto eptr=it->second.begin(); eptr!=it->second.end(); eptr++){
                cout << *eptr << " " << endl;
        }
    } else {
        cout << "Palavra nao encontrada" << endl;
    }
}


//Teste de abertura de arquivo
void Abre_arquivo::Coordenadas(string palavra){
    int N;
    map<string,int>::iterator it;
    it = contagempalavra.find(palavra);

    N = it->second;

    cout << "QTD " << N << endl;

    int ndocs;
    ndocs = 1;

    double idf;
    idf = log10(N/ndocs);

    cout << "log: " << idf << endl;

    // coordenadas de um vetor
//    double coordenadaW;
    coordenadaW = (N * idf);

    cout << "W: " << coordenadaW << endl;
}

double Abre_arquivo::Ranking(){
    double cosseno;

    cosseno = (coordenadaW * coordenadaW) / (sqrt((pow(coordenadaW,2)))*sqrt((pow(coordenadaW,2))));
    cout << "Coordenada: " << coordenadaW << endl;
    return 1;

}
