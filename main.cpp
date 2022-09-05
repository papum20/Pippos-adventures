#include "main.hpp"
using namespace std;



int main() {

	bool isRunning = true;
	//bool isPaused = false;
	Timer refresh_timer = Timer();
	refresh_timer.set_max(REFRESH_TIMER_INDEX, REFRESH_RATE);

	//// START: ESEGUITO UNA VOLTA ALL'AVVIO
	cursesInit();
	gameInit();
	
	//FINESTRE
	//calcolo per posizionare la finestra di gioco al centro
	int stdscr_x, stdscr_y;
	getmaxyx(stdscr, stdscr_y, stdscr_x);
	int level_x = (stdscr_x - CAMERA_WIDTH) / 2, level_y = (stdscr_y - CAMERA_HEIGHT) / 2;
	//finestra di input (in basso a destra, sotto level)
	int input_x = level_x + CAMERA_WIDTH - input_l, input_y = level_y + CAMERA_HEIGHT;
	//finestra hud (in alto)
	int hud_x = level_x, hud_y = level_y - HUD_HEIGHT;

	//costruttori
	pInputManager inputManager = new InputManager(input_x, input_y);
	pPlayer player = new Player(inputManager);
	Level level = Level(level_x, level_y, player);
	Menu menu = Menu(inputManager);
	//Hud hud = Hud(hud_x, hud_y, player);


	WINDOW *debug = newwin(10,10,0,0);
	box(debug,0,0);
	wrefresh(debug);
	//// UPDATE: ESEGUITO A OGNI FRAME
	while(isRunning)
	{
		// GESTIONE TEMPO FRAME : si eseguono tutte le operazioni, poi nel prossimo update il tempo rimasto nel tempo di aggiornamento (refresh_rate)
		// il gioco rimane "inattivo", continuando solo a ricevere l'input (comunque almeno una volta)
		while(!refresh_timer.check(REFRESH_TIMER_INDEX));
		inputManager->calculate_input();
		refresh_timer.start(REFRESH_TIMER_INDEX);

		//// IN PAUSA
		if (menu.is_active()) {
			mvwprintw(debug,5,1,"menu");
			//if(inputManager->get_input() == KEY_PAUSE) menu.close_menu();
		//	menu.update();			//se il menu è aperto il player non si muove
		}
		//// IN GIOCO
		else {
			mvwprintw(debug,5,1,"level");
			//if(inputManager->get_input() == KEY_PAUSE) menu.open();
		//	level.update(inputManager->get_input());
		//	level.display();
		//	hud.drawHud();
		}
		wrefresh(debug);
	}


	//// END
	cursesEnd();
	gameEnd();
	
}





#pragma region FUNZIONI
void cursesInit() {
	initscr();			//inizializza schermo ncurses
	start_color();		//inizializza colori
}
void gameInit() {
	srand(time(NULL));
	colorsInit();
}
void colorsInit() {
	Cell::initPairs();
	init_color(COLOR_BROWN, 668, 273, 164);
	init_color(COLOR_BROWN_LIGHT, 906, 371, 367);
	init_color(COLOR_GREY, 156, 129, 137);
	init_color(COLOR_BLUE, 156, 86, 898);
}

void cursesEnd() {
	endwin();			//dealloca memoria
}
void gameEnd() {
	delete FLOOR_INSTANCE;
	delete WALL_INSTANCE;
}
#pragma endregion FUNZIONI
