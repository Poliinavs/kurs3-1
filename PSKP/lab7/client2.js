const http = require('http');
const url = require('url');

const x = 3;
const y = 4;

const queryParams = `x=${x}&y=${y}`;
const requestUrl = `http://localhost:3000/calculate?${queryParams}`;

const req = http.get(requestUrl, (res) => {
    let responseData = '';

    console.log('Sending GET request to:', requestUrl);
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