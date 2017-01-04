#!/bin/sh
python py_cSort_compile.py build
cp build/lib.linux-armv7l-2.7/cSort.so .
python test.py
