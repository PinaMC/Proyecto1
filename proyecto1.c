#include <stdio.h>
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
	
	//diferenciar entre cartas en la mano, en  el mazo de ambos, en la "mesa", NO HAY cantidad maxima de crear cartas
	-Menu
	1- 5 cartas muertas es igual a menos 5 vida del jugador??
*/
struct JUGADOR{
	char nombre[60];
	int vida;
	//tablero
	//cartas
};
struct CARTAS{
	char nombreCard[70];
	char tipo[50];
	int vida;
	int ataque;
	int defensa;
	int id;
};
void mostrarCartas(struct CARTAS *cartas) {
	printf("carta");
	printf("Name: %s \n", cartas->nombreCard);
	printf("tipo: %s \n", cartas->tipo);
	printf("vida: %d \n", cartas->vida);
	printf("atq: %d \n", cartas->vida);
	printf("def: %d \n", cartas->vida);
	//printf("id: %d \n", cartas->vida);
	printf("\n");
}

int main(){
	struct CARTAS cartas[14];
	int numCartas = 0;
	//cargar archivo txt
	FILE *file = fopen("The_clash_of_the_guardians.txt", "r");
	
    if (file == NULL) {
        printf("\n**Error** archivo no encontrado\n");
    }
    while (fscanf(file, 
					"%c,%70[^,],%c,%50[^,],%d,%d,%d\n", 
						cartas[numCartas].nombreCard,
			    		&cartas[numCartas].tipo,
			    		&cartas[numCartas].vida,
			    		&cartas[numCartas].ataque,
				  		&cartas[numCartas].defensa) == 7) {
        numCartas++;
        
    }
    fclose(file);
    int a;
    for (int b = 0; b < numCartas; b++){
    	mostrarCartas(&cartas[b]);
	}
  	//printf("%c",cartas[2].nombreCard); 
   
    printf("a"); 
    
	int op; //opciones del menu
	printf("			BIENVENIDO AL JUEGO DE CARTAS \n");
	printf("			The clash of the guardians\n");
	
	
	//menu
	
	printf("\n		~Elige una opcion~\n");
	scanf("%d",&op);
	 while(op != 1 && op != 2 && op != 3 && op != 4){
    	printf("\n	***Opcion invalida, vuelve a ingresar la opcion***\n");
    	scanf("%d",&op);
	}
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
			return 1;
			break;
	default:
		printf("\nERROR EN EL SWITCH\n");
		break;
}

	return 0;
}
