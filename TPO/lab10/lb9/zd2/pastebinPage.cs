using OpenQA.Selenium.Support.UI;
using OpenQA.Selenium;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace zd2
{
    public class PastebinPage
    {
        private IWebDriver driver;

        public PastebinPage(IWebDriver driver)
        {
            this.driver = driver;
        }

        public void OpenPage(string url)
        {
            driver.Navigate().GoToUrl(url);
        }

        public void ClickCreateNewPasteButton()
        {
            Thread.Sleep(900);
            driver.FindElement(By.XPath("//*[@id=\"vue-root\"]/div/div[6]/section/div/button[1]")).Click();
        }

        public void ClickCategoryLink()
        {
            driver.FindElement(By.XPath("//*[@id=\"vue-root\"]/div/main/div/div[2]/div/div/div[3]/div/div[3]/div/a")).Click();
        }

        public void ClickSubCategory()
        {
            driver.FindElement(By.XPath("//*[@id=\"catalog-main\"]/div[1]/div/div[1]/div[6]/ul/li[8]/div/div")).Click();
        }

        public void ClickProductLink()
        {
            driver.FindElement(By.XPath("//*[@id=\"catalog-main\"]/div[1]/div/div[1]/div[6]/ul/li[10]/div/div/div[1]/div/div/a")).Click();
        }

    }
}
