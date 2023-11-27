const websocket=require('ws');
let socket=new websocket('ws:/localhost:4002/wsserver');

let k=0;

socket.onopen=()=>{
    console.log('open connection');
    setInterval(() => {
        socket.send(`client: First-${++k}`);
    }, 3000);
};
socket.onclose=(e)=>console.log(`close connection`);
socket.onmessage=(e)=>{
    console.log(`${e.data}`);
}
