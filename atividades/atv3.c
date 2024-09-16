#include <stdio.h>
#include <stdlib.h>
# define TAMFILA  10

int cabeca = 0, topo = 0;
int calda = 0;
int pilha [TAMFILA] = {0,0,0,0,0,0,0,0,0,0};

void limpar_tela() {
    system("cls");
}

void chama_menu (){
    int opcao,numero;
    printf ("\ndigite\n1 - para adicionar um numero\n2 - para excluir um numero da fila\n3 - para limpar a fila\n4 - lista\n5 - encerrar ");
    scanf ("%d",&opcao);

    switch (opcao)
    {
    case 1:
        printf ("digite o numero: ");
        push ();
        break;
    case 2:
        pop();
        break;
    case 3:
        limpar ();
        break;
    case 4:
        lista_elementos();
        break;
    case 5:
        break;
    default:
        printf ("opcao incorreta, tente novamente");
    }
}
void pilha_elementos (){
    system("cls");
    printf ("| Lista atual |\n");
    for (int i = topo - 1; i >= 0; i--)
    {
       printf(" - ");
       printf ("| %d |",pilha [i]);
    }
       printf("\ntopo : %d",topo);
       chama_menu ();

}

void push (){
    int val;

    printf ("informe um valor: ");
    scanf ("%d",&val);
    if (topo < TAMFILA)
    {
       pilha [topo] = val;
       topo ++;
       pilha_elementos();
    }
    else {
            printf ("pilha esta cheia");
    }
    
}

void pop (){
    if (topo >= 0){
        pilha [topo - 1] = 0;
        topo --;
        pilha_elementos ();

    }
    else {
        printf ("pilha esta vazia");

    }
}

int main (){
    chama_menu();
    return 0;
}