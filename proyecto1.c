#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
//Vicente Farias Piña
//variables definidas para ahorrar tiempo y cambiar los valores minimos y maximo de validacion
#define vidaMin 1
#define vidaMax 9
#define atqMax 10
#define atqMin 2
#define defMax 8
#define defMin 1

//ubicacion del archivo C:\Users\vicen\OneDrive - Universidad de Talca\Escritorio\UTAL CLASES\semestre 4\U1 Algoritmos\Proyecto1>
struct JUGADOR{
	char nombre[60];
	int vida;
	//tablero
	//cartas
};
struct CARTAS{
	char nombre[70];
	char tipo[50];
	int vida;
	int ataque;
	int defensa;
	int id;
};
struct NodoCarta {
    struct CARTAS carta;
    struct NodoCarta* siguiente;
};

void insertarCarta(struct NodoCarta** cabeza, struct CARTAS nuevaCarta) {//agrega una nueva carta al inicio de la lista
    struct NodoCarta* nuevoNodo = (struct NodoCarta*)malloc(sizeof(struct NodoCarta));
    if (!nuevoNodo) {
        printf("Error al asignar memoria para el nodo.\n");
        exit(EXIT_FAILURE);
    }

    nuevoNodo->carta = nuevaCarta;
    nuevoNodo->siguiente = *cabeza;
    *cabeza = nuevoNodo;
}

void mostrarCartas(struct NodoCarta* cabeza) {
    struct NodoCarta* actual = cabeza;

    while (actual != NULL) {
        printf("Nombre: %s\n", actual->carta.nombre);
        printf("Tipo: %s\n", actual->carta.tipo);
        printf("Vida: %d\n", actual->carta.vida);
        printf("Ataque: %d\n", actual->carta.ataque);
        printf("Defensa: %d\n\n", actual->carta.defensa);

        actual = actual->siguiente;
    }
}
struct CARTAS ingresarNuevaCarta(){//crea una nueva carta pidendo los datos al usuario
	struct CARTAS nuevaCarta;
	int tipoCarta =0;
	printf("\n------------Reglas para crear cartas---------");
	printf("\nIngresa el nombre de la nueva carta que ingresaras");
	printf("\nExisten 4 tipos de cartas (Magos, Vikingo, Nigromante, Bestias)");
	printf("\nLas cartas tienen vida min %d y vida maxima",vidaMin, vidaMax);
	printf("\nLas cartas tienen atq min %d y atq maxima %d",atqMin,atqMax);
	printf("\nLas cartas tienen def min %d y def maxima %d",defMin,defMax);
	
	printf("\nIngresa el nombre de la carta: \n");
    scanf(" %[^\n]", nuevaCarta.nombre);
    printf("\nIngrese el tipo de la carta: \n");
    do {
        printf("\nIngrese el tipo de la carta (1:Mago, 2:Vikingo, 3:Nigromante, 4:Bestia): ");
        scanf("%d", &tipoCarta);

        if (tipoCarta < 1 || tipoCarta > 4) {
            printf("\n***Opcion invalida, vuelve a ingresar la opcion***\n");
        }
    } while (tipoCarta < 1 || tipoCarta > 4);

    switch (tipoCarta) {
        case 1:
            strcpy(nuevaCarta.tipo, "Mago");
            break;
        case 2:
            strcpy(nuevaCarta.tipo, "Vikingo");
            break;
        case 3:
            strcpy(nuevaCarta.tipo, "Nigromante");
            break;
        case 4:
            strcpy(nuevaCarta.tipo, "Bestia");
            break;
        default:
            break;
    }
    do {
        printf("Ingrese la vida de la carta: ");
        scanf("%d", &nuevaCarta.vida);
        if (nuevaCarta.vida < vidaMin || nuevaCarta.vida > vidaMax) {
            printf("La vida debe estar entre %d y %d\n", vidaMin, vidaMax);
        }
    } while (nuevaCarta.vida < vidaMin || nuevaCarta.vida > vidaMax);

    do {
        printf("Ingrese el ataque de la carta: ");
        scanf("%d", &nuevaCarta.ataque);
        if (nuevaCarta.ataque < atqMin || nuevaCarta.ataque > atqMax) {
            printf("El ataque debe estar entre %d y %d\n", atqMin, atqMax);
        }
    } while (nuevaCarta.ataque < atqMin || nuevaCarta.ataque > atqMax);

    do {
        printf("Ingrese la defensa de la carta: ");
        scanf("%d", &nuevaCarta.defensa);
        if (nuevaCarta.defensa < defMin || nuevaCarta.defensa > defMax) {
            printf("La defensa debe estar entre %d y %d\n", defMin, defMax);
        }
    } while (nuevaCarta.defensa < defMin || nuevaCarta.defensa > defMax);
	
	return nuevaCarta;
}
void mostrarReglas(){
	printf("\n _____________________________________________________________________________________________________\n");
	printf("\n|                                                                                                     |\n");
	printf("\n|                                     ***REGLAS***					              |\n");
	printf("\n|-----------------------------------------------------------------------------------------------------|\n");
	printf("\n| 1- Cada jugador tendra que defender a su 'Reinado' del enemigo usando cartas cargadas desde un txt. |\n");
	printf("\n| 2- El jugador antes de iniciar la partida puede crear nuevas cartas, pero con algunas limitaciones. |\n");
	printf("\n| 3- El juego se gana cuando uno de los 2 juagdores pierde 5 puntos de vida.                          |\n");
	printf("\n| 4- Al momento de jugar el jugador tiene que colocar una carta antes de atacar al rival.             |\n");
	printf("\n| 5- El jugador puede unicamente atacar a las cartas del enemigo, mas no al rival directamente.       |\n");
	printf("\n| 6- Cuando el jugador o el rival elimine una carta se restara en uno la vida del jugador.            |\n");
	printf("\n| 7- El jugador debe ingresar su nombre antes de jugar.                                               |\n");
	printf("\n|_____________________________________________________________________________________________________|\n");
}
void agregarCartaAlFinal(struct NodoCarta** cabeza, struct CARTAS nuevaCarta) {
    struct NodoCarta* nuevoNodo = (struct NodoCarta*)malloc(sizeof(struct NodoCarta));
    if (!nuevoNodo) {
        printf("Error al asignar memoria para el nodo.\n");
        exit(EXIT_FAILURE);
    }

    nuevoNodo->carta = nuevaCarta;
    nuevoNodo->siguiente = NULL;

    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
    } else {
        struct NodoCarta* actual = *cabeza;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
}

int main(){
	
	struct NodoCarta* listaCartas = NULL;
	int numCartas = 0;
	
	FILE *file = fopen("The_clash_of_the_guardians.txt", "r"); //cargar archivo txt
	
    if (file == NULL) {
        printf("\n**Error** archivo no encontrado\n");
        return 1;
    }
    struct CARTAS nuevaCarta;
    while (fscanf(file, 
    
			"%70[^,],%50[^,],%d,%d,%d\n", 
		    nuevaCarta.nombre,
	        nuevaCarta.tipo,
	        &nuevaCarta.vida,
	        &nuevaCarta.ataque,
	        &nuevaCarta.defensa) == 5) 
    {
    	numCartas++;
        insertarCarta(&listaCartas, nuevaCarta);
    }
    fclose(file);
  	mostrarCartas(listaCartas);

	printf("\ncantidad de cartas: %d\n",numCartas);
	int op; //opciones del menu
	printf("			BIENVENIDO AL JUEGO DE CARTAS \n");
	printf("			The clash of the guardians\n");
	mostrarReglas();
	//menu
	printf("\nElije una opcion:\n");
	printf("\n 		***1- Jugar***\n");
	printf("\n 		***2- Crear carta*** \n");
	printf("\n		***3- Mostrar reglas nuevamante***\n");
	printf("\n		***4- Mostrar Historial***\n");
	printf("\n 		***5- Eligio salir del juego***\n");
	printf("\n		~Elige una opcion~ (Ingresa SOLO los numeros)			\n");
	scanf("%d",&op);
	
	 while(op != 1 && op != 2 && op != 3 && op != 4 && op != 5){
    	printf("\n	***Opcion invalida, vuelve a ingresar la opcion***\n");
    	scanf("%d",&op);
	}
	printf("\n		***Elegiste la opcion: %d***\n",op);

	switch(op) {
		case 1:	//Empieza la partida
			printf("\n 		***Jugar***\n");
											
			break;
		
		case 2: //caso para crear una carta y añadirla al final de una lista
			printf("\n 		***Crear carta***\n");
			struct CARTAS nuevaCarta = ingresarNuevaCarta();
   			agregarCartaAlFinal(&listaCartas, nuevaCarta);
			printf("\nLa carta ha sido creada\n");
											
			break;
			
		case 3: 
			printf("\n		***Mostrar reglas y lista de cartas nuevamente***\n");
			mostrarReglas();
			mostrarCartas(listaCartas);
			break;
		case 4: 
			printf("\n		***Mostrar Historial***\n");
			break;
			
		case 5: 
			printf("\n 		***Eligio salir del juego***\n");
			return 0;
			break;
		default:
			printf("\nERROR EN EL SWITCH\n");
			break;
	}
	// Liberar memoria de la lista enlazada
    struct NodoCarta* actual = listaCartas;
    while (actual != NULL) {
        struct NodoCarta* siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }

	return 0;
}
