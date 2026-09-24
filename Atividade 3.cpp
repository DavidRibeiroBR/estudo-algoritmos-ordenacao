#include <stdio.h> 
#include <vector> 
#include <cstdlib> 
#include <ctime> 
#include <cstdio> 
using namespace std; 
 
// Armazena as contagens de operações 
struct ContadorOperacoes { 
    long long totalComparacoes = 0; 
    long long totalTrocas = 0; 
}; 
// Algoritmo Bubble Sort 
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
// Função de particionamento do Quick Sort 
int particionarVetor(vector<int>& vetor, int indiceInicio, int indiceFim, 
                     ContadorOperacoes& contador) { 
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
    // Posiciona o pivô no local correto 
    swap(vetor[indiceMenores + 1], vetor[indiceFim]); 
    contador.totalTrocas++; 
    return indiceMenores + 1; 
} 
// Algoritmo Quick Sort 
void executarQuickSort(vector<int>& vetor, int indiceInicio, int indiceFim, 
                       ContadorOperacoes& contador) { 
    if (indiceInicio < indiceFim) { 
        int posicaoPivo = particionarVetor(vetor, indiceInicio, indiceFim, contador); 
        // Ordena as sub-listas da esquerda e direita 
        executarQuickSort(vetor, indiceInicio, posicaoPivo - 1, contador); 
        executarQuickSort(vetor, posicaoPivo + 1, indiceFim,contador); 
    } 
} 
 
// Gera números aleatórios entre 0 e 9999 
vector<int> gerarVetorAleatorio(int tamanho) { 
    vector<int> vetorGerado(tamanho); 
 
    for (int i = 0; i < tamanho; i++) { 
        vetorGerado[i] = rand() % 10000; 
    } 
    return vetorGerado; 
} 
int main() { 
    // Semente para geração aleatória 
    srand(time(0)); 
    vector<int> tamanhosTeste = {10, 20, 1000}; 
    // Cabeçalho da tabela 
    printf("%-18s %-25s %-25s %-25s %-25s\n", 
           "Tamanho do Array","Bubble Sort - Comp.","Bubble Sort - Trocas","Quick Sort - Comp.", 
           "Quick Sort - Mov."); 
 
    for (int tamanho : tamanhosTeste) { 
        // Gera vetor original 
        vector<int> vetorBase = gerarVetorAleatorio(tamanho); 
        // Cria cópias idênticas 
        vector<int> vetorParaBubble = vetorBase; 
        vector<int> vetorParaQuick = vetorBase; 
        ContadorOperacoes contadorBubble; 
        ContadorOperacoes contadorQuick; 
        // Executa Bubble Sort 
        executarBubbleSort(vetorParaBubble, contadorBubble); 
         
        // Executa Quick Sort 
        executarQuickSort(vetorParaQuick, 0, vetorParaQuick.size() - 1, contadorQuick ); 
        // Exibe os resultados 
        printf("%-18d %-25lld %-25lld %-25lld %-25lld\n", 
               tamanho, 
               contadorBubble.totalComparacoes, 
               contadorBubble.totalTrocas, 
               contadorQuick.totalComparacoes, 
               contadorQuick.totalTrocas); 
    } 
    return 0; 
} 
