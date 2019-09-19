from flask import Flask, render_template, request
app = Flask(__name__)

@app.route('/')
def home():
    my_list = ['A', 'BB', 'CCC', 'DDDD']
    return render_template("1_jinja.html", name="我的名子", item_list=my_list)

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=8080)

