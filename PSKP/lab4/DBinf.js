var util=require('util');
var ee=require('events');

var DBdata=[
    {id: 1, name: 'Dasha', day:'2003-10-09'},
   
    {id: 2, name: 'Igor', day:'2003-10-09'},
   
    {id: 3, name: 'Alex', day:'2003-10-09'},

    {id: 4, name: 'Ann', day:'2003-10-09'},

    {id: 5, name: 'Nastya', day:'2003-10-09'}
];




function DB(){
    this.select=()=>
    {
        return DBdata;
    };
    this.insert=(x)=>
    {
        let index=DBdata.findIndex(item=> item.id==x.id);
        if(index==-1){
            DBdata.push(x)
            console.log("push sucsess");
            return x;
        }
        else console.log('id exists');
    };
    this.update=(x)=>
    {
        let index=DBdata.findIndex(item=> item.id==x.id);
        if(index !== -1){
        DBdata.splice(index,1,x);
        return DBdata[index];
        }
        else console.log('error');
    };
    this.delete=(id)=>
    {
        let index=DBdata.findIndex((elem)=> elem.id==id);
        if (index !== -1){
            return DBdata.splice(index, 1);
        }
        else {
            return JSON.parse('{"error": "no index"}');
        }
    }
}


util.inherits(DB, ee.EventEmitter);

module.exports = { DB, DBdata };








// function DB() {
//     this.select = async () => {
//         return new Promise((resolve) => {
//             process.nextTick(() => {
//                 resolve(DBdata);
//             });
//         });
//     };

//     this.insert = async (x) => {
//         return new Promise((resolve, reject) => {
//             process.nextTick(() => {
//                 const index = DBdata.findIndex((item) => item.id === x.id);
//                 if (index === -1) {
//                     DBdata.push(x);
//                     resolve();
//                 } else {
//                     reject(new Error('id exists'));
//                 }
//             });
//         });
//     };

//     this.update = async (x) => {
//         return new Promise((resolve, reject) => {
//             process.nextTick(() => {
//                 const index = DBdata.findIndex((item) => item.id === x.id);
//                 if (index !== -1) {
//                     DBdata.splice(index, 1, x);
//                     resolve();
//                 } else {
//                     reject(new Error('error'));
//                 }
//             });
//         });
//     };

//     this.delete = async (id) => {
//         return new Promise((resolve, reject) => {
//             process.nextTick(() => {
//                 const index = DBdata.findIndex((elem) => elem.id === id);
//                 if (index !== -1) {
//                     DBdata.splice(index, 1);
//                     resolve();
//                 } else {
//                     reject(new Error('no index'));
//                 }
//             });
//         });
//     };
// }


