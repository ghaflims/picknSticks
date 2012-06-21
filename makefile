C++ = g++
LIBS = -lallegro -lallegro_image -lallegro_ttf -lallegro_font -lallegro_primitives
FILES = entery.cpp BaseObj.cpp Player.cpp Stick.cpp
OUTFILE = picknSticks

build: $(FILES)
	$(C++) $(FILES) -o $(OUTFILE) $(LIBS)
