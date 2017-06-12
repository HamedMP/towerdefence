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

#include <thread>
#include <chrono>
#include "Engine.h"
#include "Spaceship.h"
#include "BLine.h"
#include "Observer.h"
#include "Asteroid.h"
#include "Game.h"

class MyGameEngine:public GameEngine {
	Game *game;
	std::vector<Spaceship* > *ships;
	std::vector<BLine *> *Blines;
	std::vector<Asteroid*> *Asteroids;
	Observer *observer;
    int engine_speed; //Percentage, by default 30%, the higher the value the more resources consumes and faster becomes ~= to fps
	public:

    MyGameEngine(Game *game_, std::vector<Spaceship* > *ships_, std::vector<BLine * > *Blines_, Observer *observer_, int engine_speed_ = 30):
		game(game_),
		ships(ships_),
		Blines(Blines_),
        observer(observer_),
        Asteroids(),
        engine_speed(engine_speed_){}

    //Copy constructor & operator= overload
    MyGameEngine(const MyGameEngine &obj);
    MyGameEngine& operator=(const MyGameEngine &obj);

	virtual void idle();
    virtual ~MyGameEngine();

};
