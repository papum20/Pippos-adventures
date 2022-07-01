#ifndef ROOM_HPP
#define ROOM_HPP

#include "coordinate.hpp"


#define X_SCALE 9									//coefficiente di "allargamento orizzontale" della stanza

#define ROOM_WIDTH_T 30								//larghezza (senza scala) stanza
#define ROOM_WIDTH (ROOM_WIDTH_T * X_SCALE)//320	//larghezza (reale) stanza
#define ROOM_HEIGHT 40//180							//altezza stanza
#define ROOM_AREA_T (ROOM_WIDTH_T * ROOM_HEIGHT)
#define CENTRAL_ROOM_SIZE 8							//dimensioni dello spazio vuoto quadrato al centro


//direzioni (vettori unitari) (utili per la generazione di stanze e livelli)
#define DIR_SIZE 4
//define DIR_COORD 2
const Coordinate DIRECTIONS[DIR_SIZE] = {{0,-1},{1,0},{0,1},{-1,0}};
//per ogni indice i, DIR_CHANCES[i] è la probabilità di generare i percorsi a partire da un punto (nella generazione della stanza);
//la prima posizione indica la probabilità di generare in 0 nuove direzioni (cioè di fermarsi)
const int DIR_CHANCES[DIR_SIZE + 1] = {5, 20, 10, 3, 1};


#include "floor.hpp"
#include "main.hpp"
#include "physical.hpp"
#include "union_find.hpp"
#include "wall.hpp"



class Room {
	private:
		int x, y;									//coordinate rispetto alla prima stanza del livello
		//istanze di muro e pavimento, riutilizzate sempre uguali
		pPhysical floorInstance;
		pPhysical wallInstance;

		// FUNZIONI
		void generate(); 										//genera uno schema randomico per i muri, inserendoli nell'array grid
		// FUNZIONI AUSILIARIE SECONDARIE (USATE DALLE PRINCIPALI)
		void generatePath(Coordinate s, pUnionFind sets);		//genera un percorso casuale a partire da x,y
		int getAdjacentWalls(Coordinate out[], s_coord currentSet);	//riempie out con i muri adiacenti a una casella del set e ne ritorna il numero
		int getBorderWalls(Coordinate border[], int directions[], Coordinate walls[], int walls_n, UnionFind sets, s_coord parent, int distance);
					//riempie border con i muri di confine tra il set di parent e un altro (con spessore distance)
					//e directions con le rispettive direzioni, ne ritorna il numero

	protected:
		int width;
		int height;	
		pPhysical grid[ROOM_HEIGHT][ROOM_WIDTH];	//array bidimensionale di oggetti fisici (presenti nelle loro posizioni)
		// FUNZIONI AUSILIARIE PRINCIPALI
		void generateSidesWalls();
		void generateInnerRoom();
		void generateAllPaths(pUnionFind sets);
		void connectPaths(pUnionFind sets);						//fa in modo che ogni punto sia raggiungibile da ogni altro
		void resizeMap();										//ridimensiona la mappa, allargando quella temporanea generata di X_SCALE

	public:
		Room(int x, int y);
		// GENERAZIONE
//		void addNthDoor(int n);	//aggiunge una porta nell'n-esima posizione disponibile
		// CONTROLLO
		pPhysical checkPosition(Coordinate pos);		//ritorna un puntatore all'oggetto fisico presente nella casella x,y (NULL se non presente niente)
		// DISEGNO
		void draw(Cell scr[CAMERA_HEIGHT][CAMERA_WIDTH], Coordinate win_size, Coordinate center);	//riempie l'array con le informazioni per stampare a schermo, con opportune modifiche di prospettiva e altro;
																									//inquadra solo un rettangolo con le dimensioni dei parametri intorno al giocatore

		// SET
		// GET
		int getX();
		int getY();
};



typedef Room *pRoom;




#endif