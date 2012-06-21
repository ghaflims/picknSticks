/*
 * Player.cpp
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

#include "Player.h"

Player::Player() {
	BaseObj();
}

Player::~Player() {

}

void Player::init(ALLEGRO_BITMAP* img){

	BaseObj::init(50,300,2,2,1,1,32,48);
	setAlive(true);
	setId(PLAYER);
	score = 0;
	mf=4;
	cf=0;
	fw=32;
	fh=48;
	ac=4;
	ad=1;
	ar=0;
	fd=4;
	if(img!=NULL)
		image = img;

}

void Player::update(){
	BaseObj::update();
	if(x<0)
		x=0;
	else if(x>WIDTH-fw)
		x=WIDTH-fw;

	if(y<0)
		y=0;
	else if(y>HEIGHT-fh)
		y=HEIGHT-fh;

	if(fc++>fd)
		fc=0;

}

void Player::render(){
	int fx = (cf%ac)*fw;
	int fy = ar*fh;
	al_draw_bitmap_region(image,fx,fy,fw,fh,x,y,0);
}

void Player::moveUp(){
	dy=-1;
	dx=0;
	ar=1;
	if(fc==fd){
		cf+=ad;
		if(cf>2){
			ad=-1;
			cf=1;
		}
		else if(cf<0){
			ad=1;
			cf=1;
		}
	}

}

void Player::moveDown(){
	dy=1;
	dx=0;
	ar=0;
	if(fc==fd){
		cf+=ad;
		if(cf>2){
			ad=-1;
			cf=1;
		}
		else if(cf<0){
			ad=1;
			cf=1;
		}
	}

}

void Player::moveLeft(){
	ar=2;
	dx=-1;
	dy=0;
	if(fc==fd){
		cf+=ad;
		if(cf>2){
			ad=-1;
			cf=1;
		}
		else if(cf<0){
			ad=1;
			cf=1;
		}
	}
}

void Player::moveRight(){
	ar=3;
	dx=1;
	dy=0;
	if(fc==fd){
		cf+=ad;
		if(cf>2){
			ad=-1;
			cf=1;
		}
		else if(cf<0){
			ad=1;
			cf=1;
		}
	}
}

void Player::restAnimation(int pos){
	if(pos==1){
		dy=0;
	}
	else{
		dx=0;
	}

}

void Player::collided(BaseObj* obj){}
void Player::destroy(){}
