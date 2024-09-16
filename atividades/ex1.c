#include <stdio.h>
#include <stdlib.h> // Para system()

#define TAMFILA 10

int topo = 0;
int pilha[TAMFILA] = {0};

void limpar_tela() {
    #ifdef _WIN32
        system("cls"); // Windows
    #else
        system("clear"); // Linux/Unix
    #endif
}

void chama_menu();

void lista_elementos() {
    limpar_tela();
    printf("| Lista atual |\n");
    if (topo == 0) {
        printf("Pilha vazia.\n");
    } else {
        for (int i = topo - 1; i >= 0; i--) {
            printf(" - ");
            printf("| %d |\n", pilha[i]);
        }
    }
    printf("Topo: %d\n", topo);
    chama_menu();
}

void push() {
    int val;

    if (topo < TAMFILA) {
        printf("Informe um valor: ");
        scanf("%d", &val);
        pilha[topo] = val;
        topo++;
        lista_elementos();
    } else {
        printf("Pilha cheia. Não é possível adicionar mais elementos.\n");
        chama_menu();
    }
}

void pop() {
    if (topo > 0) {
        topo--;
        printf("Valor %d removido da pilha.\n", pilha[topo]);
        pilha[topo] = 0; // Opcional: Limpar o valor removido
        lista_elementos();
    } else {
        printf("Pilha vazia. Não há elementos para remover.\n");
        chama_menu();
    }
}

void chama_menu() {
    int opcao;
    printf("\nDigite\n1 - para adicionar um número\n2 - para excluir um número da pilha\n3 - listar\n4 - encerrar\n");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            lista_elementos();
            break;
        case 4:
            printf("Encerrando...\n");
            exit(0);
        default:
            printf("Opção incorreta, tente novamente.\n");
            chama_menu();
    }
}

int main() {
    chama_menu();
    return 0;
}