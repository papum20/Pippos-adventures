#ifndef PLAYER_ROD_HPP
#define PLAYER_ROD_HPP

#include "rod.hpp"
#include "../projectiles/spell.hpp"

const int player_rod_up_index=0;
const int player_rod_down_index=1;
const int player_rod_left_index=2;
const int player_rod_right_index=3;
const int player_rod_attack_up_index=4;
const int player_rod_attack_down_index=5;
const int player_rod_attack_left_index=6;
const int player_rod_attack_right_index=7;


const int player_rod_movement_states=1;
const int player_rod_attack_states=3;

const int player_rod_height=8;
const int player_rod_width=9;

const char player_rod_up[1][ANIMATION_HEIGHT][ANIMATION_WIDTH]={//height=8 width=9

{   {' ',' ', ' ' ,' ', ' ', ' ', ' ', ' ', ' '},
	{' ',' ', ' ' ,' ', ' ', ' ', ' ', ' ', ' '},
	{' ',' ', '*', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ',' ', '|', 'm', ' ', ' ', ' ', ' ', ' '},
    {' ',' ', '|', '-', ' ', ' ', ' ', ' ', ' '},
	{' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ' , ' ',' ',' ',' ', ' ' , ' ', ' '},
	{' ', ' ' , ' ',' ',' ',' ', ' ' , ' ', ' '}
	}
};

const char player_rod_left[1][ANIMATION_HEIGHT][ANIMATION_WIDTH]={//height=8 width=9

{   {' ',' ', ' ' ,' ', ' ', ' ', ' ', ' ', ' '},
	{' ',' ', ' ' ,' ', ' ', ' ', ' ', ' ', ' '},
	{' ',' ', '*', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ',' ', '|', 'm', ' ', ' ', ' ', ' ', ' '},
    {' ',' ', '|', '-', ' ', ' ', ' ', ' ', ' '},
	{' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ' , ' ',' ',' ',' ', ' ' , ' ', ' '},
	{' ', ' ' , ' ',' ',' ',' ', ' ' , ' ', ' '}
	}
};

const char player_rod_right[1][ANIMATION_HEIGHT][ANIMATION_WIDTH]={//height=8 width=9

{   {' ',' ', ' ' ,' ', ' ', ' ', ' ', ' ', ' '},
	{' ',' ', ' ' ,' ', ' ', ' ', ' ', ' ', ' '},
	{' ',' ', ' ', ' ', ' ', ' ', '*', ' ', ' '},
	{' ',' ', ' ', ' ', ' ', 'm', '|', ' ', ' '},
    {' ',' ', ' ', ' ', ' ', '-', '|', ' ', ' '},
	{' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ' , ' ',' ',' ',' ', ' ' , ' ', ' '},
	{' ', ' ' , ' ',' ',' ',' ', ' ' , ' ', ' '}
	}
};

const char player_rod_down[1][ANIMATION_HEIGHT][ANIMATION_WIDTH]={//height=8 width=9

{   {' ',' ', ' ' ,' ', ' ', ' ', ' ', ' ', ' '},
	{' ',' ', ' ' ,' ', ' ', ' ', ' ', ' ', ' '},
	{' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ',' ', ' ', ' ', ' ', 'm', ' ', ' ', ' '},
    {' ',' ', ' ', ' ', ' ', '-', '|', ' ', ' '},
	{' ',' ', ' ', ' ', ' ', ' ', '|', ' ', ' '},
	{' ', ' ' , ' ',' ',' ',' ', '*' , ' ', ' '},
	{' ', ' ' , ' ',' ',' ',' ', ' ' , ' ', ' '}
	}
};


const char player_rod_attack_right[player_rod_attack_states][ANIMATION_HEIGHT][ANIMATION_WIDTH]={

{   {' ',' ',' ',' ', '-' , ' ', '*', ' ', '-'},
	{' ',' ',' ',' ', ' ', ' ', '|', ' ', ' '},
	{' ',' ',' ',' ', ' ', ' ', '|', ' ', ' '},
    {' ',' ',' ',' ',' ', '/', ' ', ' ', ' '},
	{' ',' ',' ',' ', ' ', 'm', ' ', ' ', ' '},
	{' ',' ',' ',' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ' , ' ',' ',' ',' ', ' ' , ' ', ' '},
	{' ', ' ' , ' ',' ',' ',' ', ' ' , ' ', ' '}
	},

{   {' ',' ', ' ' ,' ', ' ', '-', '*', '-', ' '},
	{' ',' ', ' ' ,' ', ' ', ' ', '|', ' ', ' '},
	{' ',' ', ' ', ' ', ' ', ' ', '|', ' ', ' '},
	{' ',' ', ' ', ' ', ' ', '/', ' ', ' ', ' '},
    {' ',' ', ' ', ' ', ' ', 'm', ' ', ' ', ' '},
	{' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ' , ' ',' ',' ',' ', ' ' , ' ', ' '},
	{' ', ' ' , ' ',' ',' ',' ', ' ' , ' ', ' '}
	},

{   {' ',' ',' ',' ', ' ' , ' ', '*', ' ', ' '},
	{' ',' ',' ',' ', ' ', ' ', '|', ' ', ' '},
	{' ',' ',' ',' ', ' ', ' ', '|', ' ', ' '},
    {' ',' ',' ',' ',' ', '/', ' ', ' ', ' '},
	{' ',' ',' ',' ', ' ', 'm', ' ', ' ', ' '},
	{' ',' ',' ',' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ' , ' ',' ',' ',' ', ' ' , ' ', ' '},
	{' ', ' ' , ' ',' ',' ',' ', ' ' , ' ', ' '}
	}
};



const char player_rod_attack_left[player_rod_attack_states][ANIMATION_HEIGHT][ANIMATION_WIDTH]={

{   {'-',' ','*',' ', '-' , ' ', ' ', ' ', ' '},
	{' ',' ','|',' ', ' ', ' ', ' ', ' ', ' '},
	{' ',' ','|',' ', ' ', ' ', ' ', ' ', ' '},
    {' ',' ',' ','\\',' ', ' ', ' ', ' ', ' '},
	{' ',' ',' ','m', ' ', ' ', ' ', ' ', ' '},
	{' ',' ',' ',' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ' , ' ',' ',' ',' ', ' ' , ' ', ' '},
	{' ', ' ' , ' ',' ',' ',' ', ' ' , ' ', ' '}
	},

{   {' ','-', '*' ,'-', ' ', ' ', ' ', ' ', ' '},
	{' ',' ', '|' ,' ', ' ', ' ', ' ', ' ', ' '},
	{' ',' ', '|', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ',' ', ' ', '\\', ' ', ' ', ' ', ' ', ' '},
    {' ',' ', ' ', 'm', ' ', ' ', ' ', ' ', ' '},
	{' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ' , ' ',' ',' ',' ', ' ' , ' ', ' '},
	{' ', ' ' , ' ',' ',' ',' ', ' ' , ' ', ' '}
	},

{   {' ',' ','*',' ', ' ' , ' ', ' ', ' ', ' '},
	{' ',' ','|',' ', ' ', ' ', ' ', ' ', ' '},
	{' ',' ','|',' ', ' ', ' ', ' ', ' ', ' '},
    {' ',' ',' ','\\',' ', ' ', ' ', ' ', ' '},
	{' ',' ',' ','m', ' ', ' ', ' ', ' ', ' '},
	{' ',' ',' ',' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ' , ' ',' ',' ',' ', ' ' , ' ', ' '},
	{' ', ' ' , ' ',' ',' ',' ', ' ' , ' ', ' '}
	}
};

const char player_rod_attack_up[player_rod_attack_states][ANIMATION_HEIGHT][ANIMATION_WIDTH]={

{   {'-',' ','*',' ', '-' , ' ', ' ', ' ', ' '},
	{' ',' ','|',' ', ' ', ' ', ' ', ' ', ' '},
	{' ',' ','|',' ', ' ', ' ', ' ', ' ', ' '},
    {' ',' ',' ','\\',' ', ' ', ' ', ' ', ' '},
	{' ',' ',' ','m', ' ', ' ', ' ', ' ', ' '},
	{' ',' ',' ',' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ' , ' ',' ',' ',' ', ' ' , ' ', ' '},
	{' ', ' ' , ' ',' ',' ',' ', ' ' , ' ', ' '}
	},

{   {' ','-', '*' ,'-', ' ', ' ', ' ', ' ', ' '},
	{' ',' ', '|' ,' ', ' ', ' ', ' ', ' ', ' '},
	{' ',' ', '|', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ',' ', ' ', '\\', ' ', ' ', ' ', ' ', ' '},
    {' ',' ', ' ', 'm', ' ', ' ', ' ', ' ', ' '},
	{' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ' , ' ',' ',' ',' ', ' ' , ' ', ' '},
	{' ', ' ' , ' ',' ',' ',' ', ' ' , ' ', ' '}
	},

{   {' ',' ','*',' ', ' ' , ' ', ' ', ' ', ' '},
	{' ',' ','|',' ', ' ', ' ', ' ', ' ', ' '},
	{' ',' ','|',' ', ' ', ' ', ' ', ' ', ' '},
    {' ',' ',' ','\\',' ', ' ', ' ', ' ', ' '},
	{' ',' ',' ','m', ' ', ' ', ' ', ' ', ' '},
	{' ',' ',' ',' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ' , ' ',' ',' ',' ', ' ' , ' ', ' '},
	{' ', ' ' , ' ',' ',' ',' ', ' ' , ' ', ' '}
	}
};

const char player_rod_attack_down[player_rod_attack_states][ANIMATION_HEIGHT][ANIMATION_WIDTH]={

{   {' ',' ',' ',' ', ' ' , ' ', ' ', ' ', ' '},
	{' ',' ',' ',' ', ' ', ' ', ' ', ' ', ' '},
	{' ',' ',' ',' ', ' ', ' ', ' ', ' ', ' '},
    {' ',' ',' ',' ',' ', 'm', ' ', ' ', ' '},
	{' ',' ',' ',' ', ' ', '\\', ' ', ' ', ' '},
	{' ',' ',' ',' ', ' ', ' ', '|', ' ', ' '},
	{' ', ' ' , ' ',' ',' ',' ', '|' , ' ', ' '},
	{' ', ' ' , ' ',' ','-',' ', '*' , ' ', '-'}
	},

{   {' ',' ',' ',' ', ' ' , ' ', ' ', ' ', ' '},
	{' ',' ',' ',' ', ' ', ' ', ' ', ' ', ' '},
	{' ',' ',' ',' ', ' ', ' ', ' ', ' ', ' '},
    {' ',' ',' ',' ',' ', 'm', ' ', ' ', ' '},
	{' ',' ',' ',' ', ' ', '\\', ' ', ' ', ' '},
	{' ',' ',' ',' ', ' ', ' ', '|', ' ', ' '},
	{' ', ' ' , ' ',' ',' ',' ', '|' , ' ', ' '},
	{' ', ' ' , ' ',' ',' ','-', '*' , '-', ' '}
	},

{   {' ',' ',' ',' ', ' ' , ' ', ' ', ' ', ' '},
	{' ',' ',' ',' ', ' ', ' ', ' ', ' ', ' '},
	{' ',' ',' ',' ', ' ', ' ', ' ', ' ', ' '},
    {' ',' ',' ',' ',' ', 'm', ' ', ' ', ' '},
	{' ',' ',' ',' ', ' ', '\\', ' ', ' ', ' '},
	{' ',' ',' ',' ', ' ', ' ', '|', ' ', ' '},
	{' ', ' ' , ' ',' ',' ',' ', '|' , ' ', ' '},
	{' ', ' ' , ' ',' ',' ',' ', '*' , ' ', ' '}
	}
};


class Player_Rod: public Rod{
    public:
		//Spell magia;
		Player_Rod();
		
		void shoot();
};

typedef Player_Rod* pPlayer_rod;



#endif