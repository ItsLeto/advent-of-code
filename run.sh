if test -d bin; then
    echo
else
    mkdir bin
fi

g++ src/day_${1}.cpp -std=c++17 -o bin/day_${1}.out
./bin/day_${1}.out
