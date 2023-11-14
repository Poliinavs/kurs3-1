using Microsoft.VisualStudio.TestTools.UnitTesting;
using OpenQA.Selenium.Chrome;
using OpenQA.Selenium;
using System;
using System.Threading;

namespace lb9
{

    [TestClass]
    public class PastebinTest
    {
        private IWebDriver driver;
        private PastebinPage pastebinPage;

        [TestInitialize]
        public void TestInitialize()
        {
            driver = new ChromeDriver();
            pastebinPage = new PastebinPage(driver);
        }
    
                [TestMethod]
                public void CreateNewPasteTest()
                {
                    pastebinPage.OpenPage("https://pastebin.com");
                    pastebinPage.SetCode("Hello from WebDriver");
                    pastebinPage.SetExpiration("10 Minutes");
                    pastebinPage.SetPasteName("helloweb");
           /*         pastebinPage.CreateNewPaste();*/

                    // Добавьте здесь проверки на успешное создание пасты, например, проверку URL или отображение уведомления.
                }
  /*      [TestMethod]
        public void ICanWin()
        {
            WebDriver driver = new ChromeDriver();
            driver.Navigate().GoToUrl("https://pastebin.com");
            driver.FindElement(By.Id("postform-text")).SendKeys("Hello from WebDriver");

            driver.FindElement(By.Id("select2-postform-expiration-container")).Click();
            driver.FindElement(By.XPath("//li[text()='10 Minutes']")).Click();

            driver.FindElement(By.Id("postform-name")).SendKeys("helloweb");
            driver.FindElement(By.XPath("//*[@id=\"w0\"]/div[5]/div[1]/div[10]/button")).Click();

            //driver.Quit();
        }
*/

        [TestCleanup]
        public void TestCleanup()
        {
           
            driver.Quit();
        }
    }
}
