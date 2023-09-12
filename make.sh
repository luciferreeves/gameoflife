echo "Creating build directory... (if it doesn't exist)"
mkdir -p build

echo "Removing old gameOfLife... (if it exists)"
rm -f build/gameOfLife

echo "Building gameOfLife..."
echo "C++ version: $(clang++ --version)"
echo "SDL2 version: $(sdl2-config --version)"

echo "Setting C++20 standard and libc++ as the standard library..."
echo "Including SDL2 headers from /opt/homebrew/include..."
echo "Linking SDL2 libraries from /opt/homebrew/lib..."

clang++ -std=c++20 -stdlib=libc++ src/gameOfLife.cpp -I/opt/homebrew/include -L/opt/homebrew/lib/ -lSDL2 -o build/gameOfLife

echo "gameOfLife built successfully"
