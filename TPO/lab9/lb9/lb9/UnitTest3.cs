using Microsoft.VisualStudio.TestTools.UnitTesting;
using OpenQA.Selenium.Chrome;
using OpenQA.Selenium;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using OpenQA.Selenium.Support.UI;
using OpenQA.Selenium.Interactions;

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
             driver.FindElement(By.XPath("//*[@id=\"vue-root\"]/div/header/div[3]/div/div/div/div/button")).Click();
             driver.FindElement(By.XPath("//*[@id=\"vue-root\"]/div/header/div[3]/div/div/div/div/input")).Click();
             driver.FindElement(By.XPath("//*[@id=\"vue-root\"]/div/header/div[3]/div/div/div/div/input")).SendKeys("Ботинки трекинговые TERREX UNITY LEA MID R.RDY");
             driver.FindElement(By.XPath("//*[@id=\"vue-root\"]/div/header/div[3]/div/div/div/div/button")).Click();

             Thread.Sleep(7000);
             driver.FindElement(By.XPath("//*[@id=\"vue-root\"]/div/div[4]/section/div/button[2]")).Click();

          driver.FindElement(By.XPath("//*[@id=\"RTLACY744201\"]/div[1]/a")).Click();

       /*     pastebinPage.OpenPage("https://www.lamoda.by/p/rtlacy744201/shoes-adidas-botinki-trekingovye/");
            //driver.FindElement(By.XPath("//*[@id=\"vue-root\"]/div/div[5]/section/div/button[2]")).Click();
          
            driver.FindElement(By.Id("//*[@id=\"vue-root\"]/div/main/div/div[2]/div[2]/div/div[3]/div/div/div/div/div[1]/button")).Click();
                driver.FindElement(By.XPath("//li[text()='10 Minutes']")).Click();*/
           
          //  driver.FindElement(By.XPath("//*[@id=\"vue-root\"]/div/main/div/div[2]/div[2]/div/div[3]/div/div/div/div/div[2]/div")).Click();


        }

        [TestCleanup]
        public void TestCleanup()
        {
            Thread.Sleep(12000);
            driver.Quit();
        }
    }
}
