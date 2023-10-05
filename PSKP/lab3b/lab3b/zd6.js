function calculateSquare(number) {
    return new Promise((resolve, reject) => {
      if (typeof number !== 'number') {
        reject("Invalid input: not a number");
      } else {
        setTimeout(() => {
          reject(number * number);
        }, 1000); // Разрешение Promise спустя 1 секунду
      }
    });
  }
  
  function calculateCube(number) {
    return new Promise((resolve, reject) => {
      if (typeof number !== 'number') {
        reject("Invalid input: not a number");
      } else {
        setTimeout(() => {
          resolve(number * number * number);
        }, 2000); // Разрешение Promise спустя 2 секунды
      }
    });
  }
  
  function calculateFourthPower(number) {
    return new Promise((resolve, reject) => {
      if (typeof number !== 'number') {
        reject("Invalid input: not a number");
      } else {
        setTimeout(() => {
          resolve(number * number * number * number);
        }, 3000); // Разрешение Promise спустя 3 секунды
      }
    });
  }
  
  const input1 = 2;
  
  
  Promise.race([
    calculateSquare(input1),
    calculateCube(input1),
    calculateFourthPower(input1),
  ])
    .then((result) => {
      console.log("First resolved result:", result);
    })
    .catch((error) => {
      console.error("Error:", error);
    });
  
  
  Promise.any([
    calculateSquare(input1),
    calculateCube(input1),
    calculateFourthPower(input1),
  ])
    .then((result) => {
      console.log("Any resolved result:", result);
    })
    .catch((errors) => {
      console.error("All Promises rejected:", errors);
    });
  