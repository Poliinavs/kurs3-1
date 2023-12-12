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
    internal class SalePage : PageBase.PageBase
    {
        private MainPage _mainPage;
        private IWebDriver driver;

        public SalePage(IWebDriver driver) : base(driver)
        {
            this.driver = driver;
        }
        public void CreateNewPasteTest()
        {
            _mainPage.OpenQuastion();
            ChooseSale();

        }

        private void ChooseSale()
        {
            Thread.Sleep(5000);
            ReadOnlyCollection<IWebElement> elements = driver.FindElements(By.XPath("//*[@id='RTLACL954001']/div[1]/a/div/div/div[5]/div/div"));

            // Получить количество элементов
            int elementCount = elements.Count;

            Console.WriteLine("Количество элементов на странице: " + elementCount);

            // Проверить, что количество элементов больше 0
            Assert.IsTrue(elementCount > 0, "Нет элементов на странице с указанным XPath.");
        }

    }
}
