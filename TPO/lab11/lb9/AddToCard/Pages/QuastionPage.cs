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
    internal class QuastionPage : PageBase.PageBase
    {
        private MainPage _mainPage;
        private IWebDriver driver;
        public QuastionPage(IWebDriver driver) : base(driver)
        {
            this.driver = driver;
        }
        public void CreateNewPasteTest()
        {
            _mainPage.OpenQuastion();
            OpenSotialMedai();
            OpenTelegram();
            
        }
       
        private void OpenSotialMedai()
        {
            Thread.Sleep(5000);
            driver.FindElement(By.XPath("//*[@id=\"vue-root\"]/div/main/div/section[2]/div")).Click();
        }
        private void OpenTelegram()
        {
            Thread.Sleep(3000);
            driver.FindElement(By.XPath("//*[@id=\"popper_f4lbxrzc_zpfa5g\"]/div[2]/div[1]/div/div/div/ul/li[1]/a")).Click(); 
        }
       
}
}
