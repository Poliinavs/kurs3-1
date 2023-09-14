let http = require("http");
let fs = require("fs");

http
    .createServer(function (req, resp) {
        if (req.url == "/jquery") {
            resp.writeHead(200, { "Content-type": "text/html" });
            let text = fs.readFileSync("./jquery.html");
            resp.end(text);
        }
       else if (req.url == "/api/name") {
            resp.writeHead(200, { "Content-type": "text/html" });
            resp.end("Asukevich Polina");
        }
        else{
            resp.end("<h1>ERROR</h1>");
        }
    })
    .listen(5000);
console.log("http://localhost:5000/jquery");