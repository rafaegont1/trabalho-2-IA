# Algoritmos BFS e DFS

Este projeto implementa os algoritmos de **Busca em Largura (BFS)** e **Busca em Profundidade (DFS)**, desenvolvidos em C. Este README explica como cada algoritmo funciona e apresenta as principais diferenças entre eles. 

---

## 📖 Busca em Largura (BFS)

### O que é?
A **Busca em Profundidade (Depth-First Search)** é um algoritmo que explora os caminhos de um grafo ou árvore profundamente antes de retroceder. Ele utiliza o conceito de recursão ou uma pilha para gerenciar os vértices visitados.

### 🔧 Funcionamento
1. Inicia no nó inicial e o marca como visitado.
2. Insere o nó inicial em uma **fila**.
3. Enquanto a fila não estiver vazia:
   - Remove o nó da frente da fila.
   - Visita todos os vizinhos não visitados, marca-os como visitados e os adiciona à fila.
  
## 📖 Busca em Prorundidade (DFS)

### O que é?
A **Busca em Largura (Breadth-First Search)** é um algoritmo que explora os vértices de um grafo em níveis, visitando primeiro os nós mais próximos do nó inicial antes de avançar para os mais distantes.

### 🔧 Funcionamento
1. Começa no nó inicial e o marca como visitado.
2. Explora recursivamente (ou utilizando uma pilha) os vizinhos não visitados do nó atual até atingir um vértice sem vizinhos não visitados.
3. Retrocede para continuar explorando outros caminhos.

## Tempo de Execução ⏰

Foi utilizada a função `clock_gettime()`, pertencente a biblioteca `GNU C Library` para medir o tempo de execução dos dois algoritmos. Para melhor precisão e comparação entre as formas de busca, foram executados cada código dez vezes e o tempo de execução usado como comparação é a média aritmética entre eles.

Os testes foram feitos num notebook *ACER Nitro 5*(GTX 1650 - Intel Core i5 i5 - 16gb ram).

- `BFS`
  - O tempo de execução foi 495500 ns (0,0004975 segundos).
- `DFS`
  - O tempo de execução foi 541800 ns (0,0005418 segundos).
#### **Conclusões sobre os tempos**

O algoritmo BFS pode ser considerado mais "estável" no labirinto comparado. Os tempos de execução medidos tinham variações superiores a 0,0003 segundos, enquanto o DFS é bem menos previsível, tendo medições muito mais rápidas, como 0,0002 segundos e também muito mais demoradas, como 0,0008 segundos.

## Custo e Consumo de Memória 🧠

#### **Busca em Largura (BFS)**
O consumo de memória do BFS depende diretamente da **estrutura de dados usada (fila)** e do número de vértices no **nível mais amplo do grafo**. 

1. **Estrutura usada**: 
   - O BFS utiliza uma **fila (FIFO)** para armazenar os nós a serem processados.
   - Em um grafo ou árvore, no pior caso, a fila pode conter todos os nós de um mesmo nível antes de avançar para o próximo.

2. **Complexidade de memória**:
   - Se o número máximo de nós em um nível for \( b^d \), onde \( b \) é o fator de ramificação (número médio de filhos por nó) e \( d \) é a profundidade atual, o consumo de memória será proporcional a \( O(b^d) \).

3. **Impacto prático**:
   - Em grafos ou árvores com alto fator de ramificação (\( b \)) e profundidade limitada, o BFS pode consumir **muita memória**, pois mantém vários nós simultaneamente na fila.

---

#### **Busca em Profundidade (DFS)**
O consumo de memória do DFS é determinado pela **pilha de recursão** ou pela pilha explícita utilizada na versão iterativa. 

1. **Estrutura usada**:
   - O DFS utiliza uma **pilha (LIFO)**, seja por meio de recursão ou explicitamente.

2. **Complexidade de memória**:
   - A memória consumida é proporcional à **profundidade máxima da árvore ou grafo** explorada pelo algoritmo. Isso corresponde a \( O(d) \), onde \( d \) é a profundidade máxima do grafo ou árvore.

3. **Impacto prático**:
   - O DFS consome **menos memória** em comparação com o BFS em cenários onde o grafo ou árvore possui uma grande largura (\( b \)) mas é relativamente profundo.

---

### Diferenças no Consumo de Memória

| Característica          | BFS                           | DFS                           |
|-------------------------|-------------------------------|-------------------------------|
| **Estrutura de dados**  | Fila (FIFO)                  | Pilha (LIFO) ou recursão      |
| **Consumo de memória**  | \( O(b^d) \)                 | \( O(d) \)                   |
| **Maior impacto**       | Grafo com alta largura        | Grafo com alta profundidade   |
| **Escalabilidade**      | Menos escalável em grafos muito amplos | Mais escalável para grafos amplos |

---

### Comentários sobre as Diferenças

1. **BFS**:
   - Consome mais memória em situações onde o grafo ou árvore tem **muitos nós no mesmo nível**.
   - É mais adequado para encontrar caminhos mais curtos, pois explora por níveis.

2. **DFS**:
   - Usa menos memória, especialmente em grafos profundos e com poucos caminhos paralelos.
   - É ideal para explorar profundamente cada caminho antes de retroceder.

3. **Conclusão Prática**:
   - Se a memória disponível é limitada, o DFS geralmente é uma escolha melhor.
   - O BFS pode ser inviável em grafos muito amplos devido ao alto consumo de memória.

---

### Consumo de Memória

Utilizando o mesmo mapa para as duas buscas (mapa proposto no trabalho) o consumo de memória dos dois algoritmos de busca foi distinto, porém não muito distante. Entretanto, essa diferença pode chegar a conclusões acerca da eficiência de cada um dos tipos de buscas. 

Os testes foram feitos num notebook *ACER Nitro 5*(GTX 1650 - Intel Core i5 i5 - 16gb ram).

-  **DFS** -> 368 bytes de memória.
-  **BFS** -> 384 bytes de memória.


1. **Diferença de Consumo de Memória em Cenários Maiores**:
   - Embora a diferença de **16 bytes (384 - 368)** pareça pequena neste exemplo, em grafos maiores, essa diferença tende a crescer significativamente.
   - Isso ocorre devido à natureza do BFS, que armazena mais estados na fila conforme o grafo cresce em largura.

2. **Escalabilidade do Consumo**:
   - O **BFS** consome memória proporcional ao maior nível completo do grafo \( b^d \), onde:
     - \( b \): Fator de ramificação (número médio de filhos por nó).
     - \( d \): Profundidade do nível atual.
   - O **DFS**, por outro lado, consome memória proporcional à profundidade total do grafo (\( d \)).

3. **Escolha do Algoritmo**:
   - **DFS** seria mais eficiente em termos de memória em grafos amplos e profundos, onde a largura (\( b \)) é muito maior que a profundidade (\( d \)).
   - **BFS** pode ser vantajoso para problemas que exigem exploração por níveis ou busca do caminho mais curto, mas consome mais memória à medida que a largura do grafo aumenta.
  
## Completude ✅​

O **DFS** é:
- Completo em espaços de estados finitos.
- Não completo em espaços de estados infinitos, pois pode ficar preso em um ramo sem fim, sem explorar outros.

O **BFS** é:
- O espaço de estados (grafo ou árvore) seja finito.
- A solução seja alcançável.

### Comparação entre BFS e DFS na Completude

| Algoritmo | É Completo?                                      | Condição de Completude                                                                 |
|-----------|--------------------------------------------------|---------------------------------------------------------------------------------------|
| **BFS**   | Sim                                              | Desde que o grafo seja finito e a solução seja alcançável.                            |
| **DFS**   | Sim (em grafos finitos) / Não (em grafos infinitos) | Necessário evitar loops infinitos ou explorar ramos infinitamente profundos.         |

``No mapa (labirinto) proposto ambos os algoritmos de busca desempenham papel satisfatório e conseguem ser completos. ``

## Optimalidade 🚩

Optimalidade determina se a solução encontrada é a melhor possível, nesse caso, o menor caminho.

O menor caminho no labirinto proposto seria o representado na imagem abaixo:

![image](https://github.com/user-attachments/assets/07a4d470-42b6-4999-b130-9c9381fa9d00)

###### *Labirinto proposto no trabalho com pequenas modificações para melhor indentificação de posição.*


### ``A sequência do menor caminho seria: U -> V -> Q -> L -> M -> N -> I-> H -> C -> D -> E``

O CAMINHO DO **DFS**:
- U -> V -> W -> X -> Y -> T -> S -> R -> M -> N -> I -> H -> C -> D -> E

O CAMINHO DO **BFS**:
- U -> V -> Q -> L -> M -> N -> I -> H -> C -> D -> E

O BFS encontrou o caminho mais curto, porém gastou mais memória para isso, ou seja, em questão de optimalidade, o BFS tem melhor desempenho que o DFS.

## Conclusões 🤝

## Análise Comparativa

| Critério         | BFS                                    | DFS                                    |
|------------------|----------------------------------------|----------------------------------------|
| **Tempo de Execução** | Eficiente para encontrar o menor caminho.   | Pode ser mais rápido em alguns cenários, mas depende da ordem dos nós. |
| **Consumo de Memória** | Alto em grafos amplos.                      | Baixo, mas pode aumentar em grafos com alta profundidade.             |
| **Completude**    | Sempre encontra a solução (grafo finito).      | Completo apenas em grafos finitos.                                    |
| **Optimalidade**  | Garante o menor caminho (grafo não ponderado). | Não garante o menor caminho.                                          |

---

## Conclusões Finais

1. **BFS é mais adequado para problemas que exigem a solução mais curta**:
   - É ideal para cenários em que a eficiência e a optimalidade são fundamentais, como busca de caminhos em redes não ponderadas.

2. **DFS é útil em problemas que exigem exploração completa**:
   - Pode ser mais eficiente em grafos com baixa profundidade ou em situações onde qualquer solução é aceitável, mesmo que não seja a melhor.

3. **Impacto da Estrutura do Grafo**:
   - A eficiência de ambos os algoritmos depende fortemente das características do grafo, como largura, profundidade e presença de ciclos.

---

## Possíveis Melhorias

1. **Melhorias no BFS**:
   - Implementar estratégias para reduzir o consumo de memória, como podar nós irrelevantes.
   - Aplicar heurísticas para priorizar caminhos mais promissores (ex.: A*).

2. **Melhorias no DFS**:
   - Adicionar controle de estados visitados para evitar loops em grafos com ciclos.
   - Modificar o algoritmo para interromper a exploração de caminhos desnecessários, melhorando sua eficiência.


## 🚀 Como Executar

Siga os passos abaixo para compilar e executar o projeto:

1. Clone o repositório:

   ```bash
   git clone https://github.com/rafaegont1/trabalho-1-IA
   cd <nome-do-repositorio>
3. Configure o projeto: Crie uma pasta para os arquivos de compilação e configure o projeto com o CMake:

  ```bash
  mkdir build
  cd build
  cmake ..
```
3. Compile o projeto: Use o comando make para compilar:

  ```bash
  make
```
4. Execute o programa: O executável gerado terá o nome dfs. Para rodar:
 ```bash
./dfs
```
ou 
```bash
./bsf
```





