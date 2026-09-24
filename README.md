# Análise de Algoritmos de Ordenação (C++)

Este repositório contém um estudo prático e teórico sobre algoritmos de ordenação em C++, com foco especial no **Quick Sort**. Os códigos aqui presentes comparam a eficiência de diferentes métodos (Bubble, Insertion, Selection e Quick Sort) em cenários variados.

## 📖 Sobre o Quick Sort (Estratégia Dividir para Conquistar)

O Quick Sort é um algoritmo altamente eficiente baseado na estratégia de **Dividir para Conquistar**:
1. **Escolha do pivô:** Um elemento é selecionado (neste estudo, normalmente o último elemento).
2. **Particionamento:** Elementos menores que o pivô vão para a esquerda, e os maiores para a direita. O pivô encontra sua posição definitiva.
3. **Recursividade:** O processo é repetido para os sub-arrays à esquerda e à direita do pivô.
4. **Caso Base:** Sub-arrays de tamanho 0 ou 1 já estão ordenados.

### ⚡ Complexidade
* **Melhor / Médio Caso:** `O(N log N)` (quando o pivô divide o array de forma equilibrada).
* **Pior Caso:** `O(N²)` (quando a lista já está ordenada e o pivô escolhido é um dos extremos).
* **Espaço:** `O(log N)` no caso médio (referente ao tamanho da pilha de recursão).
* **Características:** Algoritmo *In-place* (não exige criação de novos arrays) e *Instável*.

---

## 💻 Arquivos do Projeto

### 1. `Atividade 3.cpp` - Comparação com Inteiros Aleatórios
* **Descrição:** Testa o **Bubble Sort** e o **Quick Sort** gerando arrays aleatórios de diferentes tamanhos (10, 20 e 1000 elementos).
* **Objetivo:** Contabilizar e comparar o número de comparações e trocas de cada algoritmo, demonstrando a superioridade do Quick Sort em vetores maiores.

### 2. `Atividade 4.0.cpp` - Ordenação de Strings (Marcas)
* **Descrição:** Aplica **Bubble Sort**, **Insertion Sort**, **Selection Sort** e **Quick Sort** para ordenar alfabeticamente um vetor contendo 50 strings (nomes de grandes marcas de tecnologia, veículos e roupas).
* **Objetivo:** Mostrar como os algoritmos lidam com tipos textuais (comparação direta na tabela ASCII) e exibir uma tabela de desempenho detalhando o número de comparações e movimentações necessárias em cada método.

### 3. `Atividade 5.cpp` - Teste em Lista Quase Ordenada
* **Descrição:** Avalia o comportamento do **Bubble Sort**, **Insertion Sort**, **Selection Sort** e **Quick Sort** em um cenário específico e muito comum na prática: uma lista que já está quase totalmente ordenada `[1, 2, 3, 8, 5, 6, 7, 4]`.
* **Objetivo:** Demonstrar como algoritmos diferentes se comportam dependendo do estado inicial dos dados. O código trabalha com cópias independentes da lista base para garantir a equidade dos testes e demonstra otimizações (como a parada antecipada no Bubble Sort).

---
