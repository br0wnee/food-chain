# Czym jest Raylib

Link:
- [Raylib](https://www.raylib.com)
Raylib to prosta i łatwa w użyciu biblioteka oparta na licencji zlib (Open-Source, dowolne wykorzystanie - również komercyjne) napisana w C
 umożliwiająca budowanie aplikacji graficznych (np. gry) na różne platformy (Windows, Unix, WebAssembly, Android itd.).

# Jak wykorzystać bibliotekę Raylib w swoich projektach

Mimo tego, że biblioteka napisana jest w C mamy możliwość korzystania z wielu języków z racji na budowane i wspierane przez społeczność
tzw. bindings do różnych języków (C++, Rust, Go itd.). W tym materiale skupimy się głównie na wykorzystaniu jej z C++ (bez wykorzystania wspomnianych bindingów).
Nie będziemy opierać się na żadnym IDE (z ang. Integrated Development Enviroment) tak aby pozostawić dowolność dla użytkownika.

# Pierwszy krok: Pobranie biblioteki

Z racji, że korzystamy z C++ nie mamy prostego dostępu do swego rodzaju menedżera pakietów jak w przypadku np. języka Python musimy pobrać     
potrzebne pliki oraz sprawić, że są dostępne dla naszego kompilatora. Sprawa wygląda znacznie prościej jeżeli będziemy korzystać z systemu GNU/Linux
(np. Fedora), ponieważ wystarczy zainstalowanie biblioteki i dodatkowych pakietów za pomocą odpowiedniego dla dystrybucji menedżera i biblioteka będzie juz dostępna. 

UWAGA: Dla użytkowników Windows, jest możliwość wykorzystania WSL (z ang. Windows Subsystem for Linux), jednakże na dzień pisania tego README występują problemy związane z
z "wirtualizacją" GPU - dlatego wykorzystanie tej metody do zaawansowanych aplikacji wykorzystujących np. grafikę 3D możemy mieć kłopoty z wydajnością. Do prostych aplikacji 2D
jest to rozwiązanie wystarczające.

   
