CXXFLAGS += -std=c++11 -O2

all: visualize $(patsubst %.in,%.png,$(wildcard sample/*.in) $(wildcard secret/*.in))

%.png: %.in
	./visualize < $< > tmp.svg
	inkscape tmp.svg --export-background=white --export-png=$@
	rm tmp.svg
