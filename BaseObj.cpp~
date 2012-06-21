/*
 * BaseObj.cpp
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

#include "BaseObj.h"

BaseObj::BaseObj() {
	x=0;
	y=0;

	vx=0;
	vy=0;

	dx=0;
	dy=0;

	bx=0;
	by=0;

	mf=0;
	cf=0;
	fc=0;
	fd=0;
	fw=0;
	fh=0;

	image = NULL;
}

void BaseObj::init(float x, float y, float vx, float vy, int dx, int dy, int bx, int by){
		BaseObj::x = x;
		BaseObj::y = y;

		BaseObj::vx = vx;
		BaseObj::vy = vy;

		BaseObj::dx = dx;
		BaseObj::dy = dy;

		BaseObj::bx = bx;
		BaseObj::by = by;
}

void BaseObj::update(){
	x += vx*dx;
	y += vy*dy;
}

void BaseObj::render(){

}

bool BaseObj::checkCollision(BaseObj* obj){
	float ox = obj->getX();
	float oy = obj->getY();
	float obx = obj->getBx();
	float oby = obj->getBy();
	bool r =false;
	if(x + bx > ox &&
			x  < ox + obx &&
			y + by > oy &&
			y  < oy + oby)
		r = true;
	return r;
}

void BaseObj::collided(BaseObj* obj){

}

bool BaseObj::isCollidable(){
	return alive && collidable;
}

void BaseObj::destroy(){

}

BaseObj::~BaseObj() {
	
}

