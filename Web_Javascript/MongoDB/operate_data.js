const mongodb = require('mongodb')
const MongoClient = mongodb.MongoClient

MongoClient.connect('mongodb://localhost:27017/test', (err, client) => {
 const db = client.db('test');
 console.log("Connected successfully to server")
 dbOperation(db, () => {
  client.close()
 })
})
const dbOperation = (db, callback) => {
 const document1 = { name:'akiko', age:19 }
 const document2 = [
   {name:'taro', age:22},
   {name:'hanako', age:15}
 ]
 const set_document = {'$set': {'name': 'sato akiko'}}
 // insert one data
 db.collection('user').insertOne(document1, (err, result) => {
  console.log("Insert 1 user")
 })
 // insert data
 db.collection('user').insertMany(document2, (err, result) => {
  console.log("Inserted 2 more user")
  })
 // find data
 db.collection('user').find().toArray((err, items) => {
  console.log("=== find all data")
  console.log(items)
 })
 // find specified documents
 // db.collection('user').find().toArray({age: {$gt: 19}}, (err, items) => {
 //  console.log("=== find age >= 19")
 //  console.log(items)
 // }) 
 // find specified one document
 db.collection('user').findOne(document1, (err, item) => {
  console.log("=== find one data")
  console.log(item)
 })
 // update document
 db.collection('user').updateOne(document1, set_document, (err, item) => {
  console.log("=== update data") 
  console.log(item)
 })
 db.collection('user').deleteOne({name: 'hanako', age: 15}, (err, item) => {
  console.log("=== delete data")
  console.log(item)
 })
 db.collection('user').find().toArray((err, items) => {
  console.log("=== find all data")
  console.log(items)
 })
 db.collection('user').insertOne({name: 'tane'}, (err, result) => {
  console.log("Insert 1 user")
  callback(result)
 })
}
