function thirdJob(data) {
    return new Promise((resolve, reject) => {
        if (isNaN(data)) {
            reject("error");
          }
          else if (data % 2 === 1) {
            setTimeout(() => {
              resolve("odd");
            }, 1000);
          }
          else {
            setTimeout(() => {
              reject("even");
              }, 2000);
          }
    
    });
  }
  
  const inputData = 2;
  
  // Обработка Promise с использованием обработчиков
  thirdJob(inputData)
    .then((result) => {
      console.log("Promise resolved:", result);
    })
    .catch((error) => {
      console.error("Promise rejected:", error);
    });
  
  // Обработка Promise с использованием async/await и try/catch
  async function handleJob() {
    try {
      const result = await thirdJob(inputData);
      console.log("Async/Await resolved:", result);
    } catch (error) {
      console.error("Async/Await rejected:", error);
    }
  }
  
  handleJob();








console.log('')
  