# https://medium.com/@schuylertk/a-beginners-guide-to-creating-and-using-makefiles-83f386856aa5
# https://stackoverflow.com/questions/21548464/how-to-write-a-makefile-to-compile-a-simple-c-program
# https://stackoverflow.com/questions/8941110/how-i-could-add-dir-to-path-in-makefile
# https://stackoverflow.com/questions/3915067/what-are-makefiles-make-install-etc
# https://stackoverflow.com/questions/39892692/how-to-implement-make-install-in-a-makefile

COMPILER = gcc
SRCDIR = src
BUILDDIR = build
TARGET = sys_info
BINDIR = /usr/local/bin

SOURCES = $(wildcard $(SRCDIR)/*.c)
#OBJECTS = build/main.o build/utils.o build/helper.o
OBJECTS = $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SOURCES))

.PHONY: all clean install uninstall

all: $(BUILDDIR) $(TARGET)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Link object files into executable
# gcc -o sys_info build/main.o build/utils.o build/helper.o
$(TARGET): $(OBJECTS)
	$(COMPILER) -o $@ $^

# Compile .c files to .o files in build directory
# gcc -c src/main.c -o build/main.o
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(COMPILER) -c $< -o $@

clean:
	-rm -rf $(BUILDDIR) $(TARGET)

install: $(TARGET)
	install -m 755 $(TARGET) $(BINDIR)/$(TARGET)

uninstall:
	rm -f $(BINDIR)/$(TARGET)
