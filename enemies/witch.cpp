#include "witch.hpp"

Witch::Witch():Enemy(){
    idle_index=witch_idle_index;
    move_up_index=witch_move_up_index;
    move_down_index=witch_move_down_index;
    move_right_index=witch_move_right_index;
    move_left_index=witch_move_left_index;

    animations[idle_index]=new Animation (witch_idle, ENEMY_ANIMATION_WIDTH, ENEMY_ANIMATION_HEIGHT, witch_idle_states);
    animations[move_up_index]=new Animation (witch_move_up, ENEMY_ANIMATION_WIDTH, ENEMY_ANIMATION_HEIGHT, witch_move_up_states);
    animations[move_left_index]=new Animation (witch_move_left, ENEMY_ANIMATION_WIDTH, ENEMY_ANIMATION_HEIGHT, witch_move_left_states);
    animations[move_right_index]=new Animation (witch_move_right, ENEMY_ANIMATION_WIDTH, ENEMY_ANIMATION_HEIGHT, witch_move_right_states);
    animations[move_down_index]=new Animation (witch_move_down, ENEMY_ANIMATION_WIDTH, ENEMY_ANIMATION_HEIGHT, witch_move_down_states);
}