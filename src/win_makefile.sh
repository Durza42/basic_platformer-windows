echo \#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#
echo building \'dream\' for 32 / 64 bits MS Windows.
echo \#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#

echo

echo \#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#
echo compiling files...
echo \#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#

echo

x86_64-w64-mingw32-g++ -std=c++17 -Wall -Wextra -c main.cpp -o main.o -I/home/durza42/programing/includes
x86_64-w64-mingw32-g++ -std=c++17 -Wall -Wextra -c Context.cpp -o Context.o -I/home/durza42/programing/includes
x86_64-w64-mingw32-g++ -std=c++17 -Wall -Wextra -c Game.cpp -o Game.o -I/home/durza42/programing/includes
x86_64-w64-mingw32-g++ -std=c++17 -Wall -Wextra -c Perso.cpp -o Perso.o -I/home/durza42/programing/includes
x86_64-w64-mingw32-g++ -std=c++17 -Wall -Wextra -c utilities.cpp -o utilities.o -I/home/durza42/programing/includes
x86_64-w64-mingw32-g++ -std=c++17 -Wall -Wextra -c Background.cpp -o Background.o -I/home/durza42/programing/includes
x86_64-w64-mingw32-g++ -std=c++17 -Wall -Wextra -c Foreground.cpp -o Foreground.o -I/home/durza42/programing/includes
x86_64-w64-mingw32-g++ -std=c++17 -Wall -Wextra -c Lvl.cpp -o Lvl.o -I/home/durza42/programing/includes
x86_64-w64-mingw32-g++ -std=c++17 -Wall -Wextra -c Vector.cpp -o Vector.o -I/home/durza42/programing/includes
x86_64-w64-mingw32-g++ -std=c++17 -Wall -Wextra -c Input.cpp -o Input.o -I/home/durza42/programing/includes
x86_64-w64-mingw32-g++ -std=c++17 -Wall -Wextra -c Grid.cpp -o Bloc.o -I/home/durza42/programing/includes
x86_64-w64-mingw32-g++ -std=c++17 -Wall -Wextra -c Tileset.cpp -o Tileset.o -I/home/durza42/programing/includes

echo

echo \#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#
echo all files compiled.
echo linking...
echo \#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#

echo

x86_64-w64-mingw32-g++ -std=c++17 -Wall -Wextra main.o Context.o Game.o Perso.o utilities.o Background.o Foreground.o Lvl.o Vector.o Input.o Grid.o Tileset.o -o ../exec/dream.exe   -I/home/durza42/programing/includes -L/home/durza42/programing/libs  `sdl2-config --libs` -lSDL2_image -lSDL2_mixer -lssp -lstdc++

echo

echo \#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#
echo all files linked.
echo exec...
echo \#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#

cd ../exec/    # il faut les dll dans le répertoire courrant pour executer dream.exe

echo
echo ----------------
file dream.exe
echo ----------------

wine dream.exe
cd ../src/
