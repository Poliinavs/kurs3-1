const http = require('http');
const url = require('url');
const fs = require('fs');

const { exec } = require('child_process'); // Импортируем модуль child_process для выполнения системной команды

const server = http.createServer((req, res) => {
    if (req.method === 'GET' && req.url.startsWith('/connection')) {
        const parsedUrl = url.parse(req.url, true);
        const queryParameters = parsedUrl.query;

        if ('set' in queryParameters) {

            server.keepAliveTimeout = parseInt(queryParameters.set, 10);
            res.writeHead(200, { 'Content-Type': 'text/plain; charset=utf-8' });
            res.end(`KeepAliveTimeout изменен на ${ server.keepAliveTimeout} ms`);
        } else {
            res.writeHead(200, { 'Content-Type': 'text/plain' });
            res.end(`KeepAliveTimeout: ${server.keepAliveTimeout} ms`);
        }
    }
     if (req.url === '/headers') {
        res.writeHead(200, { 'Content-Type': 'text/plain' });
        const requestHeaders = JSON.stringify(req.headers, null, 2); // Заголовки запроса
        const responseHeaders = JSON.stringify(res.getHeaders(), null, 2); // Заголовки ответа
        const headersInfo = `Request Headers:\n${requestHeaders}\n\nResponse Headers:\n${responseHeaders}`;
        res.end(headersInfo);
    }
     if (req.method === 'GET' && req.url.startsWith('/parameter')) {
        const parsedUrl = url.parse(req.url, true);
        const {x, y} = parsedUrl.query;

        if (x && y) {
            // Преобразуем параметры x и y в числа
            const numX = parseFloat(x);
            const numY = parseFloat(y);

            // Проверяем, являются ли x и y числами
            if (!isNaN(numX) && !isNaN(numY)) {
                // Выполняем операции
                const sum = numX + numY;
                const difference = numX - numY;
                const product = numX * numY;
                const quotient = numX / numY;

                // Отправляем результат в ответе
                res.writeHead(200, {'Content-Type': 'text/plain; charset=utf-8'});
                res.end(
                    `Сумма: ${sum}\nРазность: ${difference}\nПроизведение: ${product}\nЧастное: ${quotient}`
                );
            } else {
                // Выводим сообщение об ошибке, если x или y не являются числами
                res.writeHead(400, {'Content-Type': 'text/plain; charset=utf-8'});
                res.end('Ошибка: x и y должны быть числами.');
            }

        }
    }
  //zd4  /parameter/x/y
    const parsedUrl = url.parse(req.url);
    const pathSegments = parsedUrl.pathname.split('/');
 /*   console.log(parsedUrl);
    console.log(pathSegments[1]);*/
   if (pathSegments[1] == 'parameter') {
        const x = parseFloat(pathSegments[2]);
        const y = parseFloat(pathSegments[3]);
       console.log("ff");
        if (!isNaN(x) && !isNaN(y)) {
        /*    const sum = x + y;
            const difference = x - y;
            const product = x * y;
            const quotient = x / y;*/
console.log("ff");
            res.writeHead(302, { 'Location': `/parameter?x=${x}&y=${y}` });



        } else {
            res.writeHead(400, { 'Content-Type': 'text/plain; charset=utf-8' });
            res.end('Ошибка: x и y должны быть числами.');
        }
    }


});

const port = 3000; // Вы можете выбрать любой свободный порт

server.listen(port, () => {
    console.log(`Сервер запущен на порту ${port}`);
});
console.log("http://localhost:3000/connection")
console.log("http://localhost:3000/connection?set=10")
console.log("http://localhost:3000/headers")
console.log("http://localhost:3000/parameter?x=2&y=3")
console.log("http://localhost:3000/parameter/5/3")