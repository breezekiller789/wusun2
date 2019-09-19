#!/usr/bin/env python
# -*- coding: utf-8 -*-


My_list = [1, 2, 3, 4, 5]
my_list = [9, 8, 7, 6, 5]

_my_dict = {
    'name': '柴魚',
    'age': 25
}

my_string = "最近因為重感冒的關係回到家幾乎都不會拿出電腦基本上就是洗澡躺床滑手機睡覺才發現偶爾過過廢物的生活也不錯阿(欸"


def Add_num(n1, n2=10):
    return n1 + n2


if __name__ == "__main__":
    # List
    print(My_list, my_list)

    # Dictionary
    print(_my_dict)
    print(_my_dict['name'], _my_dict.get("age"))

    # String
    print(len(my_string))
    print(my_string[4:7])

    # Function
    print(Add_num(2, 3))
    print(Add_num(9))
