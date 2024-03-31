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

all: chess_game
.PHONY:all

extlibs$(SLASH)SFML$(SLASH)build:
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
	libgbm-dev
endif
	cmake -S $(@)$(SLASH).. -B $(@) $(TARGET) -DBUILD_SHARED_LIBS=true
	$(MAKE) -C $(@)

build: extlibs$(SLASH)SFML$(SLASH)build
	cmake -S . -B build

chess_game: build
	$(MAKE) -C .$(SLASH)$(<)$(SLASH)
	$(MV) .$(SLASH)$(<)$(SLASH)$(@) .

run: chess_game
	./chess_game
.PHONY:run

clean:
	$(RM) extlibs$(SLASH)SFML$(SLASH)build build
.PHONY: clean