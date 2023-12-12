using lb9.Pages;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using static lb9.DriverManager.DriverManager;
namespace lb9.Tests
{
    [TestClass]
    public class Product
    {
        private MainPage _mainPage;
        private ProductPage _Page;


        [SetUp]
        public void Setup()
        {
            _mainPage = new MainPage(Driver);
            _Page = new ProductPage();
        }

        [Test]
        public void Test()
        {
            _mainPage.Open();

            Thread.Sleep(3000);
            _Page.ClickLoginButton();
            _Page.EnterSearchText("Ботинки трекинговые TERREX UNITY LEA MID R.RDY");
            _Page.ClickSearchButton();

            Thread.Sleep(10000);
            _Page.ClickViewDetailsButton();
        }

        [TestCleanup]
        public void Cleanup()
        {
            QuitDriver();
        }

    }
}
