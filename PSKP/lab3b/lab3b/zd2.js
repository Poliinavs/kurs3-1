function secondJob() {
    return new Promise((resolve, reject) => {
      setTimeout(() => {
        reject("Hello World");
      }, 3000);
    });
  }
  
  
  // Обработка Promise с использованием обработчиков
  secondJob()
    .then((result) => {
      console.log("Promise resolved:", result);
    })
    .catch((error) => {
      console.error("Promise rejected:", error);
    });
  
  // Обработка Promise с использованием async/await и try/catch
  async function handleJob() {
    try {
      const result = await secondJob();
      console.log("Async/Await resolved:", result);
    } catch (error) {
      console.error("Async/Await rejected:", error);
    }
  }
  
  handleJob();








console.log('')
  