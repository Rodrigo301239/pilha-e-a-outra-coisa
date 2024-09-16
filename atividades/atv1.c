#include <stdio.h>
#include <stdlib.h>
# define TAMFILA  10

int cabeca = 0;
int calda = 0;
int fila [TAMFILA] = {0,0,0,0,0,0,0,0,0,0};

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
        enfileirar ();
        break;
    case 2:
        disinfileirar();
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
void lista_elementos (){
    system("cls");
    printf ("| Lista atual |\n");
    for (int i = 0; i < TAMFILA; i++)
    {
       printf(" - ");
       printf ("| %d |",fila [i]);
    }
       printf("\ncabeca: %d\ncalda: %d",cabeca, calda);
       chama_menu ();

}

void enfileirar (){
    int val;

    if (calda < TAMFILA){
      scanf("%d",&val);
      fila [calda] = val;
      calda++;
     lista_elementos ();
    }
    else {
        printf ("a lista esta vazia");
    }
}

void disinfileirar (){
    if (cabeca < calda){
        fila [cabeca] = 0;
        cabeca ++;
        lista_elementos ();
    }
}

void limpar (){
    for (int i = 0; i < TAMFILA; i++)
    {
        fila [i] = 0;
        
    }
    cabeca = 0;
    calda = 0;
    lista_elementos();
}

int main (){
    chama_menu();
}
