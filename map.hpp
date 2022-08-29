//// //// MAPPA DI CASELLE CONTENENTI INFORMAZIONI, OGGETTI...

#ifndef MAP_HPP
#define MAP_HPP


#include "character.hpp"
#include "chest.hpp"
#include "definitions.hpp"
#include "door.hpp"
#include "floor.hpp"
#include "structures/queue_coordinate.hpp"
#include "wall.hpp"



class Map {
	private:
		Coordinate size;
		int scale_x;
		int n_doors_max;						//massimo numero porte (dimensione array)
		int n_doors_sides;						//numero di lati occupati da una porta (attualmente)
		Coordinate door_positions[MAX_SIDES_R];

		pPhysical physical[ROOM_AREA];
		pCharacter characters[ROOM_AREA];
		pDoor doors[MAX_CONNECTED_R];			//array di puntatori a porte (verso stanze collegate)
												//disposte in direzioni: 0=su, 1=destra, 2=giu, 3=sinistra, 4=segreta,all'interno
		pChest chests[ROOM_AREA];

		pInanimate floorInstance;
		pInanimate wallInstance;

		// FUNZIONI AUSILIARIE
		Coordinate getDoorEntrance(Coordinate doorCenter);						//ritorna door.entrancePosition, il punto in cui si ritrova un character che attraversa la porta
		bool inArray_physical(pPhysical A[ROOM_AREA], int len, pPhysical obj);	//se obj si trova in A
		// FUNZIONI AUSILIARIE PRINCIPALI (GENERAZIONE)
		void generateSidesWalls();
		void generateInnerRoom();
		void generateAllPaths(pUnionFind sets);
		void connectPaths(pUnionFind sets);		//fa in modo che ogni punto sia raggiungibile da ogni altro
		void resizeMap();						//ridimensiona la mappa, allargando quella temporanea generata di X_SCALE
		void generateDoors(pUnionFind sets);					//genera le porte (generazione stanza)
		// FUNZIONI AUSILIARIE SECONDARIE (GENERAZIONE)
		void generatePath(Coordinate s, pUnionFind sets);			//genera un percorso casuale a partire da x,y
		int getAdjacentWalls(Coordinate out[], s_coord currentSet);	//riempie out con i muri adiacenti a una casella del set e ne ritorna il numero
		int getBorderWalls(Coordinate border[], int directions[], Coordinate walls[], int walls_n, UnionFind sets, s_coord parent, int distance);
					//riempie border con i muri di confine tra il set di parent e un altro (con spessore distance)
					//e directions con le rispettive direzioni, ne ritorna il numero
	

	public:
		Map(int scale_x, pInanimate floorInstance, pInanimate wallInstance);
		void destroy();
		void update_all(char input);
		void generate(); 													//genera uno schema randomico per i muri, inserendoli nella map
		void generate_with_doors();
		int shortestPath(Coordinate path[ROOM_AREA], Coordinate A, Coordinate B, int max_dist = -1, pPhysical obj[ROOM_AREA] = {}, int obj_n = 0);
		//ritorna il percorso più breve da A a B, modificando path con i passi da seguire e ritornandone la lunghezza (B incluso, A escluso); ritorna -1 se impossibile;
		//se si vuole il percorso per un oggetto physical, o che passi per un oggetto, usare il campo obj (altrimenti non serve): permette di calcolare anche il percorso che passi attraverso essi; obj_n sono le dimensioni di obj;
		//il parametro max_dist, se usato, permette di trovare solo percorsi non lunghi più di max_dist (se max_dist<0 si considera lunghezza infinita)
		int shortestPath_physical(Coordinate path[ROOM_AREA], pPhysical A, pPhysical B, int dist = 1, pPhysical obj[ROOM_AREA] = {}, int obj_n = 0);
		//shortestPath per far arrivare un oggetto A a distanza dist da un oggetto B (minimo 1); usare obj per gli oggetti attraverso cui si può passare

		// CHECK
		pPhysical checkPosition(Coordinate pos);				//ritorna un puntatore all'oggetto fisico presente nella casella x,y (NULL se non presente niente)
		pCharacter checkCharacter(Coordinate pos);				//ritorna l'oggetto (puntatore) character
		pChest checkChest(Coordinate pos);						//ritorna l'oggetto (puntatore) chest
		pDoor checkDoor(Coordinate pos);						//ritorna l'oggetto (puntatore) door
		pPhysical checkLine(Coordinate start, Coordinate end);	//checkPosition per una linea da start a end (incluso)
		pCharacter checkLineCharacter(Coordinate start, Coordinate end);

		// BOOL
		bool isFreeSpace(Coordinate start, Coordinate end);		//ritona true se il rettangolo è vuoto
		bool isLegalMove(pPhysical obj, Coordinate target);		//ritorna true se obj può occupare, con le sue dimensioni, la cella target

		// GET
		Coordinate getSize();
		int get_n_doors_max();
		pDoor getDoorInIndex(int ind);
		pDoor getDoorInPosition(Coordinate pos);				//door (puntatore) in una posizione

		// EDIT
		void addDoor(int dir, lock_type lt);
		void addCharacter(pCharacter obj);						//aggiunge un character nella sua posizione
		bool move(pPhysical obj, Coordinate target);			//muove un oggetto qualsiasi (non inanimate); ritorna true se ha successo
		void remove(pPhysical obj);								//rimuove un oggetto qualsiasi (non inanimate)
};

typedef Map *pMap;


#endif