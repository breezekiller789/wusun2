#!/usr/bin/env python
# -*- coding: utf-8 -*-

from flask import Flask
import requests
app = Flask(__name__)
# 字串擷取
def mid(source, start, end):
    n = source.find(start) + len(start)
    m = source[n:].find(end)
    return source[n:n+m]
#取得課表 http://127.0.0.1:8080/get_courses
@app.route('/get_courses')
def hello_world():
    res = requests.get('http://140.123.101.40:8888/courses.html')
    # print(res.text)
    res_list = res.text.split("</a></font></div></td></tr>") # 分割字串
    rList = []
    rTxt = ""
    for txt in res_list:
        a = mid(txt, '<td width="12%"><div align="center"><font size=2>', '</font>') # 系所
        b = mid(txt, '<td width="13%"><div align="center"><font size=2>', '</font>') # 課程 ID
        c = mid(txt, '''0', '', 'resizable=1,scrollbars=1,width=640,height=480');">''', '</a>') # 名稱
        d = mid(txt, '''1', '', 'resizable=1,scrollbars=1,width=640,height=480');">''', '</a>') # 教授
        e = mid(txt, '<td width="7%"><div align="center"><font size=2>', '</font>') # 學分
        f = mid(txt, 'width="5%"><div align="center"><font size=2>', '</font>') # 選必修
        g = mid(txt, '15%"><div align="center"><font size=2>', '</font>') # 時間
        rList.append(",".join([a, b, c, d, e, f, g, '<br>' ])) #把所以資料串成字串，丟進 rList 陣列
 # 過濾錯誤的資料
    for s in rList[2:-1]:
        rTxt += s
    # print(rList)
    # return rList[0]
    return rTxt
if __name__ == '__main__':
    app.run(host='localhost', port=8080, debug = True)
