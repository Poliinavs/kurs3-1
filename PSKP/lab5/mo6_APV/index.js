const nodemailer = require('nodemailer');


send = (password,receiver,message)=>{

    sender="pol.avs@outlook.com";
    const transporter = nodemailer.createTransport({
        host: 'smtp.office365.com', // Сервер SMTP Outlook
        port: 587, // Порт SMTP
        secure: false, // Указываем, что соединение не является безопасным (STARTTLS)
        auth: {
            user: sender,
            pass: password,
        },
    });

    const mailOptions = {
        from: sender,
        to: receiver, // Адрес получателя
        subject: 'LAB', // Тема письма
        text: message, // Текст сообщения
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
};
module.exports = send;