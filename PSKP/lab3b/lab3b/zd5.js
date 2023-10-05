function calculateSquare(number) {
    return new Promise((resolve, reject) => {
      if (isNaN(number)) {
        reject("Invalid input: not a number");
      } else {
        resolve(number * number);
      }
    });
  }

  function calculateCube(number) {
    return new Promise((resolve, reject) => {
      if (isNaN(number)) {
        reject("Invalid input: not a number");
      } else {
        resolve(number * number*number);
      }
    });
  }

  function calculateFouth(number) {
    return new Promise((resolve, reject) => {
      if (isNaN(number)) {
        reject("Invalid input: not a number");
      } else {
        resolve(number * number*number*number);
      }
    });
  }

  const input1 ="2";


Promise.all([
  calculateSquare(input1),
  calculateCube(input1),
  calculateFouth(input1)
])
  .then((results) => {
    const [squareResult, cubeResult, fourthPowerResult] = results;
    console.log("Square result:", squareResult);
    console.log("Cube result:", cubeResult);
    console.log("Fourth power result:", fourthPowerResult);
  })
  .catch((error) => {
    console.error("Error:", error);
  });