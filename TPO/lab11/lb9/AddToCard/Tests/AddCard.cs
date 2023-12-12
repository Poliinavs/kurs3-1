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
    internal class AddTotCard
    {
        private MainPage _mainPage;
        private CardPage _page;


        [SetUp]
        public void Setup()
        {
            _mainPage = new MainPage(Driver);
            _page = new CardPage();
        }

        [Test]
        public void Test()
        {
            _mainPage.Open();
            _page.AddToCard();  // Run the actual test
        }

        [TestCleanup]
        public void Cleanup()
        {
            QuitDriver();
        }
    }
}
