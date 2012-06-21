/*
 * Player.h
 *
 *  Created on: May 29, 2012
 *  Author: Mustafa S.
 *  Copyright (C) 2012 Mustafa S. (ghaflims@gmail.com)
 *  Acknowledgment:
 *  1. Allegro5 team (http://www.allegro.cc) for the amazing library
 *  2. Mike Geig (http://fixbyproximity.com) Twitter: @mikegeig Email: mikegeig(at)gmail.com
 *  for the amazing 2D game tutorial. Almost all the concepts of his work is implemented in here Thanks man.
 *  please check his website for the video tutorials.
 *  3. Rachel J. Morris (Moosader) (http://www.moosader.com/) for the suggesting the PicknSticks
 *  and the openArt website "the spites are taken from there. thanks for the one who made them"
 *  -------------------------
 *	This software is provided 'as-is', without any express or implied warranty.
 *	In no event will the authors be held liable for any damages arising from the use of this software.
 *	Permission is granted to anyone to use this software for any purpose,
 *	including commercial applications, and to alter it and redistribute it freely,
 *	subject to the following restrictions:
 *
 *	1. The origin of this software must not be misrepresented;
 *	you must not claim that you wrote the original software.
 *	If you use this software in a product, an acknowledgment
 *	in the product documentation would be appreciated but is not required.
 *
 *	2. Altered source versions must be plainly marked as such,
 *	and must not be misrepresented as being the original software.
 *
 *	3. This notice may not be removed or altered from any source distribution.
 *
 */


#pragma once
#include "BaseObj.h"

class Player : public BaseObj {
private:
	// animation Row
	int ar;
	int score;
public:
	Player();
	virtual ~Player();
	void destroy();

	void init(ALLEGRO_BITMAP* image=NULL);
	void update();
	void render();

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	void restAnimation(int);

	int getScore()const{return score;};

	void addPoint(){score++;};
	void collided(BaseObj* obj);

};

