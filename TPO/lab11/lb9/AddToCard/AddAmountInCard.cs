using Microsoft.VisualStudio.TestTools.UnitTesting;
using OpenQA.Selenium.Chrome;
using OpenQA.Selenium;
using System;
using System.Threading;
using OpenQA.Selenium.Support.UI;

namespace lb9
{
    [TestClass]
    public class AddElementInCard
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
            pastebinPage.OpenPage("https://www.lamoda.by/p/rtlaal867001/beauty_accs-kikomilano-balzam-dlya-gub/");
            driver.Manage().Timeouts().PageLoad = TimeSpan.FromSeconds(10);

            Thread.Sleep(3000);
            driver.FindElement(By.XPath("//*[@id=\"vue-root\"]/div/main/div/div[3]/div[2]/div/div[2]/div/div/div/div/div[1]/button")).Click();
            Thread.Sleep(3000);
            driver.FindElement(By.XPath("//*[@id=\"modals\"]/div/div/div[4]/a")).Click();
            Thread.Sleep(10000);
            driver.FindElement(By.XPath("//*[@id=\"cart\"]/div[2]/div/div[2]/div/div/div/div/div/div[1]/div[2]/div/div/div/button[2]/div")).Click();

            IWebElement element = driver.FindElement(By.XPath("//*[@id='cart']/div[2]/div/div[2]/div/div/div/div/div/div[1]/div[2]/div/div/div/div"));

            string elementText = element.Text;

            string expectedText = "2";

            Assert.AreEqual(expectedText, elementText, "Текст элемента не соответствует ожидаемому значению.");
        }

        [TestCleanup]
        public void TestCleanup()
        {
            Thread.Sleep(13000);
            //driver.Quit();
        }
    }



}
