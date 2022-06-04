g++ -std=c++17 -Wall -Wextra -c main.cpp -o main.o -I"../../../include"
g++ -std=c++17 -Wall -Wextra -c Context.cpp -o Context.o  -I"../../../include"
g++ -std=c++17 -Wall -Wextra -c Game.cpp -o Game.o  -I"../../../include"
g++ -std=c++17 -Wall -Wextra -c Perso.cpp -o Perso.o  -I"../../../include"
g++ -std=c++17 -Wall -Wextra -c utilities.cpp -o utilities.o  -I"../../../include"
g++ -std=c++17 -Wall -Wextra -c Background.cpp -o Background.o  -I"../../../include"
g++ -std=c++17 -Wall -Wextra -c Foreground.cpp -o Foreground.o  -I"../../../include"
g++ -std=c++17 -Wall -Wextra -c Lvl.cpp -o Lvl.o -I"../../../include"
g++ -std=c++17 -Wall -Wextra -c Vector.cpp -o Vector.o  -I"../../../include"
g++ -std=c++17 -Wall -Wextra -c Input.cpp -o Input.o  -I"../../../include"
g++ -std=c++17 -Wall -Wextra -c Grid.cpp -o Grid.o  -I"../../../include"
g++ -std=c++17 -Wall -Wextra -c Tileset.cpp -o Tileset.o  -I"../../../include"

g++ -std=c++17 -Wall -Wextra main.o Context.o Game.o Perso.o utilities.o Background.o Foreground.o Lvl.o Vector.o Input.o Grid.o Tileset.o -o ../exec/dream.exe -L"../../../libs" -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

cd ../exec/    # il faut les dll dans le répertoire courrant pour executer dream.exe

dream.exe

cd ../src/

set /p nothing=
