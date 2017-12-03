#!/bin/sh
problem=Logins

#cd to this file's location to make relative paths work
cd "$( cd "$(dirname "$0")" ; pwd -P )"

#compile
echo "compiling visualizer..."
javac ${problem}Visualizer.java

#generate images
for name in ../../data/*/*.in
do
	declare -i n=$(sed -n -e 's/\s.*$//' -e 1p $name)
	if [ $n -lt 100000 ]
	then
		echo "visualizing file ${name%.in}..."
		cat $name | java -Xmx4g ${problem}Visualizer > ${name%.in}.png
	fi
done
