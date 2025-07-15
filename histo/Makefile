# Nome dos executáveis
PAR_EXEC = histogram_par.x
SEQ_EXEC = histogram_seq.x

# Compilador C
CC = gcc

# Flags de compilação
CFLAGS_PAR = -Wall -fopenmp
CFLAGS_SEQ = -Wall

.PHONY: all clean

all: $(PAR_EXEC) $(SEQ_EXEC)

$(PAR_EXEC): histogram_par.c
	$(CC) $(CFLAGS_PAR) histogram_par.c -o $(PAR_EXEC)

$(SEQ_EXEC): histogram_seq.c
	$(CC) $(CFLAGS_SEQ) histogram_seq.c -o $(SEQ_EXEC)

clean:
	rm -f $(PAR_EXEC) $(SEQ_EXEC)