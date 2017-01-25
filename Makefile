
all: test_sort cSort.so

cSort.so:
	python py_cSort_compile.py build_ext --inplace

test_sort:
	cc -o test_sort -std=gnu11 -lm test_sort.c

test: cSort.so test_sort
	./test_sort
	python test.py

clean:
	rm -r ./build
	rm test_sort
	rm cSort.so