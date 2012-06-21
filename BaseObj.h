/*
 * BaseObj.h
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
#include<allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
#include "globals.h"
class BaseObj {
private:
	int id;
	bool alive;
	bool collidable;

protected:
	// coordinates
	float x,y;
	// velocities
	float vx,vy;
	// direction (1,0,-1)
	int dx,dy;
	// boundaries (used for collection detection)
	int bx,by;
	// (maxFrame,currentFrame,frameCount,frameDelay,frameWidth,frameHieght)
	int mf,cf,fc,fd,fw,fh;
	// (animationColumnes,animationDeriction);
	int ac,ad;

	ALLEGRO_BITMAP* image;

public:
	BaseObj();
	virtual ~BaseObj();

	void virtual destroy();
	void init(float x, float y, float vx, float vy, int dx, int dy, int bx,int by);
	void virtual update();
	void virtual render();

	int getBx() const {
		return bx;
	}

	void setBx(int bx) {
		BaseObj::bx = bx;
	}

	int getBy() const {
		return by;
	}

	void setBy(int by) {
		BaseObj::by = by;
	}

	bool isAlive() const {
		return alive;
	}

	void setAlive(bool alive) {
		BaseObj::alive = alive;
	}

	int getId() const {
		return id;
	}

	void setId(int id) {
		BaseObj::id = id;
	}

	float getX() const {
		return x;
	}

	void setX(float x) {
		BaseObj::x = x;
	}

	float getY() const {
		return y;
	}

	void setY(float y) {
		BaseObj::y = y;
	}
	int getDx() const {
		return dx;
	}

	void setDx(int dx) {
		BaseObj::dx = dx;
	}
	int getDy() const {
		return dy;
	}

	void setDy(int dy) {
		BaseObj::dy = dy;
	}

	int getVx() const {
		return vx;
	}

	void setVx(int vx) {
		BaseObj::vx = vx;
	}
	int getVy() const {
		return vy;
	}

	void setVy(int vy) {
		BaseObj::vy = vy;
	}
	bool GetCollidable() {return collidable;}
	void SetCollidable(bool collidable) {BaseObj::collidable = collidable;}
	bool isCollidable();
	bool checkCollision(BaseObj* obj);
	void virtual collided(BaseObj* obj);

};
