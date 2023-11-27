let http=require('http');
let fs=require('fs');

const httpserver=http.createServer((req, resp)=>{
    if (req.method=='GET' && req.url=='/start'){
        resp.writeHead(200,{'Content-Type':'text/html'});
        resp.end(fs.readFileSync('zd1.html'));
    }
    else {
        resp.writeHead(400,{'Content-Type':'text/plain'});
        resp.end(`statuscode: ${resp.statusCode}`);
    }
});
httpserver.listen(3000);

let n=0;
let message;
const websocket=require('ws');
const wsserver=new websocket.Server({port:4000,host:'localhost',path:'/wsserver'})
wsserver.on('connection',(ws)=>{
    ws.on('message',recvmessage=>{
        //console.log(`received message: ${}`);
        message=recvmessage;
    });
    setInterval(() => {
        ws.send(`08-01-client: ${message}->${++n}`)
    }, (5000));
    setInterval(()=>{
        ws.close()
    }, (25000));
});

console.log(`http://localhost:3000/start`);