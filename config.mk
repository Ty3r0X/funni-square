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
        src/rectangle.c \
        src/init.c \
	src/main.c

LIBDIR := $(PORTLIBS) $(WUT_ROOT)
LIB :=\
	c\
	SDL2\
	wut

INCDIR :=\
	src/

OUT := project.rpx

# Conditionals / Appends
LDFLAGS +=\
	$(addprefix -L,${LIBDIR})\
	$(addprefix -l,${LIB})

CFLAGS +=\
	$(addprefix -I,${INCDIR})\
	$(INCLUDE) -D__WIIU__ -D__WUT__

ifeq (${DEBUG},1)
CFLAGS += -g
else
CFLAGS += -O2 -Werror
endif

ifeq (${STATIC},1)
LDFLAGS += -static
endif
