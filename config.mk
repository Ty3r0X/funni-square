# Defaults
CC      := clang
DEBUG   := 1
STATIC  := 0

LDFLAGS :=
CFLAGS :=\
	-std=c99 \
	-Weverything \
	-Wno-padded \
	-Wno-disabled-macro-expansion \
	-pedantic

# Sources / Results
SRC :=\
        src/init.c \
	src/main.c

LIBDIR :=
LIB :=\
	c\
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
