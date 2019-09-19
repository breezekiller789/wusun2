from flask import request, Flask
app = Flask(__name__)

@app.route('/', methods = ['GET'])
def hi():
    res = request.get('http://140.123.101.40:8888/courses.html')
    print(res)

if __name__ == "__main__":
    app.run()

