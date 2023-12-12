using lb9.Pages;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static lb9.DriverManager.DriverManager;


namespace lb9.Tests
{
    internal class BrendPage
    {
        private MainPage _mainPage;
        private BrendsPage _page;


        [SetUp]
        public void Setup()
        {
            _mainPage = new MainPage(Driver);
            _page = new BrendsPage();
        }

        [Test]
        public void Test()
        {
            _mainPage.Open();
            _mainPage.OpenBrands();
            _page.TestNavigateToPageAndClickElement();
            _page.TestCountAndVerifyElements();

        }

        [TestCleanup]
        public void Cleanup()
        {
            QuitDriver();
        }
    }
}
