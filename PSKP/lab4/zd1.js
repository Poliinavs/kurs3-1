var http=require('http');
var url=require('url');
let fs = require("fs");
var id=0;

//каленларь, проверка на повтор id, на буд дату , при put вводим id и сразу подтягивается остальное 


const data = require('./DBinf');
const db = new data.DB();

db.on('GET', (req, resp)=>{
    console.log('db.get');
    resp.end(JSON.stringify(db.select()));
});

db.on('POST', (req, resp)=>{
    console.log('db.post');

    let b = '';
    req.on('data',str=>{b+=str; console.log('data',b);});
    
    req.on('end', () => {
        try {
            const result = db.insert(JSON.parse(b));
           // resp.end(JSON.stringify(db.select()));
        
           resp.end(JSON.stringify(result));
        } catch (error) {
            console.error('Error parsing JSON:', error);
            resp.statusCode = 400; // Ошибка парсинга JSON
            resp.end('Bad Request');
        }
    });

});

db.on('PUT', (req, resp)=>{
    console.log('db.PUT');

    let b = '';
    req.on('data',str=>{b+=str; console.log('data',b);});
    
    req.on('end', () => {
        try {
            const result = db.update(JSON.parse(b));
           // resp.end(JSON.stringify(db.select()));
           resp.end(JSON.stringify(result));
        } catch (error) {
            console.error('Error parsing JSON:', error);
            resp.statusCode = 400; // Ошибка парсинга JSON
            resp.end('Bad Request');
        }
    });

});

db.on('DELETE', (req, resp)=>{
    console.log('db.DELETE');

    let b = '';
    req.on('data',str=>{b+=str; console.log('data',b);});
    
    req.on('end', () => {
        try {
            const result = db.delete(JSON.parse(b).id);
            //resp.end(JSON.stringify(db.select()));
            resp.end(JSON.stringify(result));
        } catch (error) {
            console.error('Error parsing JSON:', error);s
            resp.statusCode = 400; // Ошибка парсинга JSON
            resp.end('Bad Request');
        }
    });

});



http.createServer(function(req,resp){
    if (url.parse(req.url).pathname==='/'){
        // resp.writeHead(200,{'Content-Type':'application/json'});
        // resp.end(JSON.stringify(db));
        resp.writeHead(200, { "Content-type": "text/html" });
        let text = fs.readFileSync("./fetch.html");
        resp.end(text);

    }
    else if (url.parse(req.url).pathname==='/api/db'){
        //id=parseInt(url.parse(req.url,true).query.id);
        db.emit(req.method,req,resp);
    }
}).listen(5000);

console.log('http://localhost:5000/api/db');
console.log('http://localhost:5000');