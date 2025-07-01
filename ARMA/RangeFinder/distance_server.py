from flask import Flask, Response

app = Flask(__name__)

@app.route('/')
def home():
    return "Serwer działa. Wejdź na /data, by zobaczyć zawartość pliku."

@app.route('/data')
def data():
    try:
        with open(r"C:\Users\Tom\Desktop\armaRangefinderTest\arma_distance.txt", 'r', encoding='utf-8') as f:
            content = f.read()
        return Response(content, mimetype='text/plain')
    except FileNotFoundError:
        return "Plik nie został znaleziony.", 404
    except Exception as e:
        return f"Wystąpił błąd: {e}", 500

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
