const http = require('http');

const options = {
    host: 'localhost',
    port: 3000,
    path: '/07-01',
    method: 'GET'
};

const req = http.request(options, (res) => {
    console.log(`Статус ответа: ${res.statusCode}`);
    console.log(`Сообщение: ${res.statusMessage}`);
    console.log(`IP-адрес удаленного сервера: ${res.socket.remoteAddress}`);
    console.log(`Порт удаленного сервера: ${res.socket.remotePort}`);
});

req.on('error', (e) => {
});

req.end();