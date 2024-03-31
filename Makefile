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

SFML$(SLASH)build:
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

build: SFML$(SLASH)build
	cmake -S . -B build

bin: build
	$(MAKE) -C .$(SLASH)$(<)$(SLASH)
	$(MKDIR) $(@)
	$(MV) .$(SLASH)$(<)$(SLASH)chess_game .$(SLASH)$(@)

run: bin
	.$(SLASH)$(<)$(SLASH)chess_game
.PHONY:run

clean:
	$(RM) SFML$(SLASH)build build bin
.PHONY: clean