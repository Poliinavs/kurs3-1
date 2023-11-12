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
            pastebinPage.CreateNewPaste();

            // Добавьте здесь проверки на успешное создание пасты, например, проверку URL или отображение уведомления.
        }

        [TestCleanup]
        public void TestCleanup()
        {
            Thread.Sleep(20000);
            driver.Quit();
        }
    }
}
