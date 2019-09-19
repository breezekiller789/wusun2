"""
TODO 通訊錄功能測試
"""

import uuid

ContactList = []  # 全域的聯絡人列表


# TODO 新增聯絡人
def add_contact(data={}):
    '''傳入格式  (Dict)  自動新增UUID
    {
        "name": "Jeff",
        "phone": "0900123456",
        "address": "中正大學"
    }
    '''
    if data:
        if data.get("name", False) and data.get("phone", False) and data.get("address", False):
            data['uid'] = str(uuid.uuid4())  # uuid1=時間戳  uuid2=POSIX UID  uuid3=名子MD5  uuid4=隨機數  uuid5=名子SHA-1
            ContactList.append(data)
            return True
        return False
    else:
        return False


# TODO 查詢聯絡人
def search_contact(field="phone", value=""):
    print("SELECT * FROM ContactList WHERE %s=%s", (field, value))
    match_list = []
    if value:
        for data in ContactList:
            if data.get(field, False) == value or value == "*":
                match_list.append(data)
        return match_list
    else:
        return match_list


# TODO 更新聯絡人  (限定匹配UUID)
def update_contact(new_data={}):
    if new_data:
        if new_data.get("name", False) and new_data.get("phone", False) and new_data.get("address", False) and new_data.get("uid", False):
            for index, old_data in enumerate(ContactList):
                if old_data.get("uid") == new_data.get("uid"):
                    ContactList[index] = new_data
            return True
        return False
    else:
        return False


# TODO 刪除聯絡人  (限定匹配UUID)
def delete_contact(uid=""):
    if uid:
        for index, data in enumerate(ContactList):
            if data.get("uid") == uid:
                ContactList.pop(index)
                return True
    return False


if __name__ == "__main__":
    # TODO 插入資料
    add_contact({
        "name": "Jeff",
        "phone": "0900123456",
        "address": "中正大學"
    })
    add_contact({
        "name": "PDTA",
        "phone": "0966666666",
        "address": "GAISlab"
    })
    add_contact({
        "name": "Julia",
        "phone": "0987654321",
        "address": "AAAAAAAAAAAAA"
    })
    add_contact({
        "name": "清心",
        "phone": "+886945878787",
        "address": "嘉義縣民雄鄉民權路3-20號"
    })
    add_contact({
        "name": "Tsai Da Fa",
        "phone": "0905690887",
        "address": "高譚市"
    })
    add_contact({
        "name": "アンコール",
        "phone": "0987987987",
        "address": "高譚市"
    })

    # TODO 搜尋資料
    print(search_contact("name", "Jeff"), "\n----------------")
    print(search_contact("phone", "0987654321"), "\n----------------")
    print(search_contact("address", "高譚市"), "\n----------------")
    print(search_contact("name", "*"), "\n----------------")

    # TODO 更新資料 (先找要更新的資料，修改欄位，更新，在查詢一次看有沒有更新)
    print("----------更新資料-----------")
    jeff_data = search_contact("name", "Jeff")[0]
    print(jeff_data)
    jeff_data['address'] = "新的地址ㄛ"
    update_contact(jeff_data)
    jeff_data = search_contact("name", "Jeff")[0]
    print(jeff_data)

    # TODO 刪除資料 (先找要更新的資料，抓出 uid 欄位，刪除指定 uid，在查詢一次看有沒有不見)
    print("----------刪除資料-----------")
    del_data = search_contact("phone", "0905690887")[0]
    print(del_data)
    uid = del_data.get("uid")
    delete_contact(uid)
    del_data = search_contact("phone", "0905690887")
    print(del_data)


