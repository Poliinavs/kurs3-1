using Microsoft.VisualStudio.TestTools.UnitTesting;
using OpenQA.Selenium.Chrome;
using OpenQA.Selenium;
using System;
using System.Threading;
using OpenQA.Selenium.Support.UI;
using System.Collections.ObjectModel;

namespace lb9
{
    [TestClass]
    public class Sale
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
            pastebinPage.OpenPage("https://www.lamoda.by");
            driver.Manage().Timeouts().PageLoad = TimeSpan.FromSeconds(10);
            Thread.Sleep(5000);

            driver.FindElement(By.XPath("//*[@id=\"vue-root\"]/div/header/div[3]/div/div/nav/a[11]")).Click();

            Thread.Sleep(5000);
            ReadOnlyCollection<IWebElement> elements = driver.FindElements(By.XPath("//*[@id='RTLACL954001']/div[1]/a/div/div/div[5]/div/div"));

            // Получить количество элементов
            int elementCount = elements.Count;

            Console.WriteLine("Количество элементов на странице: " + elementCount);

            // Проверить, что количество элементов больше 0
            Assert.IsTrue(elementCount > 0, "Нет элементов на странице с указанным XPath.");

        }

        [TestCleanup]
        public void TestCleanup()
        {
            Thread.Sleep(13000);
            //driver.Quit();
        }
    }



}
