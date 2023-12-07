.SUFFIXES:

ifeq ($(strip $(DEVKITPRO)),)
$(error "Please set DEVKITPRO in your environment. export DEVKITPRO=<path to>/devkitpro")
endif

include $(DEVKITPRO)/wut/share/wut_rules
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
