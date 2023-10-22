const http = require('http');
const url = require('url');
const fs = require('fs');
const xml2js = require('xml2js');
const path = require('path');

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
        const numX = parseFloat(pathSegments[2]);
        const numY = parseFloat(pathSegments[3]);
       console.log("ff");
        if (!isNaN(numY) && !isNaN(numX)) {
            console.log("ffssss");
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
            res.writeHead(400, { 'Content-Type': 'text/plain; charset=utf-8' });
            res.end('Ошибка: x и y должны быть числами.');
        }
    }

    if (req.method === 'GET' && req.url.startsWith('/socket')) {
        const clientIP = req.connection.remoteAddress;
        const clientPort = req.connection.remotePort;

        const serverIP = req.connection.localAddress;
        const serverPort = req.connection.localPort;

        res.setHeader('Content-Type', 'text/plain');
        res.end(`Client IP: ${clientIP}, Client Port: ${clientPort}, Server IP: ${serverIP}, Server Port: ${serverPort}`);
    }

    if (req.method === 'GET' && req.url.startsWith('/resp-status')) {
        const parsedUrl = url.parse(req.url, true);
        const { code, mess } = parsedUrl.query;

        if (code || mess) {
            res.writeHead(Number(code),mess, {'Content-Type': 'text/plain; charset=utf-8'});
            res.end(`Code: ${code}\nMessage: ${mess}`);

        } else {
            res.writeHead(Number(code), { 'Content-Type': 'text/plain' });
            res.end(mess);
        }
    }



    if (req.method === 'GET' && req.url.startsWith('/formparameter')) {
        res.writeHead(200, { 'Content-Type': 'text/html' });
        const formHtml = fs.readFileSync('zd7.html', 'utf8');
        res.end(formHtml);
    }

    if (req.method === 'POST' && req.url === '/formparameter') {
        let body = '';
        req.on('data', chunk => {
            body += chunk.toString();
        });

        req.on('end', () => {
            const formData = new URLSearchParams(body);
            const values = {};
            formData.forEach((value, key) => {
                values[key] = value;
            });

            res.writeHead(200, { 'Content-Type': 'text/plain' });
            res.end(JSON.stringify(values));
        });

    }


    if (req.method === 'POST' && req.url === '/json'){
        let data = '';

        req.on('data', chunk => {
            data += chunk;
        });

        req.on('end', () => {
            try {
                const reqData = JSON.parse(data);
                const comment = reqData._comment;
                const x = reqData.x;
                const y = reqData.y;
                const s = reqData.s;
                const o = reqData.o;
                const m = reqData.m;

                const response = {
                    "_comment": "Ответ: " + comment,

                    "x_plus_y": x + y,
                    "Concat_s_o": s +": "+ o.name,
                    "Length_m": m.length
                };

                res.writeHead(200, { 'Content-Type': 'application/json' });
                res.end(JSON.stringify(response));
            } catch (error) {
                res.writeHead(400, { 'Content-Type': 'text/plain' });
                res.end('Error with request');
            }

            //Post:
          /*  {
                "_comment": "Lb6",
                "x": 1,
                "y": 2,
                "s": "Сообщение",
                "m":["a", "b", "c"],
                "o": {"surname": "Avsiukevich", "name": "Polina"}}
*/



        });
    }
    if (req.method === 'POST' && req.url === '/xml'){
    /*    <request id="28">
            <x value = "1"/>
            <x value = "2"/>
            <m value = "a"/>
            <m value = "b"/>
        </request>
        */

        let data = '';

        req.on('data', chunk => {
            data += chunk;
        });

        req.on('end', () => {
            xml2js.parseString(data, (err, result) => {
                if (err) {
                    res.writeHead(400, { 'Content-Type': 'text/plain' });
                    res.end('Bad Request');
                    return;
                }

                const request = result.request;
                const id = request.$.id;
                const xs = request.x.map(x => +x.$.value || 0);
                const ms = request.m.map(m => m.$.value);

                const sumX = xs.reduce((acc, curr) => acc + curr, 0);
                const concatM = ms.join('');

                const response = {
                    response: {
                        $: { id: id, request: id },
                        sum: { $: { element: 'x', result: sumX.toString() } },
                        concat: { $: { element: 'm', result: concatM } }
                    }
                };

                const builder = new xml2js.Builder();
                const xml = builder.buildObject(response);

                res.writeHead(200, { 'Content-Type': 'application/xml' });
                res.end(xml);
            });
        });



    }

    if (req.method === 'GET' && req.url === '/files'){
        fs.readdir('./static', (err, files) => {
            if (err) {
                res.writeHead(500, { 'Content-Type': 'text/plain' });
                res.end('Error');
                return;
            }

            const fileCount = files.length;
            res.writeHead(200, { 'Content-Type': 'text/plain', 'X-static-files-count': fileCount.toString() });
            res.end(`Number of files : ${fileCount}`);
        });
    }

    if (pathSegments[1] == 'files') {
        const file = pathSegments[2];

        if (file !== undefined) {
            const filePath = path.join(__dirname, 'static', file);

            try {
                const fileContent = fs.readFileSync(filePath);

                res.writeHead(200, { 'Content-Type': 'text/plain' });
                res.end(fileContent);
            } catch (err) {
                res.writeHead(404, { 'Content-Type': 'text/plain' });
                res.end('Error 404: File Not Found');
            }
        }
    }


    if (req.method === 'GET' && req.url === '/upload'){
        fs.readFile('zd12.html', (err, data) => {
            if (err) {
                res.writeHead(500, {'Content-Type': 'text/plain'});
                res.end('Error');
                return;
            }

            res.writeHead(200, {'Content-Type': 'text/html'});
            res.end(data);
        });
    }
    if (req.method === 'POST' && req.url === '/upload'){
        let data = [];
        req.on('data', chunk => {
            data.push(chunk);
        });

        req.on('end', () => {
            const boundary = req.headers['content-type'].split('=')[1];
            const fileData = Buffer.concat(data).toString();
            const fileStart = fileData.indexOf('filename="') + 10;
            const fileEnd = fileData.indexOf('"', fileStart);
            const fileName = fileData.slice(fileStart, fileEnd);

            const filePath = path.join(__dirname, 'static', fileName);

            const fileContentStart = fileData.indexOf('\r\n\r\n') + 4;

            fs.writeFile(filePath, fileData.slice(fileContentStart), (err) => {
                if (err) {
                    res.writeHead(500, {'Content-Type': 'text/plain'});
                    res.end('Internal Server Error');
                } else {
                    res.writeHead(200, {'Content-Type': 'text/plain'});
                    res.end('File uploaded successfully!');
                }
            });
        });
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
console.log("http://localhost:3000/socket ")
console.log("http://localhost:3000/resp-status?code=200&mess=AllOk")
console.log("http://localhost:3000/formparameter ")
console.log("http://localhost:3000/json ")
console.log("http://localhost:3000/xml ")
console.log("http://localhost:3000/files ")
console.log("http://localhost:3000/files/a.txt ")
console.log("http://localhost:3000/upload ")