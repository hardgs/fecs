@echo off
set inc=./include/
set ex=./examples/
mkdir build 

rem First Build Library
gcc -c src/list.c -o build/list -I %inc%
gcc -c src/map.c -o build/map -I %inc%
gcc -c src/vector.c -o build/vector -I %inc%
gcc -c src/matrix4x4.c -o build/matrix4x4 -I %inc%
gcc -c src/socket.c -o build/socket -I %inc%
gcc -c src/http-request.c -o build/http-request -I %inc%
gcc -c src/csv-read.c -o build/csv-read -I %inc%

rem Now Build Examples
gcc %ex%list-ex.c build/list -o ListExample -I %inc%
gcc %ex%map-ex.c build/map build/list -o Map -I %inc%
gcc %ex%vector-ex.c build/vector -o Vector -I %inc%
gcc %ex%matrix4x4-ex.c build/matrix4x4 build/vector -o Matrix -I %inc%
gcc %ex%socket-ex.c build/socket -o Socket -lws2_32 -I %inc%
gcc %ex%http-request-ex.c build/http-request build/map build/list build/socket -o HttpRequest -lws2_32 -I %inc%
gcc %ex%show-asci.c -o ShowAsci
gcc %ex%csv-read-ex.c build/csv-read build/list -o CSVRead -I %inc%

rem Clean
del build /Q
move *.exe build/
copy basic.csv build/basic.csv
pause