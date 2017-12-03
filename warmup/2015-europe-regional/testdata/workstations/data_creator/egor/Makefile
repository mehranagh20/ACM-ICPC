

JAVAC=javac
JAVA=java
sources = $(wildcard *.java)
classes = $(sources:.java=.class)
CP = .:../../../../libs/testcasecreator/testcasecreator.jar

SAMPLES = ../../data/sample
SECRET = ../../data/secret

all: $(classes) create

clean :
	rm -f *.class

%.class : %.java
	$(JAVAC) -cp $(CP) $<

create : $(classes)
#	rm $(SECRET)/*
	$(JAVA) -cp $(CP) LoginsTool SECRET $(SECRET)

