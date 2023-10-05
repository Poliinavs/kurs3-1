const http = require('http');
const readline = require('readline');

let appState = "norm";

const server = http.createServer((req, res) => {
    if (req.url === '/') {
        res.writeHead(200, { 'Content-Type': 'text/html' });
        res.write(`<h1>${appState}</h1>`);
        res.end();
    } else {
        res.writeHead(404, { 'Content-Type': 'text/plain' });
        res.end('Страница не найдена');
    }
}).listen(5000);

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
    prompt: 'first status -> '
});
rl.prompt();

rl.on('line', (line) => { // Исправление: изменена переменная line
    switch (line.trim()) {
        case 'norm':
            console.log('reg = ' + appState + '-->' + line);
            appState = line;
            break;
        case 'stop':
            console.log('reg = ' + appState + '-->' + line);
            appState = line;
            break;
        case 'test':
            console.log('reg = ' + appState + '-->' + line);
            appState = line;
            break;
        case 'idle':
            console.log('reg = ' + appState + '-->' + line);
            appState = line;
            break;
        case 'exit':
            process.exit(0);
        default:
            console.log("Invalid input");
            break;
    }
    rl.prompt();
});

//console.log("http://localhost:5000")
//node 03-01