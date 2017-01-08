#!/usr/bin/python
import random
import cSort
import unittest

NO_ELEMENTS = 1000

def is_sorted(lst):
    for i in range(1, len(lst)):
        if lst[i] < lst[i-1]:
            return False
    return True


class TestSortPython(unittest.TestCase):

    def runTest(self):
        pass

    def setUp(self):
        self.sort_func = list.sort

    def test_00(self):
        '''Sort already sorted list of unique elements'''
        lst = range(NO_ELEMENTS)
        self.assertTrue(is_sorted(lst))
        self.sort_func(lst)
        self.assertTrue(is_sorted(lst))

    def test_01(self):
        '''Sort randomized list of elements: [0-9]{1}'''
        lst = []
        for i in range(NO_ELEMENTS):
            lst.append(random.randint(0, 9))
        self.assertFalse(is_sorted(lst))
        self.sort_func(lst)
        self.assertTrue(is_sorted(lst))

    def test_02(self):
        '''Sort randomized list of unique elements'''
        lst = range(NO_ELEMENTS)
        random.shuffle(lst)
        self.assertFalse(is_sorted(lst))
        self.sort_func(lst)
        self.assertTrue(is_sorted(lst))

    def test_03(self):
        '''Sort list with first and last elements switched'''
        lst = range(NO_ELEMENTS)
        lst[0], lst[-1] = lst[-1], lst[0]
        self.assertFalse(is_sorted(lst))
        self.sort_func(lst)
        self.assertTrue(is_sorted(lst))

    def test_03(self):
        '''Sort list with first at end of list'''
        lst = range(NO_ELEMENTS)
        tmp = lst.pop(0)
        lst.append(tmp)
        self.assertFalse(is_sorted(lst))
        self.sort_func(lst)
        self.assertTrue(is_sorted(lst))


class TestSortQuick(TestSortPython):
    def setUp(self):
        self.sort_func = cSort.quick

class TestSortMerge(TestSortPython):
    def setUp(self):
        self.sort_func = cSort.merge

class TestSortHeap(TestSortPython):
    def setUp(self):
        self.sort_func = cSort.heap

class TestSortBubble(TestSortPython):
    def setUp(self):
        self.sort_func = cSort.bubble


if __name__ == '__main__':
    unittest.main()

