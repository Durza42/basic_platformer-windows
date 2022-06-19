    # You can run this file to compile and run the game, if you are on Linux 64 and you have already installed g++ and the SDL2 library.
    # Later, a newer version will pre-compile this game; so you'll not need to install all libraries.
    # But right now, it's sadly necessary. We're sorry for this...

echo \#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#
echo building editor for 64 bits GNU/Linux.
echo \#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#

echo

echo \#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#
echo compiling files...
echo \#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#

echo

g++ -std=c++17 -Wall -Wextra -c main.cpp -o main.o 
g++ -std=c++17 -Wall -Wextra -c Context.cpp -o Context.o 
g++ -std=c++17 -Wall -Wextra -c Game.cpp -o Game.o 
g++ -std=c++17 -Wall -Wextra -c Input.cpp -o Input.o 
g++ -std=c++17 -Wall -Wextra -c utilities.cpp -o utilities.o 
g++ -std=c++17 -Wall -Wextra -c Top_menu.cpp -o Top_menu.o
g++ -std=c++17 -Wall -Wextra -c Grid.cpp -o Grid.o
g++ -std=c++17 -Wall -Wextra -c Tileset.cpp -o Tileset.o
g++ -std=c++17 -Wall -Wextra -c Loader.cpp -o Loader.o

echo \#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#
echo all files compiled.
echo linking...
echo \#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#

echo

g++ -std=c++17 -Wall -Wextra main.o Context.o Game.o Input.o utilities.o Top_menu.o Grid.o Tileset.o Loader.o -o ../exec/editor.elf `sdl2-config --libs` -lSDL2_image -lSDL2_mixer

rm Context.o Game.o Input.o main.o utilities.o Top_menu.o Grid.o Tileset.o Loader.o

echo \#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#
echo all files linked.
echo exec...
echo \#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#

echo

cd ../exec/    # il faut les dll dans le répertoire courrant pour executer dream.exe

echo ----------------
file editor.elf
echo ----------------

./editor.elf
cd ../src/
