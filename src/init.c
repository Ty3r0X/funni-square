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
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <stdlib.h>

#define THIRTYTWO_BIT 32

/* Global variables */

SDL_Window   *window;
SDL_Renderer *main_render;
SDL_Event    *main_event;
SDL_Texture  *background;
SDL_Rect     *rectangle;

int
init_program (void) {

	printf ("MMXXIII Ty3r0X - The Eye shall forsee...\n");

	/* Initialization Checks */

	if (SDL_Init (SDL_INIT_VIDEO) != 0) {
		return fprintf (stderr, "SDL initialization error: %s\n", SDL_GetError ());
	}

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
	background  = SDL_CreateTexture (main_render, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SCREEN_WIDTH, SCREEN_HEIGHT);

	/* Initialize rectangle*/

	rectangle    = calloc (1, sizeof (SDL_Rect));
	rectangle->w = RECT_SIZE;
	rectangle->h = RECT_SIZE;

	/* A new variable is created called main_event, which is a SDL_Event type, which itself is a structure
	 * of multiple structures... of events... */

	main_event = calloc (1, sizeof (SDL_Event));

	if (main_event == NULL) {
		return fprintf (stderr, "Failed to allocate memory for main event structure %s\n", SDL_GetError ());
	}

	return EXIT_SUCCESS;
}
