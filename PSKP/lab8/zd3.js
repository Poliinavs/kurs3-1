let k=0;
let message;
const websocket=require('ws');
const wsserver=new websocket.Server({port:4002,host:'localhost',path:'/wsserver'})
wsserver.on('connection',(ws)=>{
    ws.on('message',recvmessage=>{
        wsserver.clients.forEach((client)=>{
            if (client.readyState === websocket.OPEN) client.send('server: '+recvmessage);
        });
        message=recvmessage;
    });
    setInterval(()=>{
        ws.close()
    }, (25000));
});

