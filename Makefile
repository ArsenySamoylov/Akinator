CC := g++ 
STDNAME := SPrYtny

CFLAGS  := -Wall -Wextra -Wpedantic                   -Wshadow           -Winit-self            -Wredundant-decls      -Wcast-align         \
           -Wfloat-equal -Winline                     -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wundef              \
		   -Wswitch-enum -Wswitch-default             -Weffc++           -Wmain                 -Wextra                -Wcast-qual          \
		   -Wconversion  -Wctor-dtor-privacy          -Wempty-body       -Wformat-security      -Wformat=2             -Wignored-qualifiers \
		   -Wlogical-op  -Wmissing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual   -Wpointer-arith                             \
		   -Wsign-promo  -Wstack-usage=8192           -Wstrict-aliasing  -Wstrict-null-sentinel -Wtype-limits          -Wwrite-strings      \
		   -D_DEBUG      -D_EJUDGE_CLIENT_SIDE        -Wall              -g                     -pipe                  -fexceptions


SRCDIR := src ATC/Log/ ATC/Buffer/ ATC/Additional/
SRC    := $(wildcard $(addsuffix /*.cpp, $(SRCDIR)) )

INCDIR   := headers ATC/Log/ ATC/Buffer/ ATC/Additional/
INCLUDES := $(addprefix -I, $(INCDIR)) 

OBJDIR := build
OBJ    := $(patsubst %.cpp, $(OBJDIR)/%.o, $(notdir $(SRC)) )

ARGV   := 

VPATH  := $(SRCDIR)

$(STDNAME): $(OBJ)
	@$(CC) $(OBJ) -o $@

$(OBJDIR)/%.o: %.cpp
	@$(CC) -c $(INCLUDES) $(CFLAGS) $< -o $@ 

run: clean $(STDNAME)
	@./$(STDNAME) $(ARGV)

clean:
	@rm -rf $(OBJ) $(STDNAME)
