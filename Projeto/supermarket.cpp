#include "supermarket.hpp"
#include <iostream>

void inicializarLojasSupermercado() {
    Grafo g;

    g.adicionarEstante(1, "Hortifruti", "Banana");
    g.adicionarEstante(2, "Hortifruti", "Maçã");
    g.adicionarEstante(3, "Padaria", "Pão");
    g.adicionarEstante(4, "Bebidas", "Coca-Cola");
    g.adicionarEstante(5, "Congelados", "Sorvete");
    g.adicionarEstante(6, "Laticínios", "Queijo");

    g.adicionarAresta(1, 2, 2.0);
    g.adicionarAresta(2, 3, 1.5);
    g.adicionarAresta(3, 4, 2.0);
    g.adicionarAresta(4, 5, 1.0);
    g.adicionarAresta(5, 6, 3.0);
    g.adicionarAresta(1, 4, 5.0);

    lojasGrafo["Carrefour"] = g;
}
