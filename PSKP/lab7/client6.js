const fs = require('fs');
const http = require('http');

const fileStream = fs.createReadStream('img.png');

const options = {
    hostname: 'localhost',
    port: 3000,
    path: '/image',
    method: 'POST',
    headers: {
        'Content-Type': 'multipart/form-data',
    }
};

const req = http.request(options, (res) => {
    let data = '';

    res.on('data', (chunk) => {
        data += chunk;
    });

    res.on('end', () => {
        console.log(`Статус ответа: ${res.statusCode}`);
        console.log(`Ответ: ${data}`);
    });
});

req.on('error', (e) => {
    console.error(`Ошибка при отправке запроса: ${e.message}`);
});

fileStream.pipe(req);
