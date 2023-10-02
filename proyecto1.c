#include<stdio.h>
#include <stdlib.h>
#include <string.h>
/* juego de cartas por equipos, 
	*Se pueden crear cartas nuevas
	5 puntos de vida
	60 cartas o mas distintas
	*puede crear varias cartas
	-Debe tener tipo de carta (vikinga, barbaro, bandido, etc) ataque, defensa, vida
	-El juego de cartas se leera desde un archivo txt (puede cambiarlo el profe, por lo que debes validar lo que ingrese en el txt)
	-Historial de la partida (validar )
	-Se tiene que validar casi todo (basicamente todo)
	archivo tiene que ser puntos 
	*listas, colas o pilas
	*IA simulacion de jugador
	
	
	-Menu
	1-
*/
struct JUGADOR{
	char nombre[70];
	int vida;
};
struct CARTAS{
	char nombreCard[40];
	int tipo;
	int id;
	int vida;
	int defensa;
	int ataque;
};

//FILE *file = fopen("company_data.txt", "r");
int main(){

	int op; //opciones del menu
	printf("			BIENVENIDO AL JUEGO DE CARTAS \n");
	printf("			The clash of the guardians\n");
	
	//cargar archivo txt
	FILE *file = fopen("company_data.txt", "r");
	
	//menu
	printf("\n		~Elige una opcion~\n")
	switch(op) {
		case 1:
			printf("\n Jugar\n");
			break;
		
		case 2: 
			printf("\n Crear carta \n");
			break;
			
		case 3: 
			break;
		case 4: 
			printf("\n Mostrar Historial\n");
			break;
			
		case 5: 
			printf("\n Eligio salir del juego\n");
			break;
	default:
}

	
	printf("\nMenu \n");
	return 0;
}
