# Змінні (Макроси)
# Компілятор C
CC = gcc

# Прапорці компіляції:
# -IHeader : додати директорію Header до шляхів пошуку заголовочних файлів
# -Wall    : увімкнути всі основні попередження
CFLAGS = -IHeader -Wall

# -lm : підключити математичну бібліотеку (libm)
LDFLAGS = -lm

# Назва підсумкового виконуваного файлу
TARGET = lab5

# Список об'єктних файлів, необхідних для збірки
OBJS = lab5.o funct.o

# Правила збірки
# Головна ціль за замовчуванням
all: $(TARGET)

# Правило для компонування підсумкового виконуваного файлу з об'єктних файлів
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Компіляція lab5.c в lab5.o
lab5.o: Source/lab5.c Header/funct.h
	$(CC) $(CFLAGS) -c Source/lab5.c -o lab5.o

# Компіляція funct.c в funct.o
funct.o: Source/funct.c Header/funct.h
	$(CC) $(CFLAGS) -c Source/funct.c -o funct.o

# Очищення
clean:
	rm -f *.o $(TARGET) $(TARGET).exe Source/lab5.exe