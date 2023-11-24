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

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <stdlib.h>
#define HEX_POKE 0xFF

int
main (int argc, char *argv[]) {

	if (init_program () != EXIT_SUCCESS)
		return EXIT_FAILURE;

	/* We now enter an infinite loop */

	for (;;) {

		rectangle->x = rand () % 500;
		rectangle->y = rand () % 500;

		SDL_SetRenderTarget (main_render, background);
		SDL_SetRenderDrawColor (main_render, 0x00, HEX_POKE, 0x00, 0x00);
		SDL_RenderClear (main_render);
		SDL_RenderDrawRect (main_render, rectangle);
		SDL_SetRenderDrawColor (main_render, HEX_POKE, 0x00, 0x00, 0x00);
		SDL_RenderFillRect (main_render, rectangle);
		SDL_SetRenderTarget (main_render, NULL);
		SDL_RenderCopy (main_render, background, NULL, NULL);
		SDL_RenderPresent (main_render);

		/* Now we constantly check the type of event it's occouring, so far I have declared two events, since
		 * this is my first time messing around with SDL this is the algo I came up with which is partly inspired
		 * by the manpage. It obviously is NOT pretty and could be made better, but this has to suffice :-) */

		while (SDL_PollEvent (main_event)) {
			switch (main_event->type) {
				case SDL_MOUSEMOTION:
					if (check_interaction_in_rect (main_event->motion.x, main_event->motion.y, rectangle))
						printf ("You touched the square! X position: %d, Y position %d\n", main_event->motion.x, main_event->motion.y);
					break;

					/* Yes I acknowledge this is a very hacky way to exit the program, my apologies */

				case SDL_QUIT:
					printf ("Quit event detected, now exiting. See ya! :)\n");
					printf ("MMXXIII Ty3r0X - The Eye shall forsee...\n");
					SDL_DestroyRenderer (main_render);
					SDL_DestroyWindow (window);
					SDL_Quit ();
					return EXIT_SUCCESS;

				case SDL_WINDOWEVENT:
					printf ("Window position is being altered!\n");
					printf ("Current window position: (%d,%d)\t", main_event->window.data1, main_event->window.data2);
					break;

				default:
					printf ("Unhandled event\n\n");
					break;
			}
		}
	}
}
