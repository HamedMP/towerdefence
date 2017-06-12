/*
 * Copyright (C) 2017 Hamed MP
 * Copyright (C) 2017 Marcos Bernal
 * Copyright (C) 2014 Luca Sciullo
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#pragma once
#include <vector>
#include <cstring>
#include <stdio.h>
#include "Config.h"
#include "GraphicPrimitives.h"
#include "Wave.h"

using namespace std;

class Game {

    private:
        void get_difficulty_char(char* label);

	public:
		Game():
			window_width(WINDOW_WIDTH),
			window_height(WINDOW_HEIGHT),
			wave(NULL),
			level(START_LEVEL),
			score(START_SCORE),
			ship_type(SNOW_SHIP),
			n_ships(0),
			n_asteroids(0),
			n_shots(0),
            difficulty(1),
            number_of_lines(1),
            main_menu(true),
			pause(false),
            game_over(false),
            difficulty_label(new char[64]),
            number_of_lines_label(new char[32]),
            str_score(new char[20]),
            str_n_ships(new char[20]),
            str_n_asteroids(new char[20]),
            str_help(new char[20]) {}

		int window_width;
		int window_height;
		Wave *wave; //pointer to wave object
		int level;	//actual level played
		int score;	//actual score
		int ship_type; //default type for spaceships
		int n_ships;	//counter for the number of ships
		int n_asteroids;  //counter for the number of asteroids
		int n_shots;	//counter for the number of shots
        int difficulty; //Level of difficulty 1 easy - 5 very hard
        int number_of_lines; //Number of lines to defend
        bool main_menu; //flag for the main menu
        bool pause;		//flag for pause
		bool game_over;	//flag for game_over

        char *difficulty_label;
        char *number_of_lines_label;

		char *str_score;
		char *str_n_ships;
		char *str_n_asteroids;
		char *str_help;

        void main_menu_draw();
        void set_num_lines(int lines);
        void change_difficulty(int change);
        void draw();
        void pause_draw();
		void update_score(int s);
		void update_n_ships(int s);
		void update_n_asteroids(int a);
		void update_n_shots(int s);
		bool check_enough_score(int type);
		void level_completed();
        void game_over_draw();
		void reset();
};
