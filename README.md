# Algoritmos A* e Guloso
Este projeto implementa os algoritmos de **Busca A*** e **Busca Gulosa**, desenvolvidos em C. Este README explica como cada algoritmo funciona e apresenta as principais diferenças entre eles. 

---

## 📖 A*

### O que é?
O A* é um algoritmo de busca heurística amplamente utilizado em problemas de caminho mínimo. Ele combina o custo acumulado para chegar a um nó e uma estimativa heurística do custo para alcançar o objetivo, garantindo eficiência e precisão na busca.

### 🔧 Funcionamento
1. Inicia no nó inicial e o adiciona à lista **aberta** (nós a serem explorados), com um custo acumulado `g(n)` igual a zero.
2. Enquanto a lista **aberta** não estiver vazia:
   - Seleciona o nó com o menor valor de `f(n) = g(n) + h(n)` na lista **aberta**.
   - Move o nó selecionado para a lista **fechada** (nós já explorados).
   - Se o nó selecionado for o objetivo, termina o algoritmo e retorna o caminho.
   - Para cada vizinho do nó atual:
     - Calcula `g(n)` como o custo acumulado desde o início.
     - Calcula `f(n)` como `g(n) + h(n)`, onde `h(n)` é o valor estimado da heurística.
     - Se o vizinho não estiver na lista **aberta** ou **fechada**, adiciona-o à lista **aberta**.
  
## 📖 Busca Gulosa (GBS)

### O que é?
A **Busca Gulosa** é um algoritmo de busca heurística que sempre escolhe o próximo passo baseado na heurística `h(n)` de menor custo, priorizando a solução mais promissora em cada etapa. Ela é chamada "gulosa" porque tenta alcançar o objetivo o mais rápido possível, sem considerar o custo acumulado.

---

## 🔧 Funcionamento

1. Inicia no nó inicial e o adiciona à lista **aberta** (nós a serem explorados).
2. Enquanto a lista **aberta** não estiver vazia:
   - Seleciona o nó com o menor valor de `h(n)` na lista **aberta**.
   - Remove o nó da lista **aberta** e o adiciona à lista **fechada** (nós já explorados).
   - Se o nó selecionado for o objetivo, termina o algoritmo e retorna o caminho.
   - Para cada vizinho do nó atual:
     - Calcula o valor de `h(n)` para o vizinho.
     - Se o vizinho não estiver na lista **aberta** ou **fechada**, adiciona-o à lista **aberta**.
     - Caso o vizinho já esteja na lista **aberta** com um custo maior, atualiza o nó pai e recalcula `h(n)`.

## Tempo de Execução ⏰

Foi utilizada a função `clock_gettime()`, pertencente a biblioteca `GNU C Library` para medir o tempo de execução dos dois algoritmos. Para melhor precisão e comparação entre as formas de busca, foram executados cada código dez vezes e o tempo de execução usado como comparação é a média aritmética entre eles.

Os testes foram feitos num notebook *ACER Nitro 5*(GTX 1650 - Intel Core i5 i5 - 16gb ram).

- `A*`
  - O tempo de execução foi 4800 ns.
- `GBS`
  - O tempo de execução foi 4500 ns.
#### **Conclusões sobre os tempos**

A **Busca Gulosa (GBS)** é mais rápida que o **A*** porque toma decisões exclusivamente com base na heurística `(h(n))`, priorizando o próximo nó que parece estar mais próximo do objetivo sem considerar o custo acumulado do caminho `(g(n))`. Isso reduz significativamente a complexidade computacional em cada etapa, pois o algoritmo realiza menos cálculos e atualizações, além de simplificar a organização na fila de prioridade. Por outro lado, o **A*** precisa calcular a função total de custo `(f(n) = g(n) + h(n))` para cada nó, o que exige mais operações matemáticas e atualizações frequentes na fila, tornando-o mais lento em comparação. Essa simplicidade da **GBS** é o principal motivo para seu desempenho mais rápido no labirinto trabalhado.

## Custo e Consumo de Memória 🧠

#### **A***  
O consumo de memória do A* é diretamente influenciado pela **estrutura de dados utilizada (fila de prioridade)** e pela quantidade de nós que ele mantém em memória para calcular o custo total `f(n) = g(n) + h(n)`.

1. **Estrutura usada**:  
   - O A* utiliza uma **fila de prioridade** que armazena os nós a serem explorados, ordenados pelo custo total `f(n)`.
   - Cada nó precisa armazenar informações como o custo acumulado `g(n)`, o valor da heurística `h(n)` e o nó pai para reconstrução do caminho.

2. **Complexidade de memória**:  
   - O consumo de memória depende da quantidade total de nós explorados e armazenados na fila, sendo proporcional a `O(b^d)`, onde:
     - `b`: Fator de ramificação (número médio de filhos por nó).
     - `d`: Profundidade do nó objetivo.

3. **Impacto prático**:  
   - Como o A* mantém mais informações (custos `g(n)` e `h(n)`, ele pode consumir significativamente mais memória do que algoritmos que não acumulam esse histórico.

---

#### **Busca Gulosa (GBS)**  
O consumo de memória da Busca Gulosa é menor porque ela prioriza apenas o cálculo da heurística `h(n)`, sem considerar o custo acumulado `g(n)`.

1. **Estrutura usada**:  
   - A Busca Gulosa também utiliza uma **fila de prioridade**, mas ordena os nós exclusivamente pelo valor da heurística `h(n)`, sem armazenar custos acumulados.

2. **Complexidade de memória**:  
   - O consumo é proporcional a `O(b^d)`, similar ao A*, mas com menos informações armazenadas por nó, tornando o uso de memória mais eficiente.

3. **Impacto prático**:  
   - Em problemas simples ou com heurísticas muito boas, a Busca Gulosa consome consideravelmente menos memória do que o **A***, pois descarta informações relacionadas ao custo acumulado.

---

### Diferenças no Consumo de Memória

| Característica          | A*                            | Busca Gulosa (GBS)            |
|-------------------------|-------------------------------|-------------------------------|
| **Estrutura de dados**  | Fila de prioridade            | Fila de prioridade            |
| **Consumo de memória**  | `O(b^d)`, com custos `g(n)` e `h(n)` | `O(b^d)`, apenas `h(n)` |
| **Armazenamento por nó**| Mais informações (pai, `(g(n)`, `h(n))` | Menos informações `h(n)` |
| **Maior impacto**       | Mais memória em problemas complexos | Menos memória em todos os casos |
| **Escalabilidade**      | Menos escalável devido ao maior consumo | Mais escalável em termos de memória |

---

### Comparação dos Resultados de Consumo de Memória

Os testes foram realizados utilizando o mesmo mapa (proposto no trabalho) em um notebook *ACER Nitro 5* (GTX 1650 - Intel Core i5 - 16GB RAM). Os consumos médios de memória medidos foram:

- **A*** → 476 bytes de memória.  
- **Busca Gulosa** → 340 bytes de memória.  

---

### Conclusões

1. **Eficiência da Busca Gulosa (GBS):**
   - A GBS consome significativamente menos memória porque armazena apenas os valores da heurística `h(n)`, sem calcular ou guardar o custo acumulado `g(n)`.

2. **Impacto em Cenários Maiores:**
   - Em grafos maiores, a diferença de consumo tende a ser ainda mais significativa, pois cada nó no A* exige armazenamento adicional para cálculos de `g(n)` e `h(n)`.
   - A GBS se torna mais escalável em termos de memória, especialmente em problemas com um grande fator de ramificação `(b)`.

3. **Escolha do Algoritmo:**
   - **A*** é preferível quando a precisão do caminho mais curto é crucial, mesmo que isso exija maior consumo de memória.
   - **Busca Gulosa** é uma escolha mais eficiente para problemas menos complexos ou quando a memória disponível é limitada.

## Completude ✅​

O **A*** é:
- Completo, desde que:
  - O espaço de estados seja finito.
  - A heurística seja admissível (não superestime o custo real).
  - Os custos das arestas sejam positivos.

A **Busca Gulosa (GBS)** é:
- Não completa em geral, porque:
  - Pode entrar em loops ou ficar presa em caminhos subótimos, dependendo da qualidade da heurística.
  - Não considera o custo acumulado, o que pode levar à exploração de caminhos que nunca alcançam a solução.

### Comparação entre A* e Busca Gulosa na Completude

| Algoritmo    | É Completo?                                     | Condição de Completude                                                                   |
|--------------|-------------------------------------------------|-----------------------------------------------------------------------------------------|
| **A***       | Sim                                             | Desde que o grafo seja finito, a heurística seja admissível e os custos sejam positivos. |
| **GBS**      | Não                                             | Pode não ser completo devido à dependência exclusiva da heurística e à possibilidade de loops. |

``No mapa (labirinto) proposto, ambos os algoritmos encontraram uma solução, porém, dependendo da área de busca, uma busca Gulosa pode não encontrar um caminho.``


## Optimalidade 🚩

Optimalidade determina se a solução encontrada é a melhor possível, nesse caso, o menor caminho.

O menor caminho no labirinto proposto seria o representado na imagem abaixo:

![image](https://github.com/user-attachments/assets/07a4d470-42b6-4999-b130-9c9381fa9d00)

###### *Labirinto proposto no trabalho com pequenas modificações para melhor indentificação de posição.*


### ``A sequência do menor caminho seria: U -> V -> Q -> L -> M -> N -> I-> H -> C -> D -> E``

O CAMINHO DO **A***:
- U -> V -> Q -> L -> M -> N -> I-> H -> C -> D -> E

O CAMINHO DO **GBS**:
- U -> V -> Q -> L -> M -> N -> I-> H -> C -> D -> E

Ambos os métodos de busca, **A*** e **Busca Gulosa (GBS)**, conseguiram encontrar o melhor caminho no labirinto utilizado para os testes. A principal diferença observada foi no **tempo de execução** e no **consumo de memória**. Como o labirinto de teste possui poucos "vértices" (posições possíveis), e os dois algoritmos compartilham algumas semelhanças na forma como exploram os estados, os resultados foram **próximos em termos de solução encontrada**.

Entretanto, em **aplicações reais** e cenários mais complexos, o algoritmo **A*** se destaca por sua **maior optimalidade**. Isso ocorre porque o A* utiliza tanto o **custo acumulado do caminho já percorrido** quanto uma **heurística para estimar o custo até o objetivo**. Essa abordagem torna o A* mais **robusto e confiável** na busca pelo menor caminho, especialmente em grafos maiores e com custos variados.

Por outro lado, a **Busca Gulosa** depende **exclusivamente da heurística**, sem considerar o custo acumulado, o que pode levar a **escolhas subótimas** em cenários complexos. Assim, enquanto o GBS pode ser vantajoso em termos de **velocidade** e **consumo de memória**, o **A*** é a melhor escolha para garantir **soluções otimizadas** e mais precisas.


## Conclusões 🤝

## Análise Comparativa

| Critério         | A*                                     | Busca Gulosa (GBS)                      |
|------------------|----------------------------------------|-----------------------------------------|
| **Tempo de Execução** | Mais lento devido ao uso de heurística e custo acumulado. | Geralmente mais rápido, mas depende da heurística. |
| **Consumo de Memória** | Alto devido ao armazenamento de nós abertos e fechados. | Baixo, pois armazena apenas os nós mais promissores. |
| **Completude**    | Sempre encontra a solução (se condições forem satisfeitas). | Não garante encontrar a solução em alguns casos.    |
| **Optimalidade**  | Garante o caminho mais curto (com heurística admissível). | Não garante o caminho mais curto.                   |

---

## Conclusões Finais

1. **A* é mais adequado para problemas que exigem solução ótima**:
   - Ideal para cenários onde a precisão no menor caminho é essencial, como navegação GPS ou jogos baseados em mapas.

2. **Busca Gulosa é útil em problemas que exigem rapidez**:
   - Pode ser eficiente em situações onde o objetivo é chegar a uma solução rápida, mesmo que não seja a melhor.

3. **Impacto da Heurística**:
   - Ambos os algoritmos dependem fortemente da qualidade da heurística utilizada, mas o A* equilibra o custo acumulado e a estimativa, tornando-o mais robusto.

---

## Possíveis Melhorias

1. **Melhorias no A***:
   - Reduzir o consumo de memória com técnicas como *Iterative Deepening A***.
   - Refinar a heurística para balancear melhor a eficiência e a precisão.

2. **Melhorias na Busca Gulosa**:
   - Introduzir verificações para evitar loops e caminhos subótimos.
   - Combinar com outros métodos para melhorar a completude e a robustez em grafos complexos.


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





