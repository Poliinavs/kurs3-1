const websocket=require('ws');
let socket=new websocket('ws:/localhost:4000/wsserver');
let k=0;
socket.onopen=()=>{

    console.log('open connection');
    setInterval(() => {
        socket.send(++k);
    }, 3000);
};

socket.onclose=(e)=>console.log(`close connection`);

socket.onmessage=(e)=>{
    console.log(`${e.data}`);
}
socket.onerror=function(error) {alert('Error'+error.message);};