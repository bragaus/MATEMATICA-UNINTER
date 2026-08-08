CC      ?= gcc
CFLAGS  ?= -Wall -Wextra -O2
LDLIBS   = -lm

# o teorema puro nao usa libc: syscalls Linux diretos, so bitwise
FREEFLAGS = -nostdlib -ffreestanding -no-pie -fno-stack-protector

BINARIOS = teorema linear llm-forward

.PHONY: all limpar
all: $(BINARIOS)

teorema: teorema_braga.c
	$(CC) $(CFLAGS) $(FREEFLAGS) -o $@ $<

linear: linear_braga.c
	$(CC) $(CFLAGS) -o $@ $< $(LDLIBS)

llm-forward: llm_forward_braga.c
	$(CC) $(CFLAGS) -o $@ $< $(LDLIBS)

limpar:
	rm -f $(BINARIOS)
