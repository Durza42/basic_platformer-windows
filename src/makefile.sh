    # You can run this file to compile and run the game, if you are on Linux 64 and you have already installed g++ and the SDL2 library.
    # Later, a newer version will pre-compile this game; so you'll not need tp install all libraries.
    # But right now, it's sadly necessary. We're sorry for this...

echo \#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#
echo building \'dream\' for 64 bits GNU/Linux.
echo \#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#

echo

echo \#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#
echo compiling files...
echo \#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#

echo

g++ -std=c++17 -Wall -Wextra -c main.cpp -o main.o 
g++ -std=c++17 -Wall -Wextra -c Context.cpp -o Context.o 
g++ -std=c++17 -Wall -Wextra -c Game.cpp -o Game.o 
g++ -std=c++17 -Wall -Wextra -c Perso.cpp -o Perso.o 
g++ -std=c++17 -Wall -Wextra -c utilities.cpp -o utilities.o 
g++ -std=c++17 -Wall -Wextra -c Background.cpp -o Background.o 
g++ -std=c++17 -Wall -Wextra -c Foreground.cpp -o Foreground.o 
g++ -std=c++17 -Wall -Wextra -c Lvl.cpp -o Lvl.o
g++ -std=c++17 -Wall -Wextra -c Vector.cpp -o Vector.o 
g++ -std=c++17 -Wall -Wextra -c Input.cpp -o Input.o 
g++ -std=c++17 -Wall -Wextra -c Grid.cpp -o Grid.o 
g++ -std=c++17 -Wall -Wextra -c Tileset.cpp -o Tileset.o 

echo \#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#
echo all files compiled.
echo linking...
echo \#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#

echo

g++ -std=c++17 -Wall -Wextra main.o Context.o Game.o Perso.o utilities.o Background.o Foreground.o Lvl.o Vector.o Input.o Grid.o Tileset.o -o ../exec/dream.elf `sdl2-config --libs` -lSDL2_image -lSDL2_mixer

rm Background.o Context.o Foreground.o Game.o Grid.o Input.o Lvl.o main.o Perso.o Tileset.o utilities.o Vector.o

echo \#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#
echo all files linked.
echo exec...
echo \#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#

echo

cd ../exec/    # il faut les dll dans le répertoire courrant pour executer dream.exe

echo ----------------
file dream.elf
echo ----------------

./dream.elf
cd ../src/
