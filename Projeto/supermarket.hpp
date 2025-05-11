#ifndef SUPERMARKET_HPP
#define SUPERMARKET_HPP

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

struct Estante {
    int id;
    string tipoProduto;  // Ex: "Hortifruti", "Padaria", etc.
    string nomeProduto;  // Ex: "Banana", "Pão", "Coca-Cola"
};

struct Aresta {
    int destino;
    double peso;
};

class Grafo {
private:
    unordered_map<int, Estante> estantes;
    unordered_map<int, vector<Aresta>> adjacencia;

public:
    void adicionarEstante(int id, const string& tipo, const string& produto);
    void adicionarAresta(int origem, int destino, double peso);
    vector<int> dijkstra(int origem, int destino, double& custoTotal);
    void imprimirCaminho(const vector<int>& caminho, double custo);
    void gerarVisualizacaoDOT(const vector<int>& caminho, const string& nomeArquivo);

    const unordered_map<int, Estante>& getEstantes() const { return estantes; }
};

extern unordered_map<string, Grafo> lojasGrafo;

void inicializarLojasSupermercado();
void executarMenuSupermercado();

#endif
