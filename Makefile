.SUFFIXES:
include config.mk

OBJ := $(SRC:.c=.o)

# MAKE sure that you have SDL2, SDL2-dev/devel, SDL2_ttf and SDL2_ttf-dev/devel installed
CFLAGS += -I/usr/include/SDL2
LDFLAGS += -lSDL2 -lSDL2_ttf

all: $(OBJ) $(OUT)

%.o: %.c
	$(CC) $< -c $(CFLAGS) -o "$@"

clean:
	rm -f $(OBJ) $(OUT)

ifneq ($(OUT),)
$(OUT): $(OBJ)
	$(CC) $^ $(LDFLAGS) -o "$@"
endif

.PHONY: all clean
