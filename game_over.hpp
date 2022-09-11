#ifndef GAME_OVER_HPP
#define GAME_OVER_HPP



#include <curses.h>
#include <iostream>
#include "definitions.hpp"
#include "pixel_art.hpp"
#include "overlay.hpp"
#include "player.hpp"

#define WINDOW_G_O_HEIGHT 7
#define WINDOW_G_O_WIDTH 55



class Game_over:public Overlay, Pixel_art {
	protected:
    int w_x_pos, w_y_pos;
	bool is_game_over;
	pPlayer player;
	public:
		Game_over(int stdscr_x, int stdscr_y, pPlayer player);
        bool isGameOver();
		void update();
        void open();
};



#endif
