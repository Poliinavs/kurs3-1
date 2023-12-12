using OpenQA.Selenium.Chrome;
using OpenQA.Selenium;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.Collections.ObjectModel;

namespace lb9.Pages
{
    internal class BrendsPage : PageBase.PageBase
    {
        private MainPage _mainPage;
        private IWebDriver driver;
        public BrendsPage(IWebDriver driver) : base(driver)
        {
            this.driver = driver;
        }

        public void TestNavigateToPageAndClickElement()
        {
            // Pause for 3 seconds
            Thread.Sleep(3000);

            // Click the first element
            driver.FindElement(By.XPath("//*[@id=\"vue-root\"]/div/header/div[3]/div/div/nav/a[5]")).Click();

            // Pause for 10 seconds
            Thread.Sleep(10000);

            // Click the second element
            driver.FindElement(By.XPath("//*[@id=\"brand-block-A\"]/div/nav/div[1]/div[5]/a")).Click();

            // Pause for 10 seconds
            Thread.Sleep(10000);
        }

        [TestMethod]
        public void TestCountAndVerifyElements()
        {
            // Find elements using XPath
            ReadOnlyCollection<IWebElement> elements = driver.FindElements(By.XPath("//*[@id=\"RTLACX735301\"]/div[1]/div/div[2]/div[1]"));

            // Get the element count
            int elementCount = elements.Count;

            Console.WriteLine("Количество элементов на странице: " + elementCount);

            // Check if the element count is greater than 0
            Assert.IsTrue(elementCount > 0, "Нет элементов на странице с указанным XPath.");
        }
    }
}
