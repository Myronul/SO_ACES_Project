# Compilatorul și flag-urile
CC = gcc
CFLAGS = -Wall -Wextra -I inc
LDFLAGS = 

# Directoare
SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj
BIN_DIR = .

# Numele executabilului
TARGET = $(BIN_DIR)/soProject

# Găsește toate fișierele .c din src
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Creează lista de fișiere obiect
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Regula principală
all: $(OBJ_DIR) $(TARGET)

# Creează directorul pentru fișierele obiect
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Link-uiește executabilul
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Compilează fișierele .c în .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Curăță fișierele compilate
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Recompilează totul
rebuild: clean all

.PHONY: all clean rebuild