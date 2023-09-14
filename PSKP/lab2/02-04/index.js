let http=require('http');

let fs=require('fs');

http.createServer(function(req, resp){
    if(req.url=='/xmlhttprequest'){
        resp.writeHead(200, { "Content-type": "text/html" });
        let text = fs.readFileSync("./xmlhttprequest.html");
        resp.end(text);

    }
   else if(req.url=='/api/name'){
        resp.writeHead(200, { "Content-type": "text/html" });
        resp.end("Avsukevich Polina");

    }
    else{
        resp.end("<h1>ERROR</h1>");
    }
}).listen(5000,'localhost');

console.log('http://localhost:5000/xmlhttprequest');
console.log('http://localhost:5000/api/name');