function firstJob() {
    return new Promise((resolve, reject) => {
      setTimeout(() => {
        resolve("Hello World");
      }, 2000);
    });
  }
  
  // Обработка Promise с использованием обработчиков
  firstJob()
    .then((result) => {
      console.log("Promise resolved:", result);
    })
    .catch((error) => {
      console.error("Promise rejected:", error);
    });
  
  // Обработка Promise с использованием async/await и try/catch
  async function handleJob() {
    try {
      const result = await firstJob();
      console.log("Async/Await resolved:", result);
    } catch (error) {
      console.error("Async/Await rejected:", error);
    }
  }
  
  handleJob();
  