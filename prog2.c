#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct estoque{
    int cod[50];
    char nome[100][50];
    int qtd[100];
} estoque;

typedef struct clientes{
    int cod[50];
    char nome[100][50];
    int idade[100];
    long telefone[100];
} clientes;

struct estoque copia_estoque() {
    int i=0;
    struct estoque copia;
    FILE* read=fopen("estoque.csv","r");
    while(fscanf(read, "%d,%d,%s\n",&copia.cod[i],&copia.qtd[i],copia.nome[i])==3 ){
        i++;
       }
       fclose(read);
       return copia;
}

struct clientes copia_clientes() {
    int i=0;
    struct clientes copia;
    FILE* arquivo = fopen("clientes.csv","r");
    while(fscanf(arquivo, "%d,%s,%d,%li\n",&copia.cod[i],copia.nome[i],&copia.idade[i], &copia.telefone[i])==4 )
    {
        i++;
    } fclose(arquivo);
    return copia;
}

int mensurar_base(int base){
    int codigo, linhas = 0;

    char* nome_arquivo = base ? "estoque.csv" : "clientes.csv";

    FILE* arquivo = fopen(nome_arquivo,"r");
    if (arquivo == NULL) return 0;
    
    switch(base)
    {
        case 0:
            struct estoque copia;
            while(fscanf(arquivo, "%d,%d,%s\n",&copia.cod[linhas],&copia.qtd[linhas],copia.nome[linhas])==3 )
            {
                linhas++;
            } fclose(arquivo);
            break;
        
        case 1:
            struct clientes cadastros;
            while(fscanf(arquivo, "%d,%s,%d,%li\n",&cadastros.cod[linhas], cadastros.nome[linhas],&cadastros.idade[linhas], &cadastros.telefone[linhas])==4 )
            {
                linhas++;
            } fclose(arquivo);
            break;
    }

    return linhas;
}

void add_estoque(){
    FILE* estoque=fopen("estoque.csv", "a");
    int codigo = mensurar_base(0) + 1;
    char nome[50];
    int qtd;

    fprintf(estoque,"%d,",codigo);  
    printf("Quantidade do produto:\n");
    scanf("%d",&qtd);
    fprintf(estoque,"%d,",qtd);
    printf("Nome do produto:\n");
    scanf("%s",nome);
    fprintf(estoque,"%s\n",nome);
    fclose(estoque);
}

void re_estoque(int cod, int qtd){   
    int i = mensurar_base(0);
    struct estoque copia = copia_estoque();
    if(qtd > copia.qtd[cod])
    {
        printf("Redução de estoque maior que quantidade atual.\n");
        return;
    }

    copia.qtd[cod] = copia.qtd[cod] - qtd;

    FILE* write=fopen("estoque.csv","w");
       for(int j=0;j<i;j++){
        fprintf(write, "%d,%d,%s\n",copia.cod[j],copia.qtd[j],copia.nome[j]);
       }   
       fclose(write);
}

void print_estoque(){
    int i=0;
    FILE* read=fopen("estoque.csv","r");
    struct estoque copia;
    while(fscanf(read, "%d,%d,%s\n",&copia.cod[i],&copia.qtd[i],copia.nome[i])==3 ){
        i++;
       }

    printf("\n");
    for(int j=0;j<i;j++){
        printf("Código: %d, Quantidade: %d, Produto: %s\n",copia.cod[j],copia.qtd[j],copia.nome[j]);
    }
    printf("\n");
}

void realizar_venda()
{
    int cod, qtd;
    printf("Qual produto foi vendido? Dê o código\n");
    scanf("%d",&cod);
    printf("Quantos foram vendidos?\n");
    scanf("%d",&qtd);
    re_estoque(cod, qtd);
}

void cadastrar()
{
    FILE* clientes = fopen("clientes.csv", "a");
    int codigo = mensurar_base(1) + 1;
    char nome[50];
    int qtd, idade;
    long telefone;

    fprintf(clientes,"%d,",codigo);

    printf("Nome:\n");
    scanf("%s", nome);
    fprintf(clientes,"%s,", nome);

    printf("Idade:\n");
    scanf("%d", &qtd);
    fprintf(clientes,"%d,", qtd);

    printf("Telefone:\n");
    scanf("%li", &telefone);
    fprintf(clientes,"%li\n",telefone);

    fclose(clientes);
}

int main(){
    int primeira_opcao, segunda_opcao, codigo = 0, rem, cod, qtd;

    while(1){
        printf("O que voce quer fazer?\n1 - Gerenciar estoque\n2 - Realizar venda\n3 - Cadastrar cliente\n4 - Ver relatorios\nou 0- Sair\n");
        scanf("%d",&primeira_opcao);

        switch(primeira_opcao) {
            case 0: // Sair
                return 0;

            case 1: // Estoque
                printf("O que voce quer?\n1 - Adicionar produto\n2 - Retirar produto\nou 3 - Printar estoque\n");

                scanf("%d",&segunda_opcao);
                switch(segunda_opcao) {
                    case 1:
                        add_estoque();
                        break;
                    case 2:
                        printf("Qual produto você quer remover? Dê o codigo\n");
                        scanf("%d",&cod);
                        printf("Quantas unidades você quer remover?\n");
                        scanf("%d", &qtd);
                        re_estoque(cod,qtd);
                        //return 0;
                        break;
                    case 3:
                        print_estoque();
                        break;
                }
                break;

            case 2: // Vendas
                realizar_venda();
                break;
            
            case 3: // Clientes
                cadastrar();
            break;
        
            case 4: // Relatórios
            break;

            default:
                break;
        }
    }
}
