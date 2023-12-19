/*    ----------------------------------------------------------
 *     @@@@@@@  @@@ @@@  @@@@@@   @@@@@@@    @@@@@@@@   @@@  @@@
 *     @@@@@@@  @@@ @@@  @@@@@@@  @@@@@@@@  @@@@@@@@@@  @@@  @@@
 *       @@!    @@! !@@      @@@  @@!  @@@  @@!   @@@@  @@!  !@@
 *       !@!    !@! @!!      @!@  !@!  @!@  !@!  @!@!@  !@!  @!!
 *       @!!     !@!@!   @!@!!@   @!@!!@!   @!@ @! !@!   !@@!@!
 *       !!!      @!!!   !!@!@!   !!@!@!    !@!!!  !!!    @!!!
 *       !!:      !!:        !!:  !!: :!!   !!:!   !!!   !: :!!
 *       :!:      :!:        :!:  :!:  !:!  :!:    !:!  :!:  !:!
 *        ::       ::    :: ::::  ::   :::  ::::::: ::   ::  :::
 *    ----------------------------------------------------------
 *
 *   window.h
 *
 *   Copyright (C) MMXXIII Patrick D. Covaci <ty3r0x@chaox.ro>
 *
 *   The source is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   FITNESS FOR A PARTICULAR PURPOSE.
 *
 */
#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <pthread.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define SCREEN_WIDTH  800.0
#define SCREEN_HEIGHT 600.0
#define POS_X         100
#define POS_Y         100

#define COLOR_R 0xFF
#define COLOR_G 0xA5
#define COLOR_B 0x00

#define RECT_SIZE 100

extern SDL_Window   *window;
extern SDL_Renderer *main_render;
extern SDL_Texture  *background;
extern SDL_Rect     *rectangle;
extern SDL_Event    *main_event;
extern struct coords ray;

extern Uint8 bg_red;
extern Uint8 bg_green;
extern Uint8 bg_blue;

int   init_program (void);
int   check_interaction_in_rect (int x_cursor, int y_cursor, struct SDL_Rect *rect);
void *drawScreen (void *vargp);
void  modifyRectanglePosition (void);

#endif
