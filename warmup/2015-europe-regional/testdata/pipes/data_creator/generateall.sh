#!/bin/bash

g++ -O2 generate_pipes.cpp -o gen1
g++ -O2 generate_pipes2.cpp -o gen2
g++ -O2 generate_pipes3.cpp -o gen3
g++ -O2 ../submissions/accepted/pipes.cpp -o sol

echo 10 20 42 1 | ./gen1 | tee ../data/secret/05-random_small_succ.in | ./sol > ../data/secret/05-random_small_succ.ans
echo 05
echo 10 20 43 1 | ./gen1 | tee ../data/secret/06-random_small_succ.in | ./sol > ../data/secret/06-random_small_succ.ans
echo 06
echo 10 20 44 1 | ./gen1 | tee ../data/secret/07-random_small_succ.in | ./sol > ../data/secret/07-random_small_succ.ans
echo 07
echo 10 20 42 0 | ./gen1 | tee ../data/secret/08-random_small_fail.in | ./sol > ../data/secret/08-random_small_fail.ans
echo 08
echo 10 20 43 0 | ./gen1 | tee ../data/secret/09-random_small_fail.in | ./sol > ../data/secret/09-random_small_fail.ans
echo 09
echo 10 20 44 0 | ./gen1 | tee ../data/secret/10-random_small_fail.in | ./sol > ../data/secret/10-random_small_fail.ans
echo 10

echo 1000 1000 52 0  | ./gen1 | tee ../data/secret/11-random_both_large_fail.in | ./sol > ../data/secret/11-random_both_large_fail.ans
echo 11
echo 1000 1000 53 0  | ./gen1 | tee ../data/secret/12-random_both_large_fail.in | ./sol > ../data/secret/12-random_both_large_fail.ans
echo 12
echo 1000 1000 54 0  | ./gen1 | tee ../data/secret/13-random_both_large_fail.in | ./sol > ../data/secret/13-random_both_large_fail.ans
echo 13
echo 1000 1000 52 1  | ./gen1 | tee ../data/secret/14-random_both_large_succ.in | ./sol > ../data/secret/14-random_both_large_succ.ans
echo 14
echo 1000 1000 54 1  | ./gen1 | tee ../data/secret/15-random_both_large_succ.in | ./sol > ../data/secret/15-random_both_large_succ.ans
echo 15
echo 1000 1000 57 1  | ./gen1 | tee ../data/secret/16-random_both_large_succ.in | ./sol > ../data/secret/16-random_both_large_succ.ans
echo 16

echo 100 1000 66 1  | ./gen1 | tee ../data/secret/17-random_manypipes_succ.in | ./sol > ../data/secret/17-random_manypipes_succ.ans
echo 17
echo 100 1000 67 1  | ./gen1 | tee ../data/secret/18-random_manypipes_succ.in | ./sol > ../data/secret/18-random_manypipes_succ.ans
echo 18
echo 100 1000 66 0  | ./gen1 | tee ../data/secret/19-random_manypipes_fail.in | ./sol > ../data/secret/19-random_manypipes_fail.ans
echo 19
echo 100 1000 67 0  | ./gen1 | tee ../data/secret/20-random_manypipes_fail.in | ./sol > ../data/secret/20-random_manypipes_fail.ans
echo 20

echo 100 1000 62 1 900 | ./gen2 | tee ../data/secret/21-random_longerpipes_succ.in | ./sol > ../data/secret/21-random_longerpipes_succ.ans
echo 21
echo 100 1000 64 1 1000 | ./gen2 | tee ../data/secret/22-random_longerpipes_succ.in | ./sol > ../data/secret/22-random_longerpipes_succ.ans
echo 22
echo 100 1000 62 0 900 | ./gen2 | tee ../data/secret/23-random_longerpipes_fail.in | ./sol > ../data/secret/23-random_longerpipes_fail.ans
echo 23
echo 100 1000 63 0 900 | ./gen2 | tee ../data/secret/24-random_longerpipes_fail.in | ./sol > ../data/secret/24-random_longerpipes_fail.ans
echo 24


echo 100 1000 82 0 3000 | ./gen2 | tee ../data/secret/25-random_verylongpipes_fail.in | ./sol > ../data/secret/25-random_verylongpipes_fail.ans
echo 25
echo 100 1000 83 0 3000 | ./gen2 | tee ../data/secret/26-random_verylongpipes_fail.in | ./sol > ../data/secret/26-random_verylongpipes_fail.ans
echo 26
