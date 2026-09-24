#include <stdio.h> 
#include <vector> 
#include <algorithm>

using namespace std; 

// Armazena as contagens de operações 
struct ContadorOperacoes { 
    long long totalComparacoes = 0; 
    long long totalTrocas = 0; 
}; 

// 1. Algoritmo Bubble Sort (com otimização de paragem)
void executarBubbleSort(vector<int>& vetor, ContadorOperacoes& contador) { 
    int tamanhoVetor = vetor.size(); 
    for (int passada = 0; passada < tamanhoVetor - 1; passada++) { 
        bool houveTroca = false; 
        for (int indiceAtual = 0; indiceAtual < tamanhoVetor - passada - 1; indiceAtual++) { 
            contador.totalComparacoes++; 
            if (vetor[indiceAtual] > vetor[indiceAtual + 1]) { 
                swap(vetor[indiceAtual], vetor[indiceAtual + 1]); 
                contador.totalTrocas++; 
                houveTroca = true; 
            } 
        } 
        // Interrompe se o vetor já estiver ordenado 
        if (!houveTroca) 
            break; 
    } 
} 

// 2. Algoritmo Insertion Sort
void executarInsertionSort(vector<int>& vetor, ContadorOperacoes& contador) {
    int n = vetor.size();
    for (int i = 1; i < n; i++) {
        int chave = vetor[i];
        int j = i - 1;
        while (j >= 0) {
            contador.totalComparacoes++;
            if (vetor[j] > chave) {
                vetor[j + 1] = vetor[j];
                contador.totalTrocas++; // Contabilizado como deslocamento/troca
                j--;
            } else {
                break;
            }
        }
        vetor[j + 1] = chave;
    }
}

// 3. Algoritmo Selection Sort
void executarSelectionSort(vector<int>& vetor, ContadorOperacoes& contador) {
    int n = vetor.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            contador.totalComparacoes++;
            if (vetor[j] < vetor[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(vetor[i], vetor[min_idx]);
            contador.totalTrocas++;
        }
    }
}

// Função de particionamento do Quick Sort 
int particionarVetor(vector<int>& vetor, int indiceInicio, int indiceFim, ContadorOperacoes& contador) { 
    int valorPivo = vetor[indiceFim]; 
    int indiceMenores = indiceInicio - 1; 
    for (int indiceAtual = indiceInicio; indiceAtual < indiceFim; indiceAtual++) { 
        contador.totalComparacoes++; 
        if (vetor[indiceAtual] <= valorPivo) { 
            indiceMenores++; 
            swap(vetor[indiceMenores], vetor[indiceAtual]); 
            contador.totalTrocas++; 
        } 
    } 
    swap(vetor[indiceMenores + 1], vetor[indiceFim]); 
    contador.totalTrocas++; 
    return indiceMenores + 1; 
} 

// 4. Algoritmo Quick Sort 
void executarQuickSort(vector<int>& vetor, int indiceInicio, int indiceFim, ContadorOperacoes& contador) { 
    if (indiceInicio < indiceFim) { 
        int posicaoPivo = particionarVetor(vetor, indiceInicio, indiceFim, contador); 
        executarQuickSort(vetor, indiceInicio, posicaoPivo - 1, contador); 
        executarQuickSort(vetor, posicaoPivo + 1, indiceFim, contador); 
    } 
} 

int main() { 
    // Definição da lista quase ordenada
    vector<int> listaBase = {1, 2, 3, 8, 5, 6, 7, 4};
    
    
    // Criação de cópias independentes da lista original.
    // Isso é necessário porque os algoritmos alteram (ordenam) a lista original.
    // Sem essas cópias, o segundo algoritmo receberia a lista já ordenada pelo primeiro,
    // o que invalidaria o teste de desempenho para o cenário quase ordenado.
    vector<int> vetorBubble = listaBase; 
    vector<int> vetorInsertion = listaBase; 
    vector<int> vetorSelection = listaBase; 
    vector<int> vetorQuick = listaBase; 
    
    ContadorOperacoes contBubble, contInsertion, contSelection, contQuick; 
    
    // Execução
    executarBubbleSort(vetorBubble, contBubble); 
    executarInsertionSort(vetorInsertion, contInsertion);
    executarSelectionSort(vetorSelection, contSelection);
    executarQuickSort(vetorQuick, 0, vetorQuick.size() - 1, contQuick); 
    
    // Impressão dos resultados
    // Formatação para criar uma visualização em formato de tabela:
    printf("Resultados para a lista parcialmente ordenada [1, 2, 3, 8, 5, 6, 7, 4]:\n\n");
    
    printf("%20s %15s %15s\n", "Algoritmo", "Comparacoes", "Trocas/Mov."); 
    printf("------------------------------------------------------------------\n");
    printf("%20s %15lld\n", "Insertion Sort", contInsertion.totalComparacoes, contInsertion.totalTrocas); 
    printf("%20s %15lld %15lld\n", "Bubble Sort", contBubble.totalComparacoes, contBubble.totalTrocas); 
    printf("%20s %15lld %15lld\n", "Selection Sort", contSelection.totalComparacoes, contSelection.totalTrocas); 
    printf("%20s %15lld %15lld\n", "Quick Sort", contQuick.totalComparacoes, contQuick.totalTrocas); 
    printf("------------------------------------------------------------------\n");
    
    return 0; 
}