using OpenQA.Selenium.Chrome;
using OpenQA.Selenium;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace lb9.Pages
{
    internal class RregionPage : PageBase.PageBase
    {
        private MainPage _mainPage;
        private IWebDriver driver;
        public RregionPage(IWebDriver driver) : base(driver)
        {
            this.driver = driver;
        }
        public void CreateNewPasteTest()
        {
            _mainPage.OpenQuastion();
            OpenDostavka();
            ChooseMinsk();

        }

        private void OpenDostavka()
        {
            Thread.Sleep(3000);
            driver.FindElement(By.XPath("//*[@id=\"modals\"]/div/div/div[2]/div[2]/div[2]/div[3]/a[1]")).Click();
        }
        private void ChooseMinsk()
        {
            Thread.Sleep(3000);
            driver.FindElement(By.XPath("//*[@id=\"modals\"]/div/div/div[2]/div[2]/div[2]/div/div[3]/button[1]")).Click();
        }

    }
}
