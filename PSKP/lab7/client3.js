const http = require('http');

const postData = JSON.stringify({ x: 3, y: 4, s: 5 });

const options = {
    hostname: 'localhost',
    port: 3000,
    path: '/calculate',
    method: 'POST',
    headers: {
        'Content-Type': 'application/json',
        'Content-Length': postData.length,
    },
};

const req = http.request(options, (res) => {
    let responseData = '';

    console.log('Sending POST request to:', options.hostname + options.path);
    console.log('Response Status Code:', res.statusCode);

    res.on('data', (chunk) => {
        responseData += chunk;
    });

    res.on('end', () => {
        console.log('Response Data:', responseData);
    });
});

req.on('error', (err) => {
    console.error('Error:', err.message);
});

req.write(postData);
req.end();