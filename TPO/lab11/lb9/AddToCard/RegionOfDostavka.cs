using Microsoft.VisualStudio.TestTools.UnitTesting;
using OpenQA.Selenium.Chrome;
using OpenQA.Selenium;
using System;
using System.Threading;
using OpenQA.Selenium.Support.UI;

namespace lb9
{
    [TestClass]
    public class RegionOfDostavka
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

            Thread.Sleep(3000);
            driver.FindElement(By.XPath("//*[@id=\"vue-root\"]/div/header/div[1]/div/div[1]/div/div/div/div")).Click();
            Thread.Sleep(3000);
            driver.FindElement(By.XPath("//*[@id=\"modals\"]/div/div/div[2]/div[2]/div[2]/div[3]/a[1]")).Click();
            Thread.Sleep(3000);
            driver.FindElement(By.XPath("//*[@id=\"modals\"]/div/div/div[2]/div[2]/div[2]/div/div[3]/button[1]")).Click();
        }

        [TestCleanup]
        public void TestCleanup()
        {
            Thread.Sleep(13000);
            //driver.Quit();
        }
    }



}
