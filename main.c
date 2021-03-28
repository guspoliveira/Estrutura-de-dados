#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

typedef struct lista {
    int numero_conta;
    char nome_cliente[60];
    float saldo;
    struct lista* prox;
} Lista;


Lista* inserir_cadastros(Lista* primeiro);
void listar_cadastros(Lista* primeiro);
Lista* excluir_cadastros(Lista* primeiro);
void alterar_cadastros(Lista* primeiro);
void limpa_linha(void);

int main() {


    Lista *primeiro= NULL;
    char opcao;


    while(opcao!='s')
    {



        printf(" %c----------------------------------------------------------------------------%c\n",201,187);
        printf(" | ");
        printf("\t\t\t     CUSTOMER BASE");
        printf("\t\t\t      |\n");
        printf(" %c----------------------------------------------------------------------------%c\n",200,188);
        printf("\t       %c----------%c\t\t\t\t       ",201,187);
        printf("\t\t\t               |   MENU   ");
        printf("|\t\t\t\t      \n");
        printf("   %c-----------%c----------%c------------%c \n",201,200,188,187);
        printf("   | <A>  New account                  |\n");
        printf("   |-----------------------------------|\n");
        printf("   | <B>  Report                       |\n");
        printf("   |-----------------------------------|\n");
        printf("   | <C>  Delete registration          |\n");
        printf("   |-----------------------------------|\n");
        printf("   | <D>  Change registration          |\n");
        printf("   |-----------------------------------|\n");
        printf("   | <S>  Exit                         |\n");
        printf("   %c-----------------------------------%c",200,188);
        printf("\n\n\n\n");


        opcao = getch();


        switch(opcao)
        {
        case 'A':
        case 'a':

            fflush(stdin);
            system("cls");
            printf(" %c----------------------------------------------------------------------------%c\n",201,187);
            printf(" | ");
            printf("\t\t\t          NEW REGISTER     ");
            printf("\t\t\t      |\n");
            printf(" %c----------------------------------------------------------------------------%c\n",200,188);
            primeiro= inserir_cadastros(primeiro);
            getch();
            system("cls");
            break;
        case 'B':
        case 'b':

            system ("cls");
            printf(" %c----------------------------------------------------------------------------%c\n",201,187);
            printf(" | ");
            printf("\t\t\t     REGISTERED ACCOUNTS");
            printf("\t\t\t      |\n");
            printf(" %c----------------------------------------------------------------------------%c\n",200,188);
            listar_cadastros(primeiro);
            getch();
            system("cls");
            break;
        case 'C':
        case 'c':

            system ("cls");
            printf(" %c----------------------------------------------------------------------------%c\n",201,187);
            printf(" | ");
            printf("\t\t\t        DELETE REGISTRATIONS");
            printf("\t\t\t      |\n");
            printf(" %c----------------------------------------------------------------------------%c\n",200,188);
            primeiro= excluir_cadastros(primeiro);
            getch();
            system("cls");
            break;
        case 'D':
        case 'd':

            system ("cls");
            printf(" %c----------------------------------------------------------------------------%c\n",201,187);
            printf(" | ");
            printf("\t\t\t       CHANGE REGISTRATIONS");
            printf("\t\t\t      |\n");
            printf(" %c----------------------------------------------------------------------------%c\n",200,188);
            alterar_cadastros(primeiro);
            getch();
            system("cls");
            break;
        case 'S':
        case 's':

            opcao='s';
            break;
        default:

            system("cls");
            break;
        }
    }
}

void limpa_linha() {
    scanf("%*[^\n]");
    scanf("%*c");
}

Lista* inserir_cadastros(Lista* primeiro) {

    Lista cliente;
    Lista *atual = primeiro;
    char identificador = 'F';


    printf("  Account number: ");
    scanf("%d", &cliente.numero_conta);
    limpa_linha();
    printf ("\n");
    printf("  Name: ");
    fgets(cliente.nome_cliente, 40, stdin);
    printf ("\n");
    printf("  Balance: ");
    scanf("%f", &cliente.saldo);
    limpa_linha();

    printf ("\n");


    for (atual = primeiro; atual != NULL; atual = atual->prox) {
        if (atual->numero_conta == cliente.numero_conta) {
            identificador = 'V';
            break;
        }
    }

    if ( identificador != 'V' && (strlen(cliente.nome_cliente) != 1)) {


        Lista* NovoCliente = malloc (sizeof(Lista));
        strcpy(NovoCliente->nome_cliente, cliente.nome_cliente);
        NovoCliente->saldo = cliente.saldo;
        NovoCliente->numero_conta = cliente.numero_conta;
        NovoCliente->prox = primeiro;
        printf("  Successful registration.");
        printf("\n\n  PRESS ANY KEY TO RETURN TO MAIN MENU.");
        return NovoCliente;
    } else {
        printf("  Invalid registration!");
        printf("\n\n  PRESS ANY KEY TO RETURN TO MAIN MENU.");
        return primeiro;
    }
}




void listar_cadastros(Lista* primeiro) {

    Lista* atual;



    for (atual = primeiro ; atual != NULL; atual = atual->prox) {
        printf("\n  Account: ");
        printf("%d", atual->numero_conta);
        printf("\n  Name: ");
        printf("%s", atual->nome_cliente);
        printf("  Balance: ");
        printf("%.2f", atual->saldo);
        printf("\n\n");
    }
    if ( primeiro == NULL)
        printf("  No Registered Customers.");
    printf("\n\n  PRESS ANY KEY TO RETURN TO MAIN MENU.");
}



Lista* excluir_cadastros(Lista* primeiro) {

    Lista *anterior = NULL;
    Lista *atual = primeiro;
    int numero_conta = 0;



    printf("  Customer code to be deleted: ");
    scanf("%d",&numero_conta);
    limpa_linha();



    while( atual != NULL && atual->numero_conta != numero_conta) {
        anterior = atual;
        atual = atual->prox;
    }



    if (atual == NULL) {
        printf("\n  Client not found.");
        printf("\n\n  PRESS ANY KEY TO RETURN TO MAIN MENU.");
        return primeiro;
    }



    if (anterior == NULL) {
        printf("\n  Content successfully deleted.");
        primeiro= atual->prox;


    } else {
        printf("\n  Content successfully deleted.");
        anterior->prox= atual->prox;
    }



    free(atual);
    printf("\n\n  PRESS ANY KEY TO RETURN TO MAIN MENU.");
    return primeiro;
}



void alterar_cadastros(Lista *primeiro) {

    int numero_contasub;
    char nome_substituto[60];
    float saldo_sub;
    Lista *atual = primeiro;
    int encontrado;



    printf("  Customer code to be changed: ");
    scanf("%d", &numero_contasub);
    limpa_linha();

    encontrado = 0;


    for (atual = primeiro; atual != NULL; atual = atual->prox) {
        if (atual->numero_conta == numero_contasub) {
            encontrado = 1;
            printf("\n  New name: ");
            fgets(nome_substituto, 60, stdin);
            strcpy(atual->nome_cliente, nome_substituto);
            printf("\n  New Balance: ");
            scanf("%f", &saldo_sub);
            limpa_linha();
            printf ("\n");
            atual->saldo = saldo_sub;
            printf("Successfully changed data!");
        }
    }
    if (!encontrado) {
        printf("\nClient not found!");
    }

    printf("\n\n\n  PRESS ANY KEY TO RETURN TO MAIN MENU.");
}
