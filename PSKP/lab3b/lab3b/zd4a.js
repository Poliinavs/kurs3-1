const uuid = require('uuid'); 

function createOrder(customerCardNumber) {
  return new Promise((resolve, reject) => {
    // Проверка валидности номера карты покупателя (примерная проверка)
    if (isValidCardNumber(customerCardNumber)) {
      // Генерация уникального идентификатора заказа
      const orderId = uuid.v4();

      // Имитация задержки в 5 секунд перед разрешением Promise
      setTimeout(() => {
        resolve(orderId);
      }, 5000);
    } else {
      reject("Card is not valid");
    }
  });
}

function proceedToPayment(orderId) {
//  console.log(`Id заказа: ${orderId}`);

  return new Promise((resolve, reject) => {
    const isPaymentSuccessful = Math.random() < 0.5; // 50% вероятности успешной оплаты

    setTimeout(() => {
      if (isPaymentSuccessful) {
        resolve("Payment successful");

      } else {
        reject("Payment failed");
      }
    }, 2000); // Имитация асинхронной задержки в 2 секунды
  });
}



const customerCardNumber = "1234567890123456"; 


// Пример функции для проверки валидности номера карты (простой пример)
function isValidCardNumber(cardNumber) {

  //return /^\d{16}$/.test(cardNumber);
  console.log(`Номер карты: ${cardNumber}`);
  const isValid = Math.random() < 0.5; //50% вероятность true
  return isValid;
}

async function handleJob() {
    try {
      const orderId = await createOrder(customerCardNumber);
     console.log(`Номер заказа: ${orderId}`);
     const paymentResult = await  proceedToPayment(orderId);
     console.log(`Статус оплаты: ${paymentResult}`);
    } catch (error) {
    console.error(`Ошибка при создании заказа: ${error}`);
  
    }
  }
  
  handleJob();
