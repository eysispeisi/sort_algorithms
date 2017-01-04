#!/usr/bin/python
import random
import time
import cSort
import os
import sys


n = 100000
base_list = range(n)
random.shuffle(base_list)

def is_sorted(lst):
    for i in range(1, len(lst)):
        if lst[i] < lst[i-1]:
            return False
    return True


def dotest(name, func):
    lst = base_list[:]
    print "%s: "%name,
    sys.stdout.flush()
    t = time.time()
    func(lst)
    td = time.time()-t
    s = is_sorted(lst)
    print "sorted=%d, runtime=%f" % (s, td)


tests = [
    ["list.sort()", list.sort],
    ["cSort.quick()", cSort.quick],
    ["cSort.merge()", cSort.merge],
    ["cSort.heap()", cSort.heap],
#    ["cSort.bubble()", cSort.bubble], # too slow to keep in active test
    ]


for name, func in tests:
    dotest(name, func)

