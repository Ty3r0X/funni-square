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
 *   main.c
 *
 *   Copyright (C) MMXXIII Patrick D. Covaci <ty3r0x@chaox.ro>
 *
 *   The source is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   FITNESS FOR A PARTICULAR PURPOSE.
 *
 */

#include "window.h"

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_video.h>
#include <stdbool.h>
#include <stdlib.h>

#define HEX_POKE 0xFF

int
main (int argc, char *argv[]) {

	struct coords {
		int x;
		int y;
	} ray;

	Uint8 bg_red   = 0x00;
	Uint8 bg_green = HEX_POKE;
	Uint8 bg_blue  = 0x00;

	if (init_program () != EXIT_SUCCESS)
		return EXIT_FAILURE;

	for (int i = 0; i < argc; i++)
		printf ("%s\n", argv[i]);

	ray.x = 1;
	ray.y = 1;

	rectangle->x = (int) SCREEN_WIDTH / 2;
	rectangle->y = (int) SCREEN_HEIGHT / 2;

	for (;;) {

		/* Constantly initialize boolean values for corners, each for loop
		 * iteration they change values */

		bool x_limit = (rectangle->x <= 0 || rectangle->x >= SCREEN_WIDTH - RECT_SIZE);
		bool y_limit = (rectangle->y <= 0 || rectangle->y >= SCREEN_HEIGHT - RECT_SIZE);

		SDL_SetRenderTarget (main_render, background);
		SDL_SetRenderDrawColor (main_render, bg_red, bg_green, bg_blue, 0x00);
		SDL_RenderClear (main_render);
		SDL_RenderDrawRect (main_render, rectangle);
		SDL_SetRenderDrawColor (main_render, HEX_POKE, 0x00, 0x00, 0x00);
		SDL_RenderFillRect (main_render, rectangle);
		SDL_SetRenderTarget (main_render, NULL);
		SDL_RenderCopy (main_render, background, NULL, NULL);
		SDL_RenderPresent (main_render);

		/* Normally the rect constantly goes up diagonally, if it reaches a
		 * corner the next position gets multiplied with -1 on its respective
		 * axis so it goes the opposite direction*/

		if (x_limit)
			ray.x *= -1;

		if (y_limit)
			ray.y *= -1;

		/* Clear queue of mouse / keyboard events */

		while (SDL_PollEvent (main_event))
			switch (main_event->type) {

				case SDL_QUIT:
					printf ("Quit event detected, now exiting. See ya! :)\n");
					printf ("MMXXIII Ty3r0X - The Eye shall forsee...\n");
					SDL_DestroyRenderer (main_render);
					SDL_DestroyWindow (window);
					SDL_Quit ();
					return EXIT_SUCCESS;

				case SDL_MOUSEMOTION:
					if (check_interaction_in_rect (main_event->motion.x, main_event->motion.y, rectangle)) {
						printf ("Mouse cursor is inside the square at position (%d,%d)\n", main_event->motion.x, main_event->motion.y);
						ray.x *= -1;
						ray.y *= -1;
						rectangle->x = rand () % 500;
						rectangle->y = rand () % 500;
						bg_red       = rand () & HEX_POKE;
						bg_green     = rand () & HEX_POKE;
						bg_blue      = rand () & HEX_POKE;
					}
					break;

				default:
					break;
			}

		/* Constantly increment / decrement rectangle position */

		rectangle->x = rectangle->x + (1 * ray.x);
		rectangle->y = rectangle->y + (1 * ray.y);

		SDL_Delay (3);
	}
}
