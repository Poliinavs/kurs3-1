using Microsoft.VisualStudio.TestTools.UnitTesting;
using OpenQA.Selenium.Chrome;
using OpenQA.Selenium;

namespace zd2
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

                Thread.Sleep(900);
                pastebinPage.ClickCreateNewPasteButton();
                pastebinPage.ClickCategoryLink();
                Thread.Sleep(100);
                pastebinPage.ClickSubCategory();
                Thread.Sleep(100);
                pastebinPage.ClickProductLink();

                // Additional actions can be added here if needed

                // Example of additional actions
                // pastebinPage.ClickAdditionalElement();
                // pastebinPage.PerformAnotherAction();

                // Thread.Sleep(17000); // If needed, add sleep for cleanup or other actions
            }

            [TestCleanup]
            public void TestCleanup()
            {
                Thread.Sleep(17000);
                //driver.Quit();
            }
        }
    
}