# Detect the operating system
ifdef SystemRoot
    # Windows
    OS := Windows
else
    # Linux
    OS := $(shell uname)
endif

# Rule for Linux and Windows
ifeq ($(OS),Linux)
    MAKE := make
    RM := rm -rf
    MKDIR := mkdir -p
    MV := mv
	TARGET :=
    SLASH := /
    EXT :=
else ifeq ($(OS),Windows)
    MAKE := mingw32-make
    RM := del /Q /S
    MKDIR := mkdir
    MV := move
	TARGET := -G "MinGW Makefiles"
    SLASH := \\
    EXT := .exe
else
    $(error Unsupported operating system: $(OS))
endif

all: bin
.PHONY:all

SFML:
	git clone --branch 2.6.0 https://github.com/SFML/SFML.git

SFML$(SLASH)build: SFML
ifeq ($(OS),Linux)
	sudo apt update
	sudo apt install \
	libxrandr-dev \
	libxcursor-dev \
	libudev-dev \
	libopenal-dev \
	libflac-dev \
	libvorbis-dev \
	libgl1-mesa-dev \
	libegl1-mesa-dev \
	libdrm-dev \
	libfreetype-dev \
	libgbm-dev
endif
	cmake -S $(@)$(SLASH).. -B $(@) $(TARGET) -DBUILD_SHARED_LIBS=true
	$(MAKE) -C $(@)

build: SFML$(SLASH)build
	cmake -S . -B build $(TARGET)

bin: build
	$(MAKE) -C .$(SLASH)$(<)$(SLASH)
ifeq ($(wildcard bin), )
	$(MKDIR) $(@)
endif
	$(MV) .$(SLASH)$(<)$(SLASH)chess_game$(EXT) .$(SLASH)$(@)
.PHONY:bin

run:
ifeq ($(OS), Windows)
	$(if $(wildcard bin), \
    @$(MV) .$(SLASH)SFML$(SLASH)build$(SLASH)lib$(SLASH)*.dll bin)
endif
	$(if $(wildcard bin), \
    @.$(SLASH)bin$(SLASH)chess_game$(EXT), \
    @echo "Compile bin first")
.PHONY:run

clean:
	$(RM) SFML
	$(RM) build
	$(RM) bin
.PHONY: clean