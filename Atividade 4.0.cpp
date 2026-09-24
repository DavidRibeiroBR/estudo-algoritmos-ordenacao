#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
// Estrutura para rastrear o desempenho
struct ContadorOperacoes {
    long long totalComparacoes = 0;
    long long totalTrocas = 0;
};

// 1. Bubble Sort para Strings
void executarBubbleSort(vector<string>& vetor, ContadorOperacoes& contador) {
    int tamanho = vetor.size();
    for (int passada = 0; passada < tamanho - 1; passada++) {
        bool houveTroca = false;
        for (int i = 0; i < tamanho - passada - 1; i++) {
            contador.totalComparacoes++;
            // Comparação alfabética direta utilizando '>'
            if (vetor[i] > vetor[i + 1]) {
                swap(vetor[i], vetor[i + 1]);
                contador.totalTrocas++;
                houveTroca = true;
            }
        }
        if (!houveTroca) break;
    }
}

// 2. Insertion Sort para Strings
void executarInsertionSort(vector<string>& vetor, ContadorOperacoes& contador) {
    int n = vetor.size();
    for (int i = 1; i < n; i++) {
        string chave = vetor[i];
        int j = i - 1;
        while (j >= 0) {
            contador.totalComparacoes++;
            if (vetor[j] > chave) {
                vetor[j + 1] = vetor[j];
                contador.totalTrocas++;
                j--;
            } else {
                break;
            }
        }
        vetor[j + 1] = chave;
    }
}

// 3. Selection Sort para Strings
void executarSelectionSort(vector<string>& vetor, ContadorOperacoes& contador) {
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

// Particionamento do Quick Sort para Strings
int particionarVetor(vector<string>& vetor, int indiceInicio, int indiceFim, ContadorOperacoes& contador) {
    string valorPivo = vetor[indiceFim];
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

// 4. Quick Sort para Strings
void executarQuickSort(vector<string>& vetor, int indiceInicio, int indiceFim, ContadorOperacoes& contador) {
    if (indiceInicio < indiceFim) {
        int posicaoPivo = particionarVetor(vetor, indiceInicio, indiceFim, contador);
        executarQuickSort(vetor, indiceInicio, posicaoPivo - 1, contador);
        executarQuickSort(vetor, posicaoPivo + 1, indiceFim, contador);
    }
}

int main() {
    // Lista com 50 palavras (Nomes de Marcas com inicial maiúscula para manter precisão na tabela ASCII)
    vector<string> listaMarcas = {
        "Apple", "Samsung", "Nike", "Adidas", "Microsoft", "Google", "Amazon", "Toyota", "Honda", "Ford",
        "Chevrolet", "Coca-cola", "Pepsi", "Mcdonalds", "Burgerking", "Sony", "Nintendo", "Playstation", "Xbox", "Asus",
        "Acer", "Lenovo", "Hp", "Dell", "Intel", "Amd", "Nvidia", "Logitech", "Corsair", "Razer",
        "Ferrari", "Porsche", "Bmw", "Audi", "Mercedes", "Volkswagen", "Fiat", "Renault", "Peugeot", "Citroen",
        "Zara", "Gucci", "Prada", "Rolex", "Casio", "Seiko", "Yamaha", "Kawasaki", "Suzuki", "Harley-davidson"
    };

    // Criação de cópias independentes
    vector<string> vetorBubble = listaMarcas;
    vector<string> vetorInsertion = listaMarcas;
    vector<string> vetorSelection = listaMarcas;
    vector<string> vetorQuick = listaMarcas;

    ContadorOperacoes contBubble, contInsertion, contSelection, contQuick;

    // Aplicação dos algoritmos
    executarBubbleSort(vetorBubble, contBubble);
    executarInsertionSort(vetorInsertion, contInsertion);
    executarSelectionSort(vetorSelection, contSelection);
    executarQuickSort(vetorQuick, 0, vetorQuick.size() - 1, contQuick);

    // Impressão da Tabela de Desempenho
    printf("\nDesempenho na Ordenacao de 50 Palavras:\n\n");
    printf("%20s %15s %15s\n", "Algoritmo", "Comparacoes", "Trocas/Mov.");
    printf("------------------------------------------------------------------\n");
    printf("%20s %15lld %15lld\n", "Bubble Sort", contBubble.totalComparacoes, contBubble.totalTrocas);
    printf("%20s %15lld %15lld\n", "Insertion Sort", contInsertion.totalComparacoes, contInsertion.totalTrocas);
    printf("%20s %15lld %15lld\n", "Selection Sort", contSelection.totalComparacoes, contSelection.totalTrocas);
    printf("%20s %15lld %15lld\n", "Quick Sort", contQuick.totalComparacoes, contQuick.totalTrocas);
    printf("------------------------------------------------------------------\n\n");

    // Demonstração visual de que a lista foi ordenada alfabeticamente (mostrando os 5 primeiros)
    printf("Visualizacao elementps:\n");
    for(int i = 0; i < 50; i++) {
        cout << i+1 << ". " << vetorQuick[i] << endl;
    }

    return 0;
}