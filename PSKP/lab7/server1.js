const http = require('http');
const url = require("url");
const xml2js = require('xml2js').parseString;
const xmlBuilder = require('xmlbuilder');
const fs = require('fs');


const server = http.createServer((req, res) => {
    if (req.url === '/07-01' && req.method === 'GET') {
        res.writeHead(200, { 'Content-Type':'text/plain; charset=utf-8' });
        res.end('ответ сервера для 07-01');
    }
    const parsedUrl = url.parse(req.url, true);

    if (req.method === 'GET' && parsedUrl.pathname === '/calculate') {
        const x = parseInt(parsedUrl.query.x);
        const y = parseInt(parsedUrl.query.y);

        if (!isNaN(x) && !isNaN(y)) {
            const result = x + y;
            res.writeHead(200, { 'Content-Type': 'text/plain' });
            res.end(`Sum of x and y is: ${result}`);
        } else {
            res.writeHead(400, { 'Content-Type': 'text/plain' });
            res.end('Invalid parameters. Please provide numeric values for x and y.');
        }
    }
    if (req.method == 'POST' && req.url == '/calculate') {
        let requestData = '';

        req.on('data', (chunk) => {
            requestData += chunk;
        });

        req.on('end', () => {
            const requestDataObject = JSON.parse(requestData);

            if (requestDataObject.x && requestDataObject.y && requestDataObject.s) {
                const result = requestDataObject.x + requestDataObject.y + requestDataObject.s;
                const responseData = JSON.stringify({ result });

                res.writeHead(200, { 'Content-Type': 'application/json' });
                res.end(responseData);
            } else {
                res.writeHead(400, { 'Content-Type': 'text/plain' });
                res.end('Invalid parameters. Please provide x, y, and s in the request body.');
            }
        });

   /*     {
            "x": 3,
            "y": 4,
            "s": 5
        }
        */

    }

    if (req.url.startsWith('/json') && req.method === 'POST') {

        let body = '';
        req.on('data', chunk => {
            body += chunk;
        });

        req.on('end', () => {
            const requestData = JSON.parse(body);
            const comment = requestData._comment;
            const x = Number.parseInt(requestData.x);
            const y = Number.parseInt(requestData.y);
            const s = requestData.s;
            const o = requestData.o;
            const m = requestData.m;

            res.writeHead(200, { 'Content-Type': 'text/plain' });
            const response = {
                "__comment": "Answer: " + comment,
                "x:" : x,
                "y:" : y,
                "x_plus_y": x + y,
                "Concatination": s +": "+ o.name+" "+o.surname,
                "Length_m": m.length
            };

            res.end(JSON.stringify(response));
        });
    }

    if (req.url === '/xml' && req.method === 'POST') {
        let data = '';

        req.on('data', (chunk) => {
            data += chunk;
        });

        req.on('end', () => {
            xml2js(data, (err, result) => {
                if (err) {
                    console.error('Ошибка при парсинге XML:', err);
                    res.writeHead(500, { 'Content-Type': 'application/xml' });
                    res.end(`Error`);
                } else {
                    const xSum = result.request.x.reduce((sum, x) => sum + Number(x.$.value), 0);
                    const mConcatenated = result.request.m.reduce((concatenated, m) => concatenated + m.$.value, '');

                    const responseXML = xmlBuilder.create({
                        response: {
                            status: '200',
                            message: 'OK',
                            receivedData: {
                                xSum: String(xSum),
                                mConcatenated: mConcatenated
                            }
                        }
                    }).end({ pretty: true });

                    res.writeHead(200, { 'Content-Type': 'application/xml' });
                    res.end(responseXML);
                }
            });
        });
    }
    if (req.url === '/image' && req.method === 'POST') {
        const fileStream = fs.createWriteStream('image.png');

        req.on('data', (chunk) => {
            fileStream.write(chunk);
        });

        req.on('end', () => {
            fileStream.end();
            res.writeHead(200, { 'Content-Type': 'text/plain' });
            res.end('Load image');
        });
    }

    if (req.url === '/saveFile' && req.method === 'GET') {
        const fileStream = fs.createReadStream('img.png');

        fileStream.on('open', () => {
            res.setHeader('Content-Type', 'image/png');
            fileStream.pipe(res);
        });

        fileStream.on('error', (err) => {
            res.writeHead(500, { 'Content-Type': 'text/plain' });
            res.end('Internal Server Error');
        });
    }





}).listen(3000, () => {
    console.log('Сервер запущен на порту 3000');
});
console.log("http://localhost:3000/07-01");
console.log("http://localhost:3000/calculate");
console.log("http://localhost:3000/json");