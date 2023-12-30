# Defaults
CC      := gcc
DEBUG   := 1
STATIC  := 0
PLATFORM := linux

LDFLAGS :=
CFLAGS :=\
	-std=c99 \
	-Werror\
	-Wno-padded \
	-Wno-disabled-macro-expansion \
	-pedantic

# Sources / Results
SRC :=\
        src/rectangle.c \
        src/init.c \
	src/main.c

LIBDIR :=
LIB :=\
        c\
	SDL2main\
	SDL2\

INCDIR :=\
	src/

OUT := project

# Conditionals / Appends
LDFLAGS +=\
	$(addprefix -L,${LIBDIR})\
	$(addprefix -l,${LIB})

CFLAGS +=\
	$(addprefix -I,${INCDIR})

ifeq (${DEBUG},1)
CFLAGS += -g
else
CFLAGS += -O2 -Werror
endif

ifeq (${STATIC},1)
LDFLAGS += -static
endif
