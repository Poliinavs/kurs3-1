using OpenQA.Selenium;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lb9.Pages
{
    internal class ProductPage : PageBase.PageBase
    {
        private MainPage _mainPage;
        private IWebDriver driver;
        public ProductPage(IWebDriver driver) : base(driver)
        {
            this.driver = driver;
        }
        public void ClickLoginButton()
        {
            driver.FindElement(By.XPath("//*[@id=\"vue-root\"]/div/header/div[3]/div/div/div/div/button")).Click();
        }

        public void EnterSearchText(string searchText)
        {
            var searchInput = driver.FindElement(By.XPath("//*[@id=\"vue-root\"]/div/header/div[3]/div/div/div/div/input"));
            searchInput.Click();
            searchInput.SendKeys(searchText);
        }

        public void ClickSearchButton()
        {
            driver.FindElement(By.XPath("//*[@id=\"vue-root\"]/div/header/div[3]/div/div/div/div/button")).Click();
        }

        public void ClickViewDetailsButton()
        {
            driver.FindElement(By.XPath("//*[@id=\"vue-root\"]/div/div[4]/section/div/button[2]")).Click();
            driver.FindElement(By.XPath("//*[@id=\"RTLACY744201\"]/div[1]/a")).Click();
        }
    }
}
