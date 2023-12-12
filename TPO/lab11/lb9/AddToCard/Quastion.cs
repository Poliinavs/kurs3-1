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
    public class Quastion
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

            driver.FindElement(By.XPath("//*[@id=\"vue-root\"]/div/header/div[1]/div/div[2]/div[2]/a")).Click();

            Thread.Sleep(5000);
            driver.FindElement(By.XPath("//*[@id=\"vue-root\"]/div/main/div/section[2]/div")).Click();
            Thread.Sleep(3000);
            driver.FindElement(By.XPath("//*[@id=\"popper_f4lbxrzc_zpfa5g\"]/div[2]/div[1]/div/div/div/ul/li[1]/a")).Click();
        }

        [TestCleanup]
        public void TestCleanup()
        {
            Thread.Sleep(13000);
            //driver.Quit();
        }
    }



}
