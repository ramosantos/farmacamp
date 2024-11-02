#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct copy{
    int cod[50];
    char nome[100][50];
    int qtd[100];
    }copy;

void venda(){
    int i,j, qtd;
    char vendido[50];
    printf("Qual produto foi vendido?\n");
    scanf("%s",vendido);
    printf("Quantos foram vendidos?\n");
    scanf("%d",&qtd);

    


}


void add_estoque(int codigo){
    FILE* estoque=fopen("estoque.csv", "a");
    int qtd;
    char nome[50];
    fprintf(estoque,"%d,",codigo);
    
    printf("Quantidade:\n");
    scanf("%d",&qtd);
    fprintf(estoque,"%d,",qtd);

    printf("Nome do produto:\n");
    scanf("%s",nome);
    fprintf(estoque,"%s\n",nome);
    
    
    fclose(estoque);
}



void re_estoque(){
    FILE* read=fopen("estoque.csv","r");
    int i=0, cod, qtd;
    struct copy copia;
     printf("Qual produto você quer remover? Dê o codigo\n");
     scanf("%d",&cod);
     printf("Quantas unidades você quer remover?\n");
     scanf("%d", &qtd);

    
   
       
      while(fscanf(read, "%d,%d,%s\n",&copia.cod[i],&copia.qtd[i],copia.nome[i])==3 ){
        i++;
       }
       fclose(read);
       copia.qtd[cod]=copia.qtd[cod]-qtd;
       FILE* write=fopen("estoque.csv","w");

       for(int j=0;j<i;j++){
        fprintf(write, "%d,%d,%s\n",copia.cod[j],copia.qtd[j],copia.nome[j]);

       }
       
      
       fclose(write);
}

void print_estoque(){
    int i=0;
    FILE* read=fopen("estoque.csv","r");
    struct copy copia;
    while(fscanf(read, "%d,%d,%s\n",&copia.cod[i],&copia.qtd[i],copia.nome[i])==3 ){
        i++;
       }

    for(int j=0;j<i;j++){
        printf("Código: %d, Quantidade: %d, Produto: %s\n",copia.cod[j],copia.qtd[j],copia.nome[j]);
    }

}


int main(){
    int i, codigo=0,rem;
    
    
    while(1){
        printf("O que você quer fazer? 1-Gerenciar estoque, 2-Vendas, 3- cliente, 4- relatorio ou 0- sair\n");
        scanf("%d",&i);
        if(i==0){
            return 0;
        }
        if(i==1){
            printf("Você quer: 1-adicionar no estoque, 2-retirar ou 3-printar estoque?\n");
            scanf("%d",&i);
            if(i==1){
                add_estoque(codigo);
                codigo++;

            }
            if(i==2){
               

                re_estoque();
                //return 0;

            }
            if(i==3){
                print_estoque();
            }

        }
        if(i==2){

        }
    }
}