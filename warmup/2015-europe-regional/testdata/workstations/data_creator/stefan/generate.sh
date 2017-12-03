#!/bin/sh
problem=Logins
solution=Stefan

#cd to this file's location to make relative paths work
cd "$( cd "$(dirname "$0")" ; pwd -P )"

#compile
echo "compiling generator..."
javac ${problem}Generator*.java

#inputs
echo "generating .in files"
#hand-written: 01_nothing_saved, 02_only_one_machine, 03_not_sorted
java ${problem}GeneratorFullPQ 10 false false > ../../data/secret/04_fullPQ_n10.in
java ${problem}GeneratorFullPQ 100 false false > ../../data/secret/05_fullPQ_n100.in
java ${problem}GeneratorFullPQ 10 true false > ../../data/secret/06_fullPQ_n10_inverse.in
java ${problem}GeneratorFullPQ 100 true false > ../../data/secret/07_fullPQ_n100_inverse.in
java ${problem}GeneratorFullPQ 10 false true > ../../data/secret/08_fullPQ_n10_pop.in
java ${problem}GeneratorFullPQ 100 false true > ../../data/secret/09_fullPQ_n100_pop.in
java ${problem}GeneratorFullPQ 10 true true > ../../data/secret/10_fullPQ_n10_inverse_pop.in
java ${problem}GeneratorFullPQ 100 true true > ../../data/secret/11_fullPQ_n100_inverse_pop.in
for i in {12..21}
do
	n=15
	name=../../data/secret/${i}_random_n${n}
	java ${problem}GeneratorRandom $i $n 20 > $name.in
done
for i in {22..25}
	do
	n=50
	name=../../data/secret/${i}_random_n${n}
	java ${problem}GeneratorRandom $i $n 100 > $name.in
done
#Egor's test cases: 26_inTheMiddle, 27_inTheMiddle2, 28_inTheMiddle3, 29_allResearcherEqual,
#30_allResearcherEqualButTwo, 31_allResearcherEqualbutTwoOneSaved, 32_twoPartitions
cd ../egor
make -B
cd ../stefan
java ${problem}GeneratorFullPQ 300000 false false > ../../data/secret/33_fullPQ_n300000.in
java ${problem}GeneratorFullPQ 300000 true false > ../../data/secret/34_fullPQ_n300000_inverse.in
java ${problem}GeneratorFullPQ 300000 false true > ../../data/secret/35_fullPQ_n300000_pop.in
java ${problem}GeneratorFullPQ 300000 true true > ../../data/secret/36_fullPQ_n300000_inverse_pop.in
java ${problem}GeneratorMaxValues > ../../data/secret/37_maxValues.in
java ${problem}GeneratorMaxValues 2 > ../../data/secret/38_maxValues_2_groups.in
java ${problem}GeneratorMaxValues 4 > ../../data/secret/39_maxValues_4_groups.in
java ${problem}GeneratorMaxValues 10 > ../../data/secret/40_maxValues_10_groups.in
for i in {41..45}
do
	n=300000
	name=../../data/secret/${i}_random_n${n}
	java ${problem}GeneratorRandom $i $n 100000000 > $name.in
done
                                
#compile sample solution
echo "compiling sample solution..."
solutiondir=../../submissions/accepted
javac $solutiondir/$solution.java

#generate .ans outputs
for name in ../../data/*/*.in
do
	echo "solving file ${name%.in}..."
	cat $name | java -cp $solutiondir $solution > ${name%.in}.ans
done
