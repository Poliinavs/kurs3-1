const uuid = require('uuid'); 

function createOrder(customerCardNumber) {
  return new Promise((resolve, reject) => {
    // Проверка валидности номера карты покупателя
    if (isValidCardNumber(customerCardNumber)) {
      
      const orderId = uuid.v4();

     
      setTimeout(() => {
        resolve(orderId);
      }, 5000);
    } else {
      reject("Card is not valid");
    }
  });
}

function proceedToPayment(orderId) {
  console.log(`Id заказа: ${orderId}`);

  return new Promise((resolve, reject) => {
    const isPaymentSuccessful = Math.random() < 0.5; // 50% вероятности успешной оплаты

    setTimeout(() => {
      if (isPaymentSuccessful) {
        resolve("Payment successful");
      } else {
        reject("Payment failed");
      }
    }, 2000);
  });
}



const customerCardNumber = "1234567890123456"; 
createOrder(customerCardNumber)
  .then((orderId) => {
    console.log(`Заказ создан успешно. Номер заказа: ${orderId}`);
    return proceedToPayment(orderId);
  })
  .then((paymentResult) => {
    console.log(`Статус оплаты: ${paymentResult}`);
  })
  .catch((error) => {
    console.error(`Ошибка при создании заказа: ${error}`);
  });

// Пример функции для проверки валидности номера карты (простой пример)
function isValidCardNumber(cardNumber) {

  //return /^\d{16}$/.test(cardNumber);
  console.log(`Номер карты: ${cardNumber}`);
  const isValid = Math.random() < 0.5; //50% вероятность true
  return isValid;
}


