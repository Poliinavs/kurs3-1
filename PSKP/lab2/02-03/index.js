let http=require('http');

http.createServer(function(req,resp){

    if(req.url=='/api/name' && req.method=="GET")
    {
        resp.writeHead(200, { 'Content-Type': 'text/plain; charset=utf-8' });
        let text='Авсюкевич Полина Вадимовна';
        resp.end(text);
    }else{
        resp.end("<h1>ERROR</h1>");
    }
}).listen(5000);

console.log('http://localhost:5000/api/name');