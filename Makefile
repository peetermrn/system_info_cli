COMPILER = gcc
SRCDIR = src
BUILDDIR = build
TARGET = sys_info
BINDIR = /usr/local/bin

SOURCES = $(wildcard $(SRCDIR)/*.c)
#OBJECTS = build/main.o build/utils.o build/helper.o
OBJECTS = $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SOURCES))

.PHONY: clean install uninstall

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

# https://linuxhandbook.com/install-command/
install: $(TARGET)
	install -m 755 $(TARGET) $(BINDIR)/$(TARGET)

uninstall:
	rm -f $(BINDIR)/$(TARGET)
