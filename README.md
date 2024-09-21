# Czym jest Raylib

[Raylib](https://www.raylib.com) to prosta i łatwa w użyciu biblioteka oparta na licencji zlib (Open-Source, dowolne wykorzystanie - również komercyjne) napisana w C umożliwiająca budowanie aplikacji graficznych (np. gry) na różne platformy (Windows, Unix, WebAssembly, Android itd.).

# Jak wykorzystać bibliotekę Raylib w swoich projektach

Mimo tego, że biblioteka napisana jest w C mamy możliwość korzystania z wielu języków z racji na budowane i wspierane przez społeczność tzw. bindingów lub wrapperów do różnych języków (C++, Rust, Go itd.). W tym materiale skupimy się głównie na wykorzystaniu jej z C++ (bez wykorzystania wspomnianych bindingów).

Nie będziemy opierać się na żadnym IDE (z ang. Integrated Development Enviroment) tak aby pozostawić dowolność użytkownikowi w wyborze jego środowiska.

# Krok 0: Wstęp 

Z racji, że korzystamy z C++ nie mamy prostego dostępu do swego rodzaju natywnego menedżera pakietów jak w przypadku np. języka Python musimy pobrać potrzebne pliki oraz sprawić, że są dostępne dla naszego kompilatora i linkera. Sprawa wygląda znacznie prościej jeżeli będziemy korzystać z dystrybucji Linux (np. Fedora, Ubuntu), ponieważ wystarczy zainstalowanie biblioteki i dodatkowych pakietów za pomocą odpowiedniego dla dystrybucji menedżera i biblioteka będzie juz dostępna. 

UWAGA: Dla użytkowników Windows, jest możliwość wykorzystania WSL (z ang. Windows Subsystem for Linux), jednakże na dzień pisania tego README występują problemy związane z "wirtualizacją" GPU - dlatego wykorzystanie tej metody do zaawansowanych aplikacji wykorzystujących np. grafikę 3D możemy mieć kłopoty z wydajnością. Do prostych aplikacji 2D jest to rozwiązanie wystarczające.

# Fedora

## Krok 1: Pobranie pakietów deweloperskich
Pakiety systemowe
```
sudo dnf groupinstall "Development Tools" "Development Libraries"
```
Pakiety specyficzne dla Raylib

```
sudo dnf install alsa-lib-devel mesa-libGL-devel libX11-devel libXrandr-devel libXi-devel libXcursor-devel libXinerama-devel libatomic
```
## Krok 2: Pobranie biblioteki Raylib

Należy pobrać zarówno pakiet deweloperski jak i pakiet pozwalający na uruchamianie aplikacji pisanych z tą biblioteką 

```
sudo dnf install raylib raylib-devel
```

## Krok 3: Utworzenie skryptu do kompilacji i linkowania

Aby wykorzystać bibliotekę Raylib musimy jasno powiedzieć naszemu kompilatorowi (w tym przypadku g++ z zestawu GCC) co musi dokładnie zrobić.

Utwórzmy zatem katalog (folder) w którym zaczniemy nasz projekt i do niego wejdźmy

```
mkdir nazwa-projektu
cd nazwa-projektu
```

Następnie utwórzmy kolejno następny katalog gdzie będziemy trzymać pliki źródłowe

```
mkdir src
```
oraz stwórzmy skrypt do kompilacji

```
touch build.sh
```

Należy teraz zedytować skrypt za pomocą edytora tekstu (np. VS Code lub Nano)

```
nano build.sh
```
W pliku należy wpisać następującą linijkę
```