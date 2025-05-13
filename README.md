# 🛒 Grafos 2 - Supermercado Inteligente

**Número da Lista**: 2


**Conteúdo da Disciplina**: FGA0124 - PROJETO DE ALGORITMOS - T01  


## Alunos


<div align = "center">
<table>
  <tr>
    <td align="center"><a href="https://github.com/BiancaPatrocinio7"><img style="border-radius: 50%;" src="https://github.com/BiancaPatrocinio7.png" width="190;" alt=""/><br /><sub><b>Bianca Patrocínio</b></sub></a><br /><a href="Link git" title="Rocketseat"></a></td>
    <td align="center"><a href="https://github.com/leticiatmartins"><img style="border-radius: 50%;" src="https://github.com/leticiatmartins.png" width="190px;" alt=""/><br /><sub><b>Leticia Torres </b></sub></a><br />
  </tr>
</table>

| Matrícula   | Aluno                             |
| ----------- | ---------------------------------- |
| 22/1008801  | Bianca Patrocínio Castro           |
| 20/2016702  | Leticia Torres Soares Martins      |
</div>

## Sobre 
Desenvolver um sistema que representa um **supermercado como um grafo**, permitindo encontrar o **caminho mais eficiente** para coletar todos os itens de uma **lista de compras** e chegar ao caixa. O sistema utiliza **algoritmos de caminhos mínimos**, levando em conta **distância, tempo ou congestionamento**.
## Screenshots
<p align="center">
  <img src="Documentos/screenshots/print1.png" alt="Print 1 do projeto" width="600"/>
</p>
<p align="center">
  <img src="Documentos/screenshots/grafo.png" alt="Print 1 do projeto" width="600"/>
</p>
<p align="center">
  <img src="Documentos/screenshots/Captura de Tela 2025-05-12 às 13.54.45.png" alt="Print 2 do projeto" width="600"/>
</p>

<p align="center">
  <img src="Documentos/screenshots/printFinal.png" alt="Print 3 do projeto" width="600"/>
</p>

<p align="center">
  <img src="Documentos/screenshots/caminho_otimizado.png" alt="Print 3 do projeto" width="600"/>
</p>



## Instalação 
**Linguagem**:  C++
## Pré-requisitos

Antes de rodar o projeto, você precisará ter os seguintes programas instalados:

- **g++** (compilador C++).
- **make** (ferramenta de automação de builds).
- **Graphviz (dot)** para gerar e visualizar os grafos do caminho.

### Instalar g++, make e dot

#### No macOS:
Se você usa macOS, pode instalar com o Homebrew:

```bash
brew install gcc make graphviz
```

#### No Linux (Ubuntu/Debian):
No Linux, instale com:

```bash
sudo apt update
sudo apt install build-essential graphviz
```

## Como compilar e executar o projeto
### Passo 1: Clonar o repositório
```bash
git clone https://github.com/projeto-de-algoritmos-2025/Grafos-2-Supermercado-Inteligente.git
cd Grafos-2-Supermercado-Inteligente
```

### Passo 2: Compilar o projeto
Para compilar o projeto, use o comando make. Isso irá compilar todos os arquivos fonte e gerar o executável:

```bash
make
```

### Passo 3: Rodar o projeto
Após a compilação, execute o programa gerado:

```bash
 ./Grafos-1-Supermarket
```


## Uso 
Após rodar o programa, escolha os produtos da lista. O sistema encontrará fornecerá o caminhos sistema retorna o **caminho ideal para coleta**: Distância total na ordem da lista original e a Distância total na ordem otimizada mais próxima disponível usando o algoritmo, e um grafo será gerado mostrando o caminho.

O grafo será salvo como uma imagem .png

## Apresentação 


## Apresentação 

<div align="center">
<a href="https://youtu.be/jQ_cz740sGQ?si=z-E-efF1ykJEWZUY"><img src="Documentos/screenshots/Screenshot from 2025-05-12 22-13-53.png" width="50%"></a>
</div>

<font size="3"><p style="text-align: center">Autor: [Bianca Patrocínio](https://github.com/BiancaPatrocinio7) e [Letícia Torres](https://github.com/leticiatmartins).</p></font>





