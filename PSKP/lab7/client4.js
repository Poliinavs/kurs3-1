

const http = require('http');

let params = JSON.stringify({_comment: 'lb7',
    x:1, y:2,
    s:"message",
    m: ["a", "b", "c"], o: {surname: "Avsukevich", name: "Polina"}});

let options = {
    host: 'localhost',
    path: '/json',
    port: 3000,
    method: 'POST',
    headers: {
        'Content-Type': 'application/json', 'accept': 'application/json'
    }
};

const req = http.request(options, (res) => {
    console.log(`Статус ответа: ${res.statusCode}`);
    console.log(`Сообщение к статусу ответа: ${res.statusMessage}`);

    let data = '';
    res.on('data', (chunk) => {
        data += chunk.toString();
    });

    res.on('end', () => {
        console.log('body = ', data);
        console.log('parse = ', JSON.parse(data));
    });
});

req.on('error', (e) => {
    console.log('http.request: error:', e.message);
});

req.write(params);
req.end();
