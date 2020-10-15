Playlist: MainDLL.o DLL.o DNode.o Playlist.o Song.o
	g++ MainDLL.o DLL.o DNode.o Playlist.o Song.o -o Playlist

MainDLL.o: MainDLL.cpp
	g++ -c MainDLL.cpp

DLL.o: DLL.cpp DLL.hpp
	g++ -c DLL.cpp

DNode.o: DNode.cpp DNode.hpp
	g++ -c DNode.cpp

Playlist.o: Playlist.cpp Playlist.hpp
	g++ -c Playlist.cpp

Song.o: Song.cpp Song.hpp
	g++ -c Song.cpp

clean:
	rm *.o Playlist
