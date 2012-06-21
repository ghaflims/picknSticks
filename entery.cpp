/*
 * entery.cpp
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
#include<cstdlib>
#include<ctime>
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>
#include<allegro5/allegro_primitives.h>
#include "Player.h"
#include "Stick.h"
#include "globals.h"

// Globals
bool keys[] = {false,false,false,false,false};
enum KEYS{UP,DOWN,LEFT,RIGHT,SPACE};
/*PROTOTYPES*/


int main(){
	/*VARIABLES*/
		/*shell variables*/
	bool done=false;
	bool render=false;

		/*project variables*/
	Player* player = NULL;
	Stick* stick = NULL;
	ALLEGRO_BITMAP* playerImg=NULL;
	ALLEGRO_BITMAP* stickImg=NULL;
	// =====================

	/*ALLEGRO_VARIABLES*/

	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_EVENT_QUEUE* eq = NULL;
	ALLEGRO_TIMER* timer = NULL;
	ALLEGRO_FONT* font18 = NULL;

	// =====================

	/*ALLEGRO_INIT*/
	if(!al_init())
		return -1;
	display = al_create_display(WIDTH,HEIGHT);
	if(!display)
		return -1;

	// ======================

	/*ADDON_INSTALL*/

	al_install_keyboard();
	al_init_image_addon();
	al_init_font_addon(); // font before ttf always
	al_init_ttf_addon();
	al_init_primitives_addon();

	// ======================

	/*PROJECT_INIT*/
	srand(time(NULL));
	font18 = al_load_font("assets/FreeMonoBold.ttf",18,0);
	playerImg=al_load_bitmap("assets/player.png");
	stickImg=al_load_bitmap("assets/stick.png");
	al_convert_mask_to_alpha(playerImg,al_map_rgb(255,0,255));
	player = new Player();
	player->init(playerImg);

	stick = new Stick();
	stick->initImg(stickImg);
	stick->init(rand()%(WIDTH-32),rand()%(HEIGHT-32),0,0,0,0,32,32);
	// ======================


	/* TIMER AND START_UP */

	eq = al_create_event_queue();
	timer = al_create_timer(1.0/60);
	al_start_timer(timer);


	/* register events */

	al_register_event_source(eq,al_get_timer_event_source(timer));
	al_register_event_source(eq,al_get_keyboard_event_source());
	al_register_event_source(eq,al_get_display_event_source(display));


	// ======================

	/* THE LOOP */
	while(!done){
		ALLEGRO_EVENT ev;
		al_wait_for_event(eq,&ev);

		switch(ev.type){

		case ALLEGRO_EVENT_KEY_DOWN:

			switch(ev.keyboard.keycode){
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP]=true;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN]=true;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT]=true;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT]=true;
				break;
			case ALLEGRO_KEY_SPACE:
				keys[SPACE]=true;
				break;
			}

			break;

		case ALLEGRO_EVENT_KEY_UP:

			switch(ev.keyboard.keycode){
				case ALLEGRO_KEY_ESCAPE:
					done = true;
					break;
				case ALLEGRO_KEY_UP:
					keys[UP]=false;
					break;
				case ALLEGRO_KEY_DOWN:
					keys[DOWN]=false;
					break;
				case ALLEGRO_KEY_LEFT:
					keys[LEFT]=false;
					break;
				case ALLEGRO_KEY_RIGHT:
					keys[RIGHT]=false;
					break;
				case ALLEGRO_KEY_SPACE:
					keys[SPACE]=false;
					break;
				}
			break;

		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			done=true;
			break;

		/*UPDATE*/
		case ALLEGRO_EVENT_TIMER:
			render = true;
			if(keys[UP]){
				player->moveUp();
				// force one direction movement No diagonal movement
				keys[RIGHT]=false;
				keys[LEFT]=false;
			}else if(keys[DOWN]){
				player->moveDown();
				// force one direction movement No diagonal movement
				keys[RIGHT]=false;
				keys[LEFT]=false;
			}else
			// we should rest the animation for the player here
			player->restAnimation(1);

			if(keys[LEFT]){
				player->moveLeft();
				// force one direction movement No diagonal movement
				keys[UP]=false;
				keys[DOWN]=false;
			}else if(keys[RIGHT]){
				player->moveRight();
				// force one direction movement No diagonal movement
				keys[UP]=false;
				keys[DOWN]=false;
			}else
			// and rest it it here also.
			player->restAnimation(0);

			player->update();
			stick->update();
			if(stick->checkCollision(player)){
				stick->collided(player);
				stick->init(rand()%(WIDTH-32),rand()%(HEIGHT-32),0,0,0,0,32,32);
			}
			break;
		// ==================
		}

		/*RENDER*/
		if(render && al_is_event_queue_empty(eq)){
			render = false;
			// do rendering here
			player->render();
			stick->render();
			al_draw_textf(font18, al_map_rgb(255, 0, 255), 5, 5, 0, "Score: %i",player->getScore());
			al_flip_display();
			al_clear_to_color(al_map_rgb(0,0,0));
		}
		// ==================
	}

	// ======================



	/*DESTROY*/
	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_event_queue(eq);
	al_destroy_font(font18);
	al_destroy_bitmap(playerImg);
	al_destroy_bitmap(stickImg);
	delete player;
	delete stick;
	return 0;
}
