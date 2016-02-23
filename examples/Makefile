#	$@	file name of the target of the rule
#	$<	name of first prerequisite
#	$^	names of ALL prerequisites with spaces between them
#	$?	names of all NEWER prerequisites

SRCS = $(wildcard *.c)
BIN=./bin/

PROGS = $(patsubst %.c,$(BIN)%,$(SRCS))

all: $(PROGS)

$(BIN)%: %.c
	$(CC) $(CFLAGS) -o $@ $?
#	./$@

clean:
	$(RM) bin/*