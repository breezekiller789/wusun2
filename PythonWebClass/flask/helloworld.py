from flask import Flask, request

app = Flask(__name__)

res = request.get('http://140.123.101.40:8888/courses.html')
print(res)

@app.route('/')
def hello_world():
    return '<h1>Hello World</h1>'

@app.route('/hi/<name>', methods = ['GET'])
def get_id(name):
    return 'hello {}'.format(name)

if __name__ == '__main__':
    app.run(port = 5000, debug = True)
