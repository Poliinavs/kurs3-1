const fs = require('fs');
const http = require('http');

const options = {
    hostname: 'localhost',
    port: 3000,
    path: '/saveFile',
    method: 'GET'
};

const req = http.request(options, (res) => {
    const fileStream = fs.createWriteStream('img1.png');

    res.pipe(fileStream);

    fileStream.on('finish', () => {
        console.log('Файл успешно сохранен');
    });
});

req.on('error', (e) => {
    console.error(`Ошибка при отправке запроса: ${e.message}`);
});

req.end();
