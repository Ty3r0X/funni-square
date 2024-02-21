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

#define HEX_POKE     0xFF
#define COUNTER_SIZE 100

int
main (int argc, const char *argv[]) {

	struct pos ray;
	int        counter = 0;

	Uint8 bg_red   = 0x00;
	Uint8 bg_green = HEX_POKE;
	Uint8 bg_blue  = 0x00;

	printf ("MMXXIII Ty3r0X\n");

	if (init_program () != EXIT_SUCCESS)
		return EXIT_FAILURE;

	/* Print argv - useless but used to stop
	 * my compiler from yelling */

	for (int i = 0; i < argc; i++)
		printf ("%s\n", argv[i]);

	ray.x = 1;
	ray.y = 1;

	rectangle->x = (int) SCREEN_WIDTH / 2;
	rectangle->y = (int) SCREEN_HEIGHT / 2;

	for (;;) {

		/* Initialize counter array */

		char counter_text[COUNTER_SIZE];

		/* Constantly initialize boolean values for corners, each for loop
		 * iteration they change values */

		bool x_limit = (rectangle->x <= 0 || rectangle->x >= SCREEN_WIDTH - RECT_SIZE);
		bool y_limit = (rectangle->y <= 0 || rectangle->y >= SCREEN_HEIGHT - RECT_SIZE);

		/* Insert counter values into the array */

		snprintf (counter_text, sizeof (counter_text), "%d", counter);

		text_surface = TTF_RenderText_Solid (text_font, counter_text, *text_color);
		text_texture = SDL_CreateTextureFromSurface (main_render, text_surface);

		/* Snatch counter_box's width and size by querying text_surface */

		SDL_QueryTexture (text_texture, NULL, NULL, &counter_box.w, &counter_box.h);

		/* Background render*/

		SDL_SetRenderTarget (main_render, background);
		SDL_SetRenderDrawColor (main_render, bg_red, bg_green, bg_blue, 0x00);
		SDL_RenderClear (main_render);

		/* Rectangle render */

		SDL_RenderDrawRect (main_render, rectangle);
		SDL_SetRenderDrawColor (main_render, HEX_POKE, 0x00, 0x00, 0x00);
		SDL_RenderFillRect (main_render, rectangle);
		SDL_SetRenderTarget (main_render, NULL);
		SDL_RenderCopy (main_render, background, NULL, NULL);

		/* Counter render */

		SDL_RenderCopy (main_render, text_texture, NULL, &counter_box);

		/* All finished, time to show on screen */

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
					printf ("Quit event detected, now exiting.\n");
					SDL_DestroyRenderer (main_render);
					SDL_DestroyWindow (window);
					SDL_Quit ();
					return EXIT_SUCCESS;

				case SDL_MOUSEMOTION:
					if (check_interaction_in_rect (main_event->motion.x, main_event->motion.y, rectangle)) {
						printf ("Mouse cursor is inside the square at position (%d,%d)\n",
						        main_event->motion.x,
						        main_event->motion.y);

						ray.x *= -1;
						ray.y *= -1;

						rectangle->x = rand () % (int) (SCREEN_WIDTH - 1 - RECT_SIZE);
						rectangle->y = rand () % (int) (SCREEN_HEIGHT - 1 - RECT_SIZE);

						bg_red   = rand () & HEX_POKE;
						bg_green = rand () & HEX_POKE;
						bg_blue  = rand () & HEX_POKE;

						counter++;
					}
					break;

				default:
					break;
			}

		/* Constantly increment / decrement rectangle position */

		rectangle->x = rectangle->x + (1 * ray.x);
		rectangle->y = rectangle->y + (1 * ray.y);

		/* Add a delay, let the CPU breathe */

		SDL_Delay (3);
	}
}
