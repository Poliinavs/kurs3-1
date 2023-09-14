let http = require("http");
let fs = require("fs");

http
    .createServer(function (req, resp) {
        if (req.url == "/fetch") {
            resp.writeHead(200, { "Content-type": "text/html" });
            let text = fs.readFileSync("./fetch.html");
            resp.end(text);
        }
       else if(req.url=='/api/name') {
            resp.writeHead(200, { "Content-type": "text/html" });
            resp.end("Polina Avsukevich");
        }
        else{
            resp.end("<h1>ERROR</h1>");
        }
    })
    .listen(5000);
console.log("http://localhost:5000/fetch");
console.log("http://localhost:5000/api/name");