# Compiler | TODO: использовать компилятор c++
CC=clang

# Important (making object) flags
CFLAGS=-c -D _DEBUG -ggdb3 -Wall -Wextra -Weffc++ -Wcast-align -Wcast-qual -Wchar-subscripts -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat=2 -Winline -Wnon-virtual-dtor -Woverloaded-virtual -Wpacked -Wpointer-arith -Wredundant-decls -Wsign-promo -Wstrict-overflow=2 -Wsuggest-override -Wswitch-default -Wswitch-enum -Wundef -Wunreachable-code -Wunused -Wvariadic-macros -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -fcheck-new -fsized-deallocation -fstack-check -fstack-protector -fstrict-overflow -fno-omit-frame-pointer -fPIE -O0

# Linker flags
LDFLAGS=-lm

# Sources to make object files to pack bin
SOURCES=main.c solve_equation.c user_interface.c

# Just pick up SOURCES and change extension to .o (objects)
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=bin

.PHONY: all .c.o clean go

all: $(EXECUTABLE)

go: all
	./$(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)
