# 🛒 Grafos 2 - Supermercado Inteligente

---

## 👩‍💻 Integrantes

- 202016702 Letícia Torres Soares Martins  
- 221008801 Bianca Patrocínio Castro

---

## 🎯 Objetivo

Desenvolver um sistema que representa um **supermercado como um grafo**, permitindo encontrar o **caminho mais eficiente** para coletar todos os itens de uma **lista de compras** e chegar ao caixa. O sistema utiliza **algoritmos de caminhos mínimos**, levando em conta **distância, tempo ou congestionamento**.

---

## 🔧 Tecnologias e Estruturas Utilizadas

- **Linguagem**: C++
- **Representação do grafo**: Lista de adjacência
- **Tipo de grafo**: Ponderado e Direcionado
- **Algoritmo principal**: Dijkstra
- **Possíveis extensões**: Algoritmo A*, simulação de horários de pico, múltiplos coletores

---

## 🧩 Modelagem do Grafo

### 🟢 Nós (Vértices)

Cada **nó** representa um ponto do supermercado:

- Corredores  
- Seções de produtos  
- Entrada  
- Caixas

#### Atributos de um nó:

- `id`: identificador do ponto  
- `tipo`: tipo do ponto (ex: "frutas", "bebidas", "entrada", "caixa")  
- `item`: nome do item disponível (ou `null` se não houver item no local)

### 🔗 Arestas

As **arestas** representam os caminhos entre os pontos do supermercado.

#### Atributos das arestas:

- `peso`: representa a distância, tempo ou fator de congestionamento entre os pontos

> Durante simulações de **horários de pico**, os pesos podem ser aumentados para refletir o congestionamento.

---

## 🧠 Funcionamento do Algoritmo

1. O usuário (ou sistema) fornece uma **lista de compras**.
2. Cada item da lista é associado a um **nó no grafo**.
3. O algoritmo de **Dijkstra** encontra o menor caminho para:
   - Passar por todos os nós da lista
   - Finalizar no caixa
   - Começando pela entrada
4. O sistema retorna o **caminho ideal para coleta**.

---

## 🌟 Funcionalidades Extras (Planejadas)

- 🔄 **Comparação de algoritmos**: Dijkstra vs A*
- ⏰ **Simulação de horários de pico**
- 🧑‍🤝‍🧑 **Múltiplos coletores**: divisão otimizada da lista
- 🎮 **Modo jogo**: o usuário tenta montar o caminho ideal manualmente e o sistema compara com o algoritmo

---

## 📊 Exemplo de Caso de Uso

**Entrada**: Lista de compras: `["banana", "arroz", "detergente"]`  
**Saída**: Caminho ideal: `Entrada → Frutas → Limpeza → Grãos → Caixa`  
**Peso total**: `12 unidades de distância`

---

## 🎥 Apresentação



<p align="center">Autor: <a href="https://github.com/BiancaPatrocinio7">Bianca Patrocínio</a> e <a href="https://github.com/leticiatmartins">Letícia Torres</a>.</p>

---
