const fs = require('fs');
const send = require("./mo6_APV");



const http = require('http');
const nodemailer = require('nodemailer');
const querystring = require('querystring');

const port = 3000;
//pol.avs@outlook.com
const server = http.createServer((req, res) => {
    if (req.method === 'GET' && req.url === '/') {
        // Отправить HTML-форму для ввода данных
        send('teddy.174',"pol.avs@outlook.com","Message from 3");
        res.writeHead(500, { 'Content-Type': 'text/plain' });
        res.end('All Good ');

    } else {
        res.writeHead(404, { 'Content-Type': 'text/plain' });
        res.end('Страница не найдена');
    }
});

server.listen(port, () => {
    console.log(`Сервер запущен на порту ${port}`);
});
console.log("http://localhost:3000/")
