#include <stdio.h>
#include <stdint.h>
#include <locale.h>
#include <string.h>

#define N 2

typedef struct Jogador{
    int idade;
    int salario;
    char nome[50];
    char posicao[25];
} JOGADOR;


// --> Função para Cadastrar N Jogadores <-- \\

void cadastrarJogador(JOGADOR J[N]){ // metodo para cadastrar jogadores
    int i;    
    
    for(i = 0; i < N; i++){ // esse for passa o cadastro N vezes
        printf("Digite o Nome do Jogador: ");
        scanf("%s", J[i].nome);
        printf("Digite a Idade do Jogador: ");
        scanf("%d", &J[i].idade);
        printf("Digite a Posição do Jogador: ");
        scanf("%s", J[i].posicao);
        printf("Digite o Salário do Jogador: ");
        scanf("%d", &J[i].salario);
        printf("Jogador %s Cadastrado com Sucesso!\n\n", J[i].nome);
    } 
}

// --> Função para Mostrar Jogador com Maior Salario <-- \\

JOGADOR maiorSalario(JOGADOR J[N]) {
    int i;
    JOGADOR jMSal = J[0]; // declarando uma variavel que começa na posição 0

    for (i = 0; i < N; i++) {
        if (J[i].salario > jMSal.salario) { // comparando os salarios com a variavel jMSal que começa na posição 0
            jMSal = J[i];
        }
    }
    return jMSal;
}

// --> Função para Mostrar o Nome de Todos os Jogadores Cadastrados  <-- \\

void todosJogadores(JOGADOR J[]){
	int i;
	
	for (i = 0; i < N; i++){
		printf("Jogadores Cadastrados: %s\n", J[i].nome);
	}
}


void main(){
	JOGADOR J[N];
    JOGADOR jMSal; // declarando jMSal p conseguir puxar no case 2
    JOGADOR num_jogadores;
    
    int op;
    
    setlocale(LC_ALL, "Portuguese");
    
    printf("Seja Bem Vindo ao Sistema de Jogadores!\n");
    printf("Escolha uma Opção Abaixo\n\n");
    
    do{
        printf("1 - Cadastrar Jogador\n");
        printf("2 - Mostrar Jogador com Maior Salário\n");
        printf("3 - Mostrar Jogadores Cadastrados\n");
        printf("4 - Sair do Programa\n");
        printf("Sua Opção: ");
        scanf("%d", &op);
  		printf("\n");
    
        switch(op){
            case 1: 
                cadastrarJogador(J);
                break;
            case 2:
				jMSal = maiorSalario(J);
                printf("%s é o Jogador com Maior Salario, Recebendo %d mil\n\n", jMSal.nome, jMSal.salario);
                break;
            case 3:
				todosJogadores(J);
                break;
            case 4:
                break;
        }
    } while(op != 4);
        printf("Saindo do Programa...");
        return 0;
}
