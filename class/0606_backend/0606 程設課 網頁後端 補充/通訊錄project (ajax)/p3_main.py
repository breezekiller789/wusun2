from flask import Flask, render_template, request
app = Flask(__name__)


@app.route('/')  # 首頁 Flask 預設路徑 templates 資料夾
def index():
   return render_template('p3_form.html')


# 取得 GET 表單
@app.route('/get_name', methods=['GET'])
def get_hello():
    # TODO request.args  裡面會保存 GET 傳進來的參數  可以用 request.args.get('名稱') 取值   print(request.args)

    name = request.args.get("your_name")

    return "<h1> Hello %s </h1>" % name


# 取得 POST 表單
@app.route('/post_login', methods=['POST'])
def post_hello():
    # TODO request.form  會保存 POST 表單   print(request.form)

    name = request.form.get("your_name")
    password = request.form.get("your_password")

    return "<h1> Hello %s  <br> <p>your password = %s </p> </h1>" % (name, password)


if __name__ == '__main__':
    app.run(host='0.0.0.0', port=8080)


