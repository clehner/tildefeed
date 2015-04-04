VERSION = 0.0.1

CC ?= gcc
CFLAGS = -MMD -Isrc -Wall -Wextra -Werror -pedantic -std=c99 -Wno-unused-parameter -DVERSION=\"$(VERSION)\"

BIN = smallfeed
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
DEP = $(SRC:.c=.d)

ifndef V
	QUIET_CC   = @echo ' CC   ' $<;
	QUIET_LINK = @echo ' LINK ' $@;
endif

all: $(BIN)

-include $(DEP)

.c.o:
	$(QUIET_CC)$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ): Makefile

$(BIN): $(OBJ)
	$(QUIET_LINK)$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(BIN) $(OBJ) $(DEP)

.PHONY: clean
