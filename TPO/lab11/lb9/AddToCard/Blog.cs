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
    public class Blog
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

            driver.FindElement(By.XPath("/html/body/div[1]/div/header/div[3]/div/div/nav/a[10]")).Click();

            Thread.Sleep(5000);
            driver.FindElement(By.XPath("//*[@id=\"vue-root\"]/div/main/div/div/div/div[2]/div[1]/section/div/div/div/div/div/a")).Click();
            Thread.Sleep(5000);
            driver.FindElement(By.XPath("//*[@id=\"rec641661462\"]/div/div/div[3]/a")).Click();


        }

        [TestCleanup]
        public void TestCleanup()
        {
            Thread.Sleep(13000);
            //driver.Quit();
        }
    }



}
