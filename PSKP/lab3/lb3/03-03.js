const http = require('http');
const url = require('url');
let fs = require("fs");

const server = http.createServer((req, res) => {
    const query = url.parse(req.url, true).query; //парсинг параметров, затем их получение

    if (req.url.startsWith('/fact')) {
        const k = parseInt(query.k);         // получаем параметр k и преобразуем в число

        if (!isNaN(k)) {
            const factorial = calculateFactorial(k);
            res.writeHead(200, {'Content-Type':'application/json'});
            res.end(factorial.toString());
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

function calculateFactorial(n) {
    if (n === 0) {
        return 1;
    }
    return n * calculateFactorial(n - 1);
}

console.log('http://localhost:5000/fact?k=x');