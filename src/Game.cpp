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

#include <stdio.h>
#include <string>
#include <cstring>
#include <sstream>
#include "Game.h"
#include "Config.h"

using namespace std;
int N_LINES = 1;

void Game::get_difficulty_char(char* label){
    switch(this->difficulty){
    case(TOO_EASY_DIF):  sprintf(label, "%s", "Very EASY"); break;
    case(EASY_DIF):      sprintf(label, "%s", "EASY"); break;
    case(MEDIUM_DIF):    sprintf(label, "%s", "Medium"); break;
    case(HARD_DIF):      sprintf(label, "%s", "Hard"); break;
    case(VERY_HARD_DIF): sprintf(label, "%s", "Very Hard ?"); break;
    }
}

void Game::main_menu_draw() {
    char * tmp_str = new char[16];
    char str[] = "Tower Defence";
    char str1[] = "Press 'space bar' to start...";
    get_difficulty_char(tmp_str);
    sprintf(difficulty_label, "%s%s%s", "Difficulty: ", tmp_str, " use 'q' for increase and 'e' for decrease");
    sprintf(number_of_lines_label, "%s%d%s", "Lines to defend: '", number_of_lines, "' change them with num keys");
    GraphicPrimitives::drawText2D(str, -0.25, 0.6, 1, 0, 0);
    GraphicPrimitives::drawText2D(str1, -0.32, 0.3, 1, 1, 0);
    GraphicPrimitives::drawText2D(difficulty_label, -0.32, 0.1, 1, 1, 0);
    GraphicPrimitives::drawText2D(number_of_lines_label, -0.32, -0.1, 1, 1, 0);
}

void Game::set_num_lines(int lines){
    this->number_of_lines = lines;
    N_LINES = lines;
}

void Game::change_difficulty(int change){
    if(change == EASIER)
        this->difficulty = this->difficulty == TOO_EASY_DIF ? TOO_EASY_DIF : this->difficulty-1;
    else
        this->difficulty = this->difficulty == VERY_HARD_DIF ? VERY_HARD_DIF : this->difficulty+1;
}

void Game::draw(){

	sprintf(str_score, "%s%d", "Score: ", score);
	sprintf(str_n_ships, "%s%d", "Ships: ", n_ships);
	sprintf(str_n_asteroids, "%s%d", "Asteroids left: ", n_asteroids);
	sprintf(str_help, "%s", "Press 'h' or 'p' to see the help page");

	GraphicPrimitives::drawText2D(str_score, -1, -1, 1, 1, 0);
	GraphicPrimitives::drawText2D(str_n_ships, -0.7, -1, 1, 1, 0);
	GraphicPrimitives::drawText2D(str_n_asteroids, -0.4, -1, 1, 1, 0);
	GraphicPrimitives::drawText2D(str_help, -0.1, -1, 1, 1, 0);
}

void Game::pause_draw() {
	char str[] = "PAUSE";
	char str1[] = "Press 'p' to continue ...";
	char str2[] = "h: Show this page";
	char str3[] = "a: Launch a new wave of asteroids";
	char str4[] = "q: Select spaceship SNOW";
	char str5[] = "w: Select spaceship GRASS";
	char str6[] = "e: Select spaceship BLOOD";
	char str7[] = "Mouse Left-button: put a spaceship inside a cell";
	GraphicPrimitives::drawText2D(str, -0.13, 0.8, 1, 1, 1);
	GraphicPrimitives::drawText2D(str1, -0.22, 0.6, 1, 1, 1);
	GraphicPrimitives::drawText2D(str2, -0.92, 0.2, 1, 1, 1);
	GraphicPrimitives::drawText2D(str3, -0.92, -0.0, 1, 1, 1);
	GraphicPrimitives::drawText2D(str4, -0.92, -0.2, 1, 1, 1);
	GraphicPrimitives::drawText2D(str5, -0.92, -0.4, 1, 1, 1);
	GraphicPrimitives::drawText2D(str6, -0.92, -0.6, 1, 1, 1);
	GraphicPrimitives::drawText2D(str7, -0.92, -0.8, 1, 1, 1);
}


void Game::update_score(int s) {
	score += s;
}

void Game::update_n_ships(int s) {
	n_ships = s;
}

void Game::update_n_asteroids(int s) {
	n_asteroids = s;
}

void Game::update_n_shots(int s) {
	n_shots = s;
}

bool Game::check_enough_score(int type) {
	bool tmp = false;
	int diff;
	switch(type) {
		case SNOW_SHIP:
			diff = SNOW_SHIP_COST;
			break;
		case GRASS_SHIP:
			diff = GRASS_SHIP_COST;
			break;
		case BLOOD_SHIP:
			diff = BLOOD_SHIP_COST;
			break;
		default:
			diff = 0;
			break;
	}
	if((score - diff) >= 0) {
		score -= diff;
		tmp = true;
	}
	return tmp;

}
void Game::level_completed() {
	level++;
	delete wave;
	wave = NULL;
	printf("Level completed\n");
}

void Game::game_over_draw() {
	char str[] = "GAME OVER";
	char str1[] = "Press 'r' to restart...";
	GraphicPrimitives::drawText2D(str, -0.10, 0.8, 1, 1, 1);
	GraphicPrimitives::drawText2D(str1, -0.13, 0.6, 1, 1, 1);
}

void Game::reset() {
	game_over = false;
	score = START_SCORE;
	level = START_LEVEL;
	ship_type = SNOW_SHIP;
	n_ships = 0;
	n_asteroids = 0;
	n_shots= 0;
}

