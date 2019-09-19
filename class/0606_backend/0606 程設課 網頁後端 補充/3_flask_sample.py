from flask import Flask, render_template
app = Flask(__name__)

@app.route('/')
def home():
    return "你的名子: <input name='your_name' type='text'>"
    # return render_template("0_form.html")

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=8080)

