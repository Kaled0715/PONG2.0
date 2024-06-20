# Definiciones de variables
CXX = g++
CXXFLAGS = -std=c++11 -Wall
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

SRCDIR = src
INCDIR = include
BUILDDIR = obj
BINDIR = bin

SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(SOURCES:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)
EXECUTABLE = $(BINDIR)/main

# Regla para compilar el ejecutable
$(EXECUTABLE): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS) -Llib $(SFML_LIBS)

# Regla para compilar los archivos objeto
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c -o $@ $<

# Regla para ejecutar el programa
run: $(EXECUTABLE)
	./$(EXECUTABLE)

# Regla para limpiar los archivos compilados
clean:
	rm -rf $(BUILDDIR) $(BINDIR)
