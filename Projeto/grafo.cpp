#include "supermarket.hpp"
#include <iostream>
#include <queue>
#include <fstream>
#include <sstream>
#include <limits>

unordered_map<string, Grafo> lojasGrafo;

void Grafo::adicionarEstante(int id, const string& tipo, const string& produto) {
    estantes[id] = {id, tipo, produto};
}

void Grafo::adicionarAresta(int origem, int destino, double peso) {
    adjacencia[origem].push_back({destino, peso});
}

vector<int> Grafo::dijkstra(int origem, int destino, double& custoTotal) {
    unordered_map<int, double> distancia;
    unordered_map<int, int> anterior;
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> fila;

    for (auto it = estantes.begin(); it != estantes.end(); ++it) {
        int id = it->first;
        distancia[id] = numeric_limits<double>::infinity();
    }


    distancia[origem] = 0;
    fila.push({0, origem});

    while (!fila.empty()) {
        int atual = fila.top().second;
        double distAtual = fila.top().first;
        fila.pop();

        if (atual == destino) break;

        for (const Aresta& vizinho : adjacencia[atual]) {
            double novaDist = distAtual + vizinho.peso;
            if (novaDist < distancia[vizinho.destino]) {
                distancia[vizinho.destino] = novaDist;
                anterior[vizinho.destino] = atual;
                fila.push({novaDist, vizinho.destino});
            }
        }
    }

    custoTotal = distancia[destino];
    vector<int> caminho;

    if (distancia[destino] == numeric_limits<double>::infinity()) {
        return caminho;  // nenhum caminho encontrado
    }

    for (int v = destino; v != origem; v = anterior[v]) {
        caminho.insert(caminho.begin(), v);
    }
    caminho.insert(caminho.begin(), origem);

    return caminho;
}


void Grafo::imprimirCaminho(const vector<int>& caminho, double custo) {
    cout << "\n>> Caminho encontrado (custo total: " << custo << "):\n";
    for (int id : caminho) {
        const auto& e = estantes[id];
        cout << "- Estante " << e.id << " [" << e.tipoProduto << "]: " << e.nomeProduto << "\n";
    }
    cout << endl;
}

void Grafo::gerarVisualizacaoDOT(const vector<int>& caminho, const string& nomeArquivo) {
    ofstream dotFile(nomeArquivo + ".dot");
    dotFile << "digraph G {\n  rankdir=LR;\n  node [shape=box, style=filled, fillcolor=lightgreen];\n";

    for (size_t i = 0; i < caminho.size(); ++i) {
        dotFile << "  " << caminho[i];
        if (i < caminho.size() - 1)
            dotFile << " -> " << caminho[i + 1];
        dotFile << ";\n";
    }

    dotFile << "}\n";
    dotFile.close();

    string comando = "dot -Tpng " + nomeArquivo + ".dot -o " + nomeArquivo + ".png";
    system(comando.c_str());

#ifdef _WIN32
    system(("start " + nomeArquivo + ".png").c_str());
#elif __APPLE__
    system(("open " + nomeArquivo + ".png").c_str());
#else
    system(("xdg-open " + nomeArquivo + ".png").c_str());
#endif
}
