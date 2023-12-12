using OpenQA.Selenium;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using static lb9.Log.Log;
namespace lb9.Pages
{
    internal class MainPage : PageBase.PageBase
    {
        private readonly string _baseUrl = "https://www.lamoda.by";

        public MainPage(IWebDriver driver) : base(driver)
        {
        }

        public void Open()
        {
            Driver.Navigate().GoToUrl(_baseUrl);
            Info("Main page opened.");
        }
        public void OpenBlog()
        {
            Thread.Sleep(5000);

            Driver.FindElement(By.XPath("/html/body/div[1]/div/header/div[3]/div/div/nav/a[10]")).Click();
        }
        public void OpenBrands()
        {
            Thread.Sleep(5000);

            Driver.FindElement(By.XPath("//*[@id=\\\"vue-root\\\"]/div/header/div[3]/div/div/nav/a[5]\"")).Click();
        }
        public void OpenQuastion()
        {
            Thread.Sleep(5000);

            Driver.FindElement(By.XPath("//*[@id=\"vue-root\"]/div/header/div[1]/div/div[2]/div[2]/a")).Click();
        }

        public void OpenRegion()
        {
            Thread.Sleep(5000);

            Driver.FindElement(By.XPath("//*[@id=\"vue-root\"]/div/header/div[1]/div/div[1]/div/div/div/div")).Click();
        }

        public void OpenSale()
        {
            Thread.Sleep(5000);

            Driver.FindElement(By.XPath("//*[@id=\"vue-root\"]/div/header/div[3]/div/div/nav/a[11]")).Click();
        }
    }
}
