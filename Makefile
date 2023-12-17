.SUFFIXES:
include config.mk

OBJ := $(SRC:.c=.o)

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
