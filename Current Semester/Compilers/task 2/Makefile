# Nome do arquivo de saída
TARGET = output

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -I.

# Arquivos de código-fonte
SRC = main.c funcs.c

# Arquivos objeto
OBJ = $(SRC:.c=.o)

# Regra padrão
all: $(TARGET)

# Regra de linkedição
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Regra de compilação para arquivos .c
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET) input.txt

# Limpar arquivos gerados
clean:
	rm -f $(TARGET) $(OBJ)

# Declarar como alvos que não são arquivos
.PHONY: all clean
