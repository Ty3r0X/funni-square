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
 *   init.c - executes initialization functions + allocations
 *
 *   Copyright (C) MMXXIII Patrick D. Covaci <ty3r0x@chaox.ro>
 *
 *   The source is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   FITNESS FOR A PARTICULAR PURPOSE.
 *
 */

#include "window.h"

#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <stdlib.h>

/* Global variables */

SDL_Window   *window;
SDL_Renderer *main_render;
SDL_Event    *main_event;
SDL_Texture  *background;
SDL_Rect     *rectangle;
SDL_Surface  *text_surface;
SDL_Texture  *text_texture;
TTF_Font     *text_font;
SDL_Color    *text_color;
SDL_Rect      counter_box;

int
init_program (void) {
	/* Initialization Checks */

	if (SDL_Init (SDL_INIT_VIDEO) < 0)
		return fprintf (stderr, "SDL initialization error: %s\n", SDL_GetError ());

	if (TTF_Init () < 0)
		return fprintf (stderr, "Font initialization error: %s\n", SDL_GetError ());

	/* window variable initialization */

	window = SDL_CreateWindow ("Hello There",
	                           POS_X,
	                           POS_Y,
	                           SCREEN_WIDTH,
	                           SCREEN_HEIGHT,
	                           SDL_WINDOW_SHOWN);

	if (window == NULL) {
		return fprintf (stderr, "SDL Window Creation Error: %s\n", SDL_GetError ());
	}

	/* Background initialization */

	main_render = SDL_CreateRenderer (window, -1, 0);
	background  = SDL_CreateTexture (main_render,
                                        SDL_PIXELFORMAT_RGBA8888,
                                        SDL_TEXTUREACCESS_TARGET,
                                        SCREEN_WIDTH,
                                        SCREEN_HEIGHT);

	/* Initialize rectangle*/

	rectangle    = calloc (1, sizeof (SDL_Rect));
	rectangle->w = RECT_SIZE;
	rectangle->h = RECT_SIZE;

	/* Counter initialization */

	counter_box.x = COUNTER_BOX_X;
	counter_box.y = COUNTER_BOX_Y;
	text_font     = TTF_OpenFont ("arimo.ttf", COUNTER_TEXT_SIZE);
	text_surface  = NULL;
	text_texture  = NULL;
	text_color    = calloc (1, sizeof (SDL_Color));
	text_color->r = 255;
	text_color->g = 255;
	text_color->b = 255;

	/* A new variable is created called main_event, which is a SDL_Event type, which itself is a structure
	 * of multiple structures... of events... */

	main_event = calloc (1, sizeof (SDL_Event));

	if (main_event == NULL) {
		return fprintf (stderr, "Failed to allocate memory for main event structure %s\n", SDL_GetError ());
	}

	return EXIT_SUCCESS;
}
