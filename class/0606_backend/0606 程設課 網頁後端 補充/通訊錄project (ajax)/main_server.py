from flask import Flask, render_template, request
import uuid
import json

ContactList = []  # 全域的聯絡人列表
app = Flask(__name__)


@app.route('/')  # 首頁 Flask 預設路徑 templates 資料夾
def index():
   return render_template('form.html')


# POST 新增聯絡人
@app.route('/add', methods=['POST'])  # TODO request.form  會保存 POST 表單   print(request.form)
def add_contact():
    data = request.form.to_dict()
    if data:
        if data.get("name", False) and data.get("phone", False) and data.get("address", False):
            data['uid'] = str(uuid.uuid4())  # uuid1=時間戳  uuid2=POSIX UID  uuid3=名子MD5  uuid4=隨機數  uuid5=名子SHA-1
            ContactList.append(data)
            return json.dumps({'msg': True})
        return json.dumps({'msg': False})
    else:
        return json.dumps({'msg': False})


# GET 查詢聯絡人
@app.route('/search', methods=['GET'])  # TODO request.args  裡面會保存 GET 傳進來的參數  可以用 request.args.get('名稱') 取值   print(request.args)
def search_contact():
    field = request.args.get('field')
    value = request.args.get('value')
    match_list = []
    if value:
        for data in ContactList:
            if data.get(field, False) == value or value == "*":
                match_list.append(data)
        return json.dumps(match_list)
    else:
        return json.dumps(match_list)


# PUT 更新聯絡人
@app.route('/update', methods=['PUT'])  # TODO 跟 POST一樣資料放在 Form裡面
def update_contact():
    new_data = request.form.to_dict()
    if new_data:
        if new_data.get("name", False) and new_data.get("phone", False) and new_data.get("address", False) and new_data.get("uid", False):
            for index, old_data in enumerate(ContactList):
                if old_data.get("uid") == new_data.get("uid"):
                    ContactList[index] = new_data
            return json.dumps({'msg': True})
        return json.dumps({'msg': False})
    else:
        return json.dumps({'msg': False})


# DELETE 刪除聯絡人(uid)
@app.route('/delete', methods=['DELETE'])  # TODO 跟 GET 一樣參數放在  request.args
def delete_contact():
    uid = request.args.get('uid')
    if uid:
        for index, data in enumerate(ContactList):
            if data.get("uid") == uid:
                ContactList.pop(index)
                return json.dumps({'msg': True})
    return json.dumps({'msg': False})


# TODO Run Server
if __name__ == '__main__':
    app.run(host='0.0.0.0', port=8080)

