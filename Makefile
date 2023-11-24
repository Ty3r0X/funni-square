.SUFFIXES:
include config.mk

OBJ := $(SRC:.c=.o)

all: $(OBJ) $(OUT)
%.o: %.c
	$(CC) -o $@ -c $(CFLAGS) $<
clean:
	rm -f $(OBJ) $(OUT)

ifneq ($(OUT),)
$(OUT): $(OBJ)
	$(CC) -o "$@" $(LDFLAGS) $^
endif

.PHONY: all clean
