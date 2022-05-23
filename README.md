## Uruchamianie Programu
 * Aby móc poprawnie skompilować program należy najpierw stworzyć katalog build, o ile go nie ma, a następnie użyć programu cmake poleceniem `cmake ..` do stworzenia pliku makefile w katalogu `build/`.
 * Następnie należy użyć Makefile poleceniem `make`, aby skompilować program po wcześniejszym poprawnym stworzeniu pliku `Makefile` z pomocą cmake w katalogu `build/`. 
 * Po poprawnym skompilowaniu, aby uruchomić program, należy użyć polecenia `./main` w katalogu `build/`.

Wymagane: cmake.

Główna pętla programu znajduje się w katalogu `\app`, pliki nagłówków w `\inc`, a pliki źródłowe w `\src`

## Building
Build by making a build directory (i.e. `build/`), run `cmake` in that dir, and then use `make` to build the desired target.
