#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das cartas
// Objetivo: No nível novato você deve criar as cartas representando as cidades utilizando scanf para entrada de dados e printf para exibir as informações.

/*
	Struct que define as propriedades de uma Carta.
*/
typedef struct Carta {
	char nome[40];
	char codigo[3];
	char estado[1];
	float area;
	float pib;
	int populacao;
	int numPontosTuristicos;
	int indice;
} Carta;

/*
	Essa função é responsável por imprimir as informações
	da carta.
	- Carta *carta: ponteiro para a carta a ser imprimda.
*/
void ImprimirCarta(Carta *carta);

/*
	Essa função é responsável por preencher a Struct da carta
	com as entradas do usuário utilizando a função scanf(...).

	- Carta *carta: ponteiro para a carta que receberá as entradas.
	- int indice: número da carta sendo preenchda.
*/
void PreencherCartaSolicitandoUsuario(Carta *carta, int indice);

int main() {
	// Área para definição das variáveis para armazenar as propriedades das cidades
	Carta carta1, carta2;

	// Área para entrada de dados
	PreencherCartaSolicitandoUsuario(&carta1, 1);
	PreencherCartaSolicitandoUsuario(&carta2, 2);

	// Área para exibição dos dados da cidade
	ImprimirCarta(&carta1);
	ImprimirCarta(&carta2);

	return 0;
}

void PreencherCartaSolicitandoUsuario(Carta *carta, int indice) {
	carta->indice = indice;

	printf("\nInicio do cadastro da Carta %d.", carta->indice);

	printf("\nInforme o Estado da Carta (Uma letra de 'A' a 'H'):");
	scanf(" %c", carta->estado);

	printf("\nInforme o Codigo da Carta (A01, B03):");
	scanf("%3s", carta->codigo);

	getchar(); // limpa o '\n' do buffer
	printf("\nInforme o Nome da Cidade da Carta:");
	fgets(carta->nome, sizeof(carta->nome), stdin);
	carta->nome[strcspn(carta->nome, "\n")] = 0;

	printf("\nInforme o Numero de Habitantes:");
	scanf("%d", &carta->populacao);

	printf("\nInforme a Area da Cidade:");
	scanf("%f", &carta->area);

	printf("\nInforme o PIB da Carta:");
	scanf("%f", &carta->pib);

	printf("\nInforme o Numero de Pontos Turisticos:");
	scanf("%d", &carta->numPontosTuristicos);

	printf("\nFim do cadastro da Carta %d.", indice);
}

void ImprimirCarta(Carta *carta) {
	printf("Informacoes da Carta %d: \n", carta->indice);
	printf("   - Estado    : %s \n", carta->estado);
	printf("   - Codigo    : %s \n", carta->codigo);
	printf("   - Nome      : %s \n", carta->nome);
	printf("   - Populacao : %d \n", carta->populacao);
	printf("   - PIB       : %f bilhoes de reais \n", carta->pib);
	printf("   - Area      : %f km^2 \n", carta->area);
	printf("   - N. Pontos Turisticos : %d \n", carta->numPontosTuristicos);
}