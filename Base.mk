CC=gcc
CFLAGS=-Wall

BDIR=./bin
SDIR=./
ODIR=./obj

BIN=$(BDIR)/app
SRCS=$(wildcard $(SDIR)/*.c)
OBJS=$(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRCS))

all: $(BIN)

$(BIN): $(OBJS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $^ -o $@

$(ODIR)/%.o: $(SDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $^ -o $@

run: all
	@printf "\tRunning %s...\n" $(BIN)
	@$(BIN)

clean:
	$(RM) -r $(BDIR)/* $(ODIR)/*
