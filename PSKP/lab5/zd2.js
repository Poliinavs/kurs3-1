const fs = require('fs');




const http = require('http');
const nodemailer = require('nodemailer');
const querystring = require('querystring');

const port = 3000;
//pol.avs@outlook.com
const server = http.createServer((req, res) => {
    if (req.method === 'GET' && req.url === '/') {
        // Отправить HTML-форму для ввода данных
        fs.readFile('zd2.html', 'utf8', (err, data) => {
            if (err) {
                console.error('Ошибка при чтении файла index.html:', err);
                res.writeHead(500, { 'Content-Type': 'text/plain; charset=utf-8' });
                res.end('Ошибка при чтении файла');
            } else {
                res.writeHead(200, { 'Content-Type': 'text/html; charset=utf-8' });
                res.end(data);
            }
        });

    } else if (req.method === 'POST' && req.url === '/send') {
        console.log("POST");
        let requestBody = '';

        req.on('data', (data) => {
            requestBody += data.toString();
        });

        req.on('end', async () => {
            const {sender, receiver, message} = querystring.parse(requestBody);
            console.log(message);
            console.log(receiver);
            console.log(sender);



            const transporter = nodemailer.createTransport({
                host: 'smtp.office365.com',                                                           // Сервер SMTP Outlook
                port: 587,                                                                          // Порт SMTP
                secure: false,                                                                       // Указываем, что соединение не является безопасным (STARTTLS)
                auth: {
                    user: sender,
                    pass: password,
                },
            });

            const mailOptions = {
                from: sender,
                to: receiver,                                                                     // Адрес получателя
                subject: 'LAB',                                                                    // Тема письма
                text: message,                                                                       // Текст сообщения
            };

            transporter.sendMail(mailOptions, (err, info) => {
                if (err) {
                    console.error(err);
                } else {
                    console.log('Отправлено: ' + info.response);
                    res.writeHead(400, { 'Content-Type': 'text/plain; charset=utf-8' });
                    res.end('Отправлено');
                }
            });













            // Настройки транспорта для Nodemailer (замените на свои данные)
           /* const transporter = nodemailer.createTransport({
                host: 'smtp.ethereal.email',
                port: 587,
                secure: false,
                auth: {
                    user: sender, // Замените на свой Gmail адрес
                }
            });

       /!*     const mailOptions = {
                from: sender,
                to: receiver,
                subject: 'Тестовое письмо с использованием Nodemailer',
                text: message
            };*!/
            let result = await transporter.sendMail({
                from: sender,
                to: receiver,
                subject: 'Message from Node js',
                text: message,
                html:
                    'This <i>message</i> was sent from <strong>Node.js</strong> server.',
            });
            console.log(result)*/

            // Отправка письма
            /*  transporter.sendMail(mailOptions, (error, info) => {
                  if (error) {
                      console.log('Ошибка при отправке: ' + error);
                      res.writeHead(500, { 'Content-Type': 'text/plain' });
                      res.end('Ошибка при отправке письма');
                  } else {
                      console.log('Письмо отправлено: ' + info.response);
                      res.writeHead(200, { 'Content-Type': 'text/plain' });
                      res.end('Письмо успешно отправлено');
                  }
              });*/
        });
    } else {
        res.writeHead(404, { 'Content-Type': 'text/plain' });
        res.end('Страница не найдена');
    }
});

server.listen(port, () => {
    console.log(`Сервер запущен на порту ${port}`);
});
console.log("http://localhost:3000/")
