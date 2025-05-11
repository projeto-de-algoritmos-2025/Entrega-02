#include "supermarket.hpp"
#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

// Função auxiliar para calcular distância total em uma sequência
double calcularDistanciaLista(Grafo& grafo, const vector<int>& lista) {
    double total = 0;
    for (size_t i = 0; i + 1 < lista.size(); ++i) {
        double parcial = 0;
        grafo.dijkstra(lista[i], lista[i + 1], parcial);
        total += parcial;
    }
    return total;
}

void executarMenuSupermercado() {
    string loja = "Carrefour";
    auto& grafo = lojasGrafo[loja];

    cout << "===== OTIMIZADOR DE COMPRAS NO SUPERMERCADO =====\n";
    cout << "Produtos disponíveis:\n";

    for (const auto& par : grafo.getEstantes()) {
        const Estante& e = par.second;
        cout << e.id << ". " << e.nomeProduto << " [" << e.tipoProduto << "]\n";
    }

    cout << "\nInforme os IDs dos produtos que deseja comprar (separados por espaço, termine com -1):\n";
    vector<int> listaOriginal;
    int id;
    while (cin >> id && id != -1) {
        listaOriginal.push_back(id);
    }

    if (listaOriginal.empty()) {
        cout << "Nenhum produto selecionado.\n";
        return;
    }

    // Cálculo do percurso na ordem original da lista
    double distanciaLista = calcularDistanciaLista(grafo, listaOriginal);

    // Gera a ordem otimizada usando heurística simples: sempre ir ao mais próximo
    vector<int> listaOtimizada;
    vector<int> restantes = listaOriginal;
    int atual = restantes.front();
    listaOtimizada.push_back(atual);
    restantes.erase(restantes.begin());

    while (!restantes.empty()) {
        double melhorCusto = numeric_limits<double>::infinity();
        int proximoMelhor = -1;
        for (int i = 0; i < (int)restantes.size(); ++i) {
            double custo = 0;
            grafo.dijkstra(atual, restantes[i], custo);
            if (custo < melhorCusto) {
                melhorCusto = custo;
                proximoMelhor = i;
            }
        }
        atual = restantes[proximoMelhor];
        listaOtimizada.push_back(atual);
        restantes.erase(restantes.begin() + proximoMelhor);
    }

    double distanciaOtimizada = calcularDistanciaLista(grafo, listaOtimizada);

    // Mostrar caminho otimizado
    cout << "\n>> Caminho otimizado:\n";
    for (int id : listaOtimizada) {
        Estante e = grafo.getEstantes().at(id);
        cout << "- Estante " << e.id << " [" << e.tipoProduto << "]: " << e.nomeProduto << "\n";
    }

    cout << "\nDistância total na ordem da lista original: " << distanciaLista << " metros";
    cout << "\nDistância total na ordem otimizada:        " << distanciaOtimizada << " metros\n";

    // Gerar visualização para o caminho otimizado
    vector<int> visualizacaoFinal;
    for (size_t i = 0; i + 1 < listaOtimizada.size(); ++i) {
        double custoTemp;
        vector<int> trecho = grafo.dijkstra(listaOtimizada[i], listaOtimizada[i + 1], custoTemp);
        if (i > 0) trecho.erase(trecho.begin());
        visualizacaoFinal.insert(visualizacaoFinal.end(), trecho.begin(), trecho.end());
    }

    grafo.gerarVisualizacaoDOT(visualizacaoFinal, "caminho_otimizado");
}
