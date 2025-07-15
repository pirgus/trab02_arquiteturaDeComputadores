# Nome dos executáveis
PAR_EXEC = bucket_par.x
SEQ_EXEC = bucket_seq.x
GERA_LISTA = gera_lista.x

# Compilador C
CC = gcc

# Flags de compilação
CFLAGS_PAR = -Wall -fopenmp
CFLAGS_SEQ = -Wall

.PHONY: all clean

all: $(PAR_EXEC) $(SEQ_EXEC) $(GERA_LISTA)

$(PAR_EXEC): bucket_par.c
	$(CC) $(CFLAGS_PAR) bucket_par.c -o $(PAR_EXEC)

$(SEQ_EXEC): bucket_seq.c
	$(CC) $(CFLAGS_SEQ) bucket_seq.c -o $(SEQ_EXEC)

$(GERA_LISTA): gera_lista.c
	$(CC) $(CFLAGS_SEQ) gera_lista.c -o $(GERA_LISTA)

clean:
	rm -f $(PAR_EXEC) $(SEQ_EXEC) $(GERA_LISTA)