const http = require('http');
const xml2js = require('xml2js').parseString;
const xmlBuilder = require('xmlbuilder');

const postData = `
  <request id="28">
     <x value = "1"/>
     <x value = "2"/>
     <m value = "a"/>
     <m value = "b"/>
  </request>
`;

const options = {
    hostname: 'localhost',
    port: 3000,
    path: '/xml',
    method: 'POST',
    headers: {
        'Content-Type': 'application/xml', 'accept':'application/xml'
    },
};

const req = http.request(options, (res) => {
    let data = '';

    res.on('data', (chunk) => {
        data += chunk;
    });

    res.on('end', () => {
        console.log('body = ', data);
        xml2js(data, (err, str)=>{
            if(err) console.log('error: xml parse');
        })
    });
});

req.on('error', (e) => {
    console.error(`Ошибка при отправке запроса: ${e.message}`);
});

req.end(postData.toString());