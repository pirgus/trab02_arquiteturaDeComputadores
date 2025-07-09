# Nome dos executáveis
PAR_EXEC = bucket_par.x
SEQ_EXEC = bucket_seq.x

# Compilador C
CC = gcc

# Flags de compilação
CFLAGS_PAR = -Wall -fopenmp
CFLAGS_SEQ = -Wall

.PHONY: all clean

all: $(PAR_EXEC) $(SEQ_EXEC)

$(PAR_EXEC): bucket_par.c
	$(CC) $(CFLAGS_PAR) bucket_par.c -o $(PAR_EXEC)

$(SEQ_EXEC): bucket_seq.c
	$(CC) $(CFLAGS_SEQ) bucket_seq.c -o $(SEQ_EXEC)

clean:
	rm -f $(PAR_EXEC) $(SEQ_EXEC)