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

	if (init_program () != EXIT_SUCCESS)
		return EXIT_FAILURE;

	struct coords {
		int x;
		int y;
	} ray;

	ray.x = 1;
	ray.y = 1;

	rectangle->x = (int) SCREEN_WIDTH / 2;
	rectangle->y = (int) SCREEN_HEIGHT / 2;

	for (;;) {

		SDL_SetRenderTarget (main_render, background);
		SDL_SetRenderDrawColor (main_render, 0x00, HEX_POKE, 0x00, 0x00);
		SDL_RenderClear (main_render);
		SDL_RenderDrawRect (main_render, rectangle);
		SDL_SetRenderDrawColor (main_render, HEX_POKE, 0x00, 0x00, 0x00);
		SDL_RenderFillRect (main_render, rectangle);
		SDL_SetRenderTarget (main_render, NULL);
		SDL_RenderCopy (main_render, background, NULL, NULL);
		SDL_RenderPresent (main_render);

		bool x_limit = (rectangle->x == 0 || rectangle->x == SCREEN_WIDTH);
		bool y_limit = (rectangle->y == 0 || rectangle->y == SCREEN_HEIGHT);

		if (x_limit)
			ray.x *= -1;

		if (y_limit)
			ray.y *= -1;

		SDL_PollEvent (main_event);

		if (main_event->type == SDL_QUIT) {
			printf ("Quit event detected, now exiting. See ya! :)\n");
			printf ("MMXXIII Ty3r0X - The Eye shall forsee...\n");
			SDL_DestroyRenderer (main_render);
			SDL_DestroyWindow (window);
			SDL_Quit ();
			return EXIT_SUCCESS;
		}

		rectangle->x = rectangle->x + (1 * ray.x);
		rectangle->y = rectangle->y + (1 * ray.y);

		/*while (SDL_PollEvent (main_event)) {
		        switch (main_event->type) {
		                case SDL_MOUSEMOTION:
		                        if (check_interaction_in_rect (main_event->motion.x, main_event->motion.y, rectangle)) {
		                                rectangle->x = rand () % 500;
		                                rectangle->y = rand () % 500;
		                                printf ("You touched the square! X position: %d, Y position %d\n", main_event->motion.x, main_event->motion.y);
		                        }
		                        break;

		                case SDL_WINDOWEVENT:
		                        printf ("Window position is being altered!\n");
		                        printf ("Current window position: (%d,%d)\t", main_event->window.data1, main_event->window.data2);
		                        break;

		                default:
		                        printf ("Unhandled event\n\n");
		                        break;
		        }
		}
	*/
	}
}
