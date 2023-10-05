const http = require('http');
const url = require('url');
let fs = require("fs");

const server = http.createServer((req, res) => {
    const query = url.parse(req.url, true).query; //парсинг параметров, затем их получение

    if (req.url.startsWith('/fact')) {
        const k = parseInt(query.k);         // получаем параметр k и преобразуем в число

        if (!isNaN(k)) {
            calculateFactorial(k, (result) => {
                res.writeHead(200, {'Content-Type':'application/json'});
                res.end(result.toString());
            });


        } else {//выводим стариницу праметр x
            res.writeHead(200, { "Content-type": "text/html" });
            let text = fs.readFileSync("./03-03.html");
            res.end(text);
        }


    } else
    {
        res.writeHead(400, { 'Content-Type': 'text/plain' });
        res.end('Error');
    }
}).listen(5000);

function calculateFactorial(n, callback) {
    if (n === 0) {
        setImmediate(() => {
            callback(1);
        });
        return;
    }

    calculateFactorial(n - 1, (result) => {
        setImmediate(() => {
            callback(n * result);
        });
    });
}

console.log('http://localhost:5000/fact?k=x');