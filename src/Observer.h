/*
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
#include "Shot.h"
#include "Spaceship.h"
#include "BLine.h"
#include "Asteroid.h"
#include "Game.h"

#define X_FIRING ((shot->pos.x + shot->width) > ast->pos.x - ast->width/2) && (shot->pos.x < ast->pos.x + ast->width/2)
#define Y_FIRING ((shot->pos.y + shot->height) > ast->pos.y - ast->height/2) && (shot->pos.y < ast->pos.y + ast->height/2)
#define SHOT_DEAD shot->died

#define X_COLLISION (ast->pos.x - ast->width/2) < (ship->pos.x + ship->width/2) && (ast->pos.x + ast->width/2) > (ship->pos.x - ship->width/2)
#define Y_COLLISION (ast->pos.y - ast->height/2) < (ship->pos.y + ship->height/2) && (ast->pos.y + ast->height/2) > (ship->pos.y - ship->height/2)
#define SHIP_DEAD ship->died

class Observer {
		Game *game;
		std::vector<Spaceship * > *ships;
		std::vector<BLine *> *Blines;

	public:
		Observer(Game *game_, std::vector<Spaceship * > * ships_, std::vector<BLine * > * Blines_):
			game(game_),
			ships(ships_),
			Blines(Blines_){}

		
		void manage_deaths();
		void detect_problems();
		void check_firing(int line, std::vector<Shot *> *shots);
		void check_collision(Spaceship *ship);
		void check_level_finished();

};
