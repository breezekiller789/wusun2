#!/usr/bin/python
#! -*- coding:utf-8 -*-
string = 'test<p>Hello World</p>end'

def find_word(source, start, end):
    x = source.find(start)
    y = source.find(end)
    x += len(start)
    print(source[x:y])
    print("x = {}, y = {}".format(x, y))

if __name__ == '__main__':
    find_word(string, "<p>", "</p>")
