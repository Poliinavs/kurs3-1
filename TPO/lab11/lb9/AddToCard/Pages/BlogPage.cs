using Microsoft.VisualStudio.TestTools.UnitTesting;
using OpenQA.Selenium;
using OpenQA.Selenium.Chrome;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace lb9.Pages
{
    internal class BlogPage : PageBase.PageBase
    {
        private MainPage _mainPage;
        private IWebDriver driver;

        public BlogPage(IWebDriver driver) : base(driver)
        {
            this.driver= driver;
        }

        public 

        public void BlogPageTest()
        {

            OpenBlog();
            OpenPageBlog();
            OpenProduct();
        }

        private void OpenBlog()
        {
            Thread.Sleep(5000);

            driver.FindElement(By.XPath("/html/body/div[1]/div/header/div[3]/div/div/nav/a[10]")).Click();

        }

        private void OpenPageBlog()
        {
            Thread.Sleep(5000);
            driver.FindElement(By.XPath("//*[@id=\"vue-root\"]/div/main/div/div/div/div[2]/div[1]/section/div/div/div/div/div/a")).Click();
        }

        private void OpenProduct()
        {
            Thread.Sleep(5000);
            driver.FindElement(By.XPath("//*[@id=\"rec641661462\"]/div/div/div[3]/a")).Click();
        }
    }
}
