CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

OBJDIR = obj
SRCDIR = src
BINDIR = bin

OBJS = $(OBJDIR)/Ball.o $(OBJDIR)/Paddle.o $(OBJDIR)/Score.o $(OBJDIR)/SoundManager.o $(OBJDIR)/Juego.o $(OBJDIR)/Main.o
TARGET = $(BINDIR)/PongGame.exe

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJDIR)/*.o $(TARGET)
