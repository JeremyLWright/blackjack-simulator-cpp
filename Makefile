DOC_SRCS=$(wildcard doc/doxygen/*)
LECTURE_SRCS=$(wildcard doc/lecture/*.html)
LECTURE_MEDIA=$(wildcard doc/media/*)
LECTURE_IMG=$(wildcard doc/img/*)

all: dist/fall2013/index.html webroot

.PHONY: webroot

webroot:
	cp -au doc/webroot/* dist

dist/fall2013/index.html: $(DOC_SRCS)
	doxygen util/Doxyfile

deploy: dist/fall2013/index.html webroot
	rsync -avz -e ssh dist/*  jlwrigh1@general.asu.edu:www


clean:
	rm -rf dist/*

