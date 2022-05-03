## Uruchamianie Programu
 * Aby móc poprawnie skompilować program należy najpierw stworzyć katalog build, o ile go nie ma, a następnie użyć programu cmake poleceniem `cmake ..` do stworzenia pliku makefile w katalogu `build/`.
 * Następnie należy użyć Makefile poleceniem `make`, aby skompilować program po wcześniejszym poprawnym stworzeniu pliku `Makefile` z pomocą cmake w katalogu `build/`. 
 * Po poprawnym skompilowaniu, aby uruchomić program, należy użyć polecenia `./main` w katalogu `build/`.

## Uruchamianie Testów Programu
 * Testy jednostkowe programu uruchamiają się po wpisaniu do terminala `./unit_tests` po poprawnej kompilacji z użyciem pliku Makefile w katalogu `build/`.

## Generowanie dokumentacji w Doxygen
 * Aby wygenerować pliki dokumentacji Doxygen, w postaci HTML, należy skorzystać z pliku konfiguracyjnego `Doxyfile.in` znajdującego się w głównym katalogu repozytorum. Aby to zrobić, należy skorzystać z polecenia `doxygen Doxyfile.in` w głównym katalogu repozytorium. Wygenerowane pliki będą znajdowały się w katalogu `dox/`. Do wygenerowania dokumentacji można również skorzystać z kreatora doxywizard lub cmake poleceniem `doxygen` w katalogu `build/`. 

## Wcześniej wygenerowana dokumentacja
 * Repozytorum posiada wcześniej wygenerowane najaktualniejsze pliki dokumentacji w katalogu `dox/`. Aby uruchomić stronę główną dokumetnacji należy uruchomić plik `./dox/html/index.html`

## Building
Build by making a build directory (i.e. `build/`), run `cmake` in that dir, and then use `make` to build the desired target.

Requirements: cmake, gnuplot, doxygen + dot

Example:

``` bash
> mkdir build && cd build
> cmake .. # options: -DCMAKE_BUILD_TYPE=[Debug | Coverage | Release], Debug is default
> make
> ./main
> make test      # Makes and runs the tests.
> make coverage  # Generate a coverage report.
> make doc       # Generate html documentation.
```

Things to remember:
* changes to zad3/CMakeLists.txt with new files added, i.e.:
```cpp
# --------------------------------------------------------------------------------
#                         Locate files (change as needed).
# --------------------------------------------------------------------------------
set(SOURCES          # All .cpp files in src/
    src/lacze_do_gnuplota
    src/Matrix2x2.cpp
    src/Rectangle .cpp
    src/Vector2D.cpp
)
set(TESTFILES        # All .cpp files in tests/
    Vector2D.cpp
    Matrix2x2.cpp
    Rectangle.cpp
)
set(LIBRARY_NAME zad3)  # Default name for the library built from src/*.cpp (change if you wish)
```
* changes to zad3/tests/CMakeLists.txt with new files added, i.e.:
```cpp
# List all files containing tests. (Change as needed)
set(TESTFILES        # All .cpp files in tests/
    main.cpp
    Wektor2D.cpp
    Macierz2x2.cpp
    Prostokat.cpp
)
```
The `main.cpp` in the folder `tests` is needed. Only there we define `#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN`.

The main loop of the program is in the `app` folder.

