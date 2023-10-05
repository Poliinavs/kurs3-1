const http = require('http');
const url = require('url');

const server = http.createServer((req, res) => {
    const query = url.parse(req.url, true).query; //парсинг параметров, затем их получение

    if (req.url.startsWith('/fact')) {
        const k = parseInt(query.k);         // получаем параметр k и преобразуем в число

        if (!isNaN(k)) {
            const factorial = calculateFactorial(k);
            // res.writeHead(200, { 'Content-Type': 'text/html' });
            //
            // res.write(`<h1>Factorial of number ${k} = ${factorial}</h1>`);
            // res.end();
            res.writeHead(200, {'Content-Type':'application/json'});
            res.end(JSON.stringify({k: k, fact: factorial}));
        } else {
            res.writeHead(400, { 'Content-Type': 'text/plain' });
            res.end('Error');
        }
    } else {
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

console.log('http://localhost:5000/fact?k=3');