using Microsoft.VisualStudio.TestTools.UnitTesting;
using OpenQA.Selenium.Chrome;
using OpenQA.Selenium;
using System;
using System.Threading;
using OpenQA.Selenium.Support.UI;

namespace lb9
{
    [TestClass]
    public class PastebinTest3
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
            pastebinPage.OpenPage("https://www.lamoda.by/women-home/");
            driver.Manage().Timeouts().PageLoad = TimeSpan.FromSeconds(10);

            Thread.Sleep(3000);
            pastebinPage.ClickLoginButton();
            pastebinPage.EnterSearchText("Ботинки трекинговые TERREX UNITY LEA MID R.RDY");
            pastebinPage.ClickSearchButton();

            Thread.Sleep(9000);
            pastebinPage.ClickViewDetailsButton();
        }

        [TestCleanup]
        public void TestCleanup()
        {
            Thread.Sleep(13000);
            //driver.Quit();
        }
    }


   
}
