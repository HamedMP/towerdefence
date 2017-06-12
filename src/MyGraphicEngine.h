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
#include <time.h>	// class needs this inclusion
#include "Engine.h"
#include "GraphicPrimitives.h"
#include "Spaceship.h"
#include "BLine.h"
#include "Asteroid.h"
#include "Game.h"

class MyGraphicEngine:public GraphicEngine {

	Game *game;
	std::vector<Spaceship* > *ships;
	std::vector<BLine* > *Blines;

    //char * str;
	public:

	MyGraphicEngine(Game *game_, std::vector<Spaceship* > * ships_, std::vector<BLine* > * Blines_):
		game(game_),
		ships(ships_),
		Blines(Blines_)
		{}


    virtual void Draw();
	virtual void reshape(int width, int height);

    //Copy constructor & operator= overload
    MyGraphicEngine(const MyGraphicEngine &obj);
    MyGraphicEngine& operator=(const MyGraphicEngine &obj);

    virtual ~MyGraphicEngine();

};
