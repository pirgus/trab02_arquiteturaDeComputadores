# Define o compilador C padrão para a versão sequencial
CC = gcc

# Define o compilador CUDA/OpenACC para a versão paralela
NVCC = nvc

# Define as flags de compilação para a versão paralela
# -fast: Otimizações de compilação
# -Minfo=acc: Exibe mensagens informativas do compilador OpenACC
# -acc: Habilita a compilação com OpenACC
# -gpu=cc89: Especifica a arquitetura da GPU (Compute Capability 8.9 neste exemplo)
NVCC_FLAGS = -fast -Minfo=acc -acc -gpu=cc89

# Nome dos executáveis
SEQ_EXEC = friendly_seq
PAR_EXEC = friendly_par

# Arquivos fonte
SEQ_SRC = friendly_seq.c
PAR_SRC = friendly_par.c

.PHONY: all clean

all: $(SEQ_EXEC) $(PAR_EXEC)

$(SEQ_EXEC): $(SEQ_SRC)
	$(CC) $(SEQ_SRC) -o $(SEQ_EXEC)

$(PAR_EXEC): $(PAR_SRC)
	$(NVCC) $(NVCC_FLAGS) $(PAR_SRC) -o $(PAR_EXEC)

clean:
	rm -f $(SEQ_EXEC) $(PAR_EXEC)
	rm -f *.o # Remove arquivos objeto, se houver