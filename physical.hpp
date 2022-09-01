#ifndef PHYSICAL_HPP
#define PHYSICAL_HPP


#include <iostream>
#include "animation.hpp"

#define ctrl(x) (x & 0x1F)				//permette di fare i controlli per le combinazioni ctrl+tasto per fare combo e simili.  
										//Es. if ( input==ctrl(a) ) permette di controllare se abbiamo premuto ctrl+a


#pragma region PHYSICAL_CONSTANTS

const int MAX_ANIMATIONS = 6;
// NUMERI
#define N_ENEMIES 6

#define N_CHEST_TYPES 3
#define N_ITEM_DIFENSIVO 4
#define N_ARTIFACTS 4
#define N_WEAPONS 5
#define N_ITEMS (N_ITEM_DIFENSIVO + N_ARTIFACTS + N_WEAPONS)

// ID
#pragma region PHYSICAL_IDS
#define ID_INANIMATE_S 10
#define ID_INANIMATE_E 19
#define ID_ENEMY_S 100
#define ID_ENEMY_E 149
#define ID_ITEM_S 150
#define ID_ITEM_E 179
#define ID_PROJECTILE_S 180
#define ID_PROJECTILE_E 199

#define ID_DEFAULT 0
#define ID_PLACEHOLDER 1
#define ID_PLAYER 2
#define ID_CHEST 3
#define ID_WALL 10
#define ID_FLOOR 11
#define ID_DOOR 20
#define ID_ARTEFACT 30
#pragma endregion PHYSICAL_IDS

//// COSTANTI PER LA RAPPRESENTAZIONE GRAFICA
#pragma region GRAPHICS
// COLORI
#define COLOR_WALL COLOR_RED
#define COLOR_TRANSPARENT COLOR_YELLOW	//per il muro quando diventa più chiaro se c'è qualcosa dietro
#define COLOR_UPPER_WALL COLOR_BLACK	//bordo superiore muro
#define COLOR_FLOOR COLOR_GREEN
#define COLOR_SHADOW COLOR_CYAN			//per il pavimento con l'ombra di un oggetto
// CARATTERI
#define CHAR_EMPTY ' '

#pragma endregion GRAPHICS

#pragma region PHYSICAL_STATS
#define PHYSICAL_MAX_SPEED 5.
#pragma endregion PHYSICAL_STATS

#pragma endregion PHYSICAL_CONSTANTS


#include "cell.hpp"
#include "coordinate.hpp"
#include "definitions.hpp"
#include "map.hpp"



class Physical {
	protected:
		Coordinate pos;
		Coordinate size;
		int id;		//intero che identifica il tipo di oggetto (comune a tutti e soli gli oggetti della stessa classe)

		p_Animation animations[MAX_ANIMATIONS]; //array di liste di array bidimensionali

		int move_up_index;
		int move_down_index;
		int move_left_index;
		int move_right_index;
	public:
		int current_animation;
		Physical();
		virtual void copy(Physical B);			//copia i parametri di B
		virtual void update(pMap map, char input);
		virtual void destroy();

		void drawAtPosition(Cell scr[CAMERA_HEIGHT][CAMERA_WIDTH], Coordinate win_start, Coordinate pos);	//disegna l'oggetto nella finestra, alle date coordinate, secondo la sua animazione, entro i limiti della finestra
		void drawAtOwnPosition(Cell scr[CAMERA_HEIGHT][CAMERA_WIDTH], Coordinate win_start);				//disegna l'oggetto nella finestra, nella sua posizione, secondo la sua animazione, entro i limiti della finestra

		// BOOL
		bool isInanimate();
		bool isCharacter();
		bool isProjectile();
		//bool isItem();			//se è item/artefatto...
		bool findInArray(Physical *A[ROOM_AREA], int len);

		// GET
		int getId();
		Coordinate getPosition();
		Coordinate getSize();
		Coordinate getSpeed();				//velocità in caselle/secondo (float)
		Coordinate lastFrameMovement();
		void conflicts();
		void next_animation();
		// SET
		void setPosition(Coordinate pos);
};

typedef Physical *pPhysical;




#endif