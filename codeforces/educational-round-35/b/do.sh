#!/bin/zsh

g++ t.cpp -std=c++11 -o a.out
if [[ $1 != "p" ]]; then
    g++ -std=c++11 t2.cpp -o a2.out
fi
echo "" > dif

while read a; do
    if [[ $1 == "p" ]]; then
        python3 t.py <<< "$a" > out
    else
        ./a2.out <<< "$a" > out
    fi
    ./a.out <<< "$a" > out2
    dif=$(diff --ignore-all-space out2 out)
    if [[ "$dif" != "" ]]; then
        echo "$dif $a";
        exit 0;
    fi
done < in

cat dif | head -n 2
