#include "MaqBusca.h"

MaqBusca::MaqBusca(){
    linhas_ = 0;
    coordenadaW = 0;
}

MaqBusca::~MaqBusca(){

}

// abre o arquivo
void MaqBusca::Abrearquivo(){
    bool repeticao_ = false;
    do{
        cout << "---------------------------------------------" << endl;
        cout << "Digite o nome do arquivo a ser aberto: \n" << "-> ";
        cin >> nomearquivo_;

        nomearquivo_ = nomearquivo_ + ".txt";
        leitura.open(nomearquivo_.c_str());

        if (leitura.fail()){
            cout << "Erro de leitura de arquivo! Digite novamente o nome do arquivo." << endl;
        }else{
            repeticao_ = true;
        }
    }while(repeticao_ == false);
}

// fecha o arquivo
void MaqBusca::Fechaaquivo(){
    leitura.close();
    cout << "---->Fechamento do arquivo realizado com sucesso!" << endl;
}

// Verifica quantos linhas estao no arquivo de entrada
void MaqBusca::Contagemlinhas(){
    ifstream contagem;
    string logs_;

    contagem.open(nomearquivo_.c_str());

    while(!contagem.eof()) {
        getline(contagem, logs_);
        linhas_++;
    }
    contagem.close();
}

// pega o numero de linhas
void MaqBusca::Getlinhas(){
    cout << linhas_ << endl;
}

// Troca caixa alta para caixa baixa e remove caracteres
string MaqBusca::Tratamento(string palavra){
    transform(palavra.begin(), palavra.end(), palavra.begin(), ptr_fun <int, int> ( tolower ) );
    palavra.erase(remove_if(palavra.begin(), palavra.end(), [](char c){ return c==','||c=='.'|| c=='!'||
                            c=='-'|| c=='?'||c== ':' ||c== ';' ||c== 39 ||c== '[' ||c== ']' ||c== '{' ||c== '}' ||
                            c== '<' ||c== '>' ||c== '(' ||c== ')' ||c== '*' ||c== '%'||c== '&'; }), palavra.end());

    return palavra;
}


// faz o indice invertido
void MaqBusca::IndiceInvertido(){
    MaqBusca A;

    string palavra;
    string palavra_tratada;

    vector<string>::iterator it;

    while (leitura >> palavra){
        palavra_tratada = A.Tratamento(palavra);

        // testa se a palavra existe no indice, se nao, adiciona
        if (indiceinvertido.find(palavra_tratada) == indiceinvertido.end()){
                indiceinvertido[palavra_tratada].push_back(nomearquivo_);
        } else { // palavra ja existe
            it = find(indiceinvertido[palavra_tratada].begin(), indiceinvertido[palavra_tratada].end(), nomearquivo_);

            // testa se o arquivo ja foi adicionado ao map
            if (it == indiceinvertido[palavra_tratada].end()){
                indiceinvertido[palavra_tratada].push_back(nomearquivo_);
            }
        }

        // faz a contagem de quantas vezes a palavra apareceu
        if (contagempalavra.find(palavra_tratada) == contagempalavra.end()){
            contagempalavra[palavra_tratada] = 1;
        } else {
            contagempalavra[palavra_tratada]++;
        }
    }

//    A.ImprimirMap(contagempalavra);
    A.ImprimirMap(indiceinvertido);

}

// imprime o map da contagem
void MaqBusca::ImprimirMap(map<string,int> m){
    for (auto itr = m.begin(); itr != m.end(); ++itr) {
        cout << itr->first << '\t' << itr->second << '\n';
    }
}

// imprime o indice invertido
void MaqBusca::ImprimirMap(map<string,vector<string>> m){
    for( auto itr = m.begin(); itr != m.end(); ++itr) {
        cout << itr->first << ": ";
        for( auto eptr=itr->second.begin(); eptr!=itr->second.end(); eptr++){
            cout << *eptr << " ";
        }
        cout << endl;
    }
}

// faz pesquisa de uma palavra no indice invertido
void MaqBusca::Pesquisa(string palavra){
    map<string,vector<string>>::iterator it;

    it = indiceinvertido.find(palavra);
    if (it->first == palavra){
        cout << "Documentos: "; //<< endl;
        for( auto eptr=it->second.begin(); eptr!=it->second.end(); eptr++){
                cout << *eptr << " " << endl;
        }
    } else {
        cout << "Palavra nao encontrada" << endl;
    }
}

//Faz calculo da coordenada da palavra
void MaqBusca::Coordenadas(string palavra, int ndocs){
    int N;
    map<string,int>::iterator it;
    it = contagempalavra.find(palavra);

    N = it->second;

    cout << "QTD " << N << endl;
    cout << "Docs " << ndocs << endl;

    double idf;
    idf = log10(N/ndocs);

    cout << "log: " << idf << endl;

    // coordenadas de um vetor
    coordenadaW = (N * idf);

    cout << "W: " << coordenadaW << endl;
}

// faz calculo do ranking
double MaqBusca::Ranking(){
    double cosseno;

    cosseno = (coordenadaW * coordenadaW) / (sqrt((pow(coordenadaW,2)))*sqrt((pow(coordenadaW,2))));
    cout << "Coordenada: " << coordenadaW << endl;

    return coordenadaW;
}
