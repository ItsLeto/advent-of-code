if test -d bin; then
    echo
else
    mkdir bin
fi

g++ src/aoc${1}.cpp -std=c++17 -o bin/aoc${1}.out
./bin/aoc${1}.out
