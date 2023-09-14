const http = require('http');
const fs = require('fs');

http.createServer(function (req, resp) {
    if (req.url === '/png') {
        resp.writeHead(200, { 'Content-Type': 'image/png' });

        let image = fs.readFileSync('./pic.png');
        resp.end(image);
    }
    else{
        resp.end("<h1>ERROR</h1>");
    }
}).listen(5000, 'localhost');

console.log('http://localhost:5000/png');