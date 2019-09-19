from flask import Flask, render_template, request
app = Flask(__name__)

@app.route('/')
def home():
    return render_template("0_form.html")

@app.route('/get_name', methods=['GET'])
def get_name():
    name = request.args.get("your_name")
    return "Hello %s" % name


@app.route('/post_login', methods=['POST'])
def post_form():
    name = request.form.get("your_name")
    password = request.form.get("your_password")
    return "Hello %s <br> your password is %s" % (name, password)


if __name__ == '__main__':
    app.run(host='0.0.0.0', port=8080)

