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
    internal class CardPage : PageBase.PageBase
    {
        private MainPage _mainPage;
        private IWebDriver driver;
        public CardPage(IWebDriver driver) : base(driver)
        {
            this.driver = driver;
        }
        public void CreateNewPasteTest()
        {
            driver = new ChromeDriver();
            driver.Navigate().GoToUrl("https://www.lamoda.by/p/rtlaal867001/beauty_accs-kikomilano-balzam-dlya-gub/");
            driver.Manage().Timeouts().PageLoad = TimeSpan.FromSeconds(10);

            AddToCart();

            string actualCount = GetCartItemCount();

            string expectedCount = "2";

            Assert.AreEqual(expectedCount, actualCount, "Текст элемента не соответствует ожидаемому значению.");
        }

        public void AddToCard()
        {
            driver = new ChromeDriver();
            driver.Navigate().GoToUrl("https://www.lamoda.by/p/rtlaal867001/beauty_accs-kikomilano-balzam-dlya-gub/");
            driver.Manage().Timeouts().PageLoad = TimeSpan.FromSeconds(10);

            Thread.Sleep(3000);
            driver.FindElement(By.XPath("//*[@id=\"vue-root\"]/div/main/div/div[3]/div[2]/div/div[2]/div/div/div/div/div[1]/button")).Click();
            Thread.Sleep(3000);
            driver.FindElement(By.XPath("//*[@id=\"modals\"]/div/div/div[4]/a")).Click();
            Thread.Sleep(5000);
        }
        public void DeleteFromCard()
        {
            driver = new ChromeDriver();
            driver.Navigate().GoToUrl("https://www.lamoda.by/p/rtlaal867001/beauty_accs-kikomilano-balzam-dlya-gub/");
            driver.Manage().Timeouts().PageLoad = TimeSpan.FromSeconds(10);

            AddToCart();

            try
            {
                // Попытка найти элемент по XPath
                GetCartItemCount();
                // Если элемент найден, считаем тест не пройденным
                Assert.Fail("Тест не пройден: Элемент корзины найден!");
            }
            catch (NoSuchElementException)
            {

            }
        }

        private void AddToCart()
        {
            Thread.Sleep(3000);
            driver.FindElement(By.XPath("//*[@id=\"vue-root\"]/div/main/div/div[3]/div[2]/div/div[2]/div/div/div/div/div[1]/button")).Click();
            Thread.Sleep(3000);
            driver.FindElement(By.XPath("//*[@id=\"modals\"]/div/div/div[4]/a")).Click();
            Thread.Sleep(10000);
            driver.FindElement(By.XPath("//*[@id=\"cart\"]/div[2]/div/div[2]/div/div/div/div/div/div[1]/div[2]/div/div/div/button[2]/div")).Click();
        }

        private string GetCartItemCount()
        {
            IWebElement element = driver.FindElement(By.XPath("//*[@id='cart']/div[2]/div/div[2]/div/div/div/div/div/div[1]/div[2]/div/div/div/div"));
            return element.Text;
        }
    }
}
