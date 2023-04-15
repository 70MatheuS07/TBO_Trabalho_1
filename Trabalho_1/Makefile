CC = gcc
LDLIBS = -lm

# Arquivos fonte
SRCS = trab1.c Arquivo.c tPonto.c

# Arquivos objeto correspondentes
OBJS = $(SRCS:.c=.o)

all: trab1

trab1: $(OBJS)
	$(CC) $(OBJS) $(LDLIBS) -o trab1

%.o: %.c %.h
	$(CC) -c $< -o $@

clean:
	rm -f trab1 $(OBJS)
