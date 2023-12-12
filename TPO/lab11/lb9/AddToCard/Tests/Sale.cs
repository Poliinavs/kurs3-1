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
    [TestClass]
    public class Sale
    {
        private MainPage _mainPage;
        private SalePage _Page;


        [SetUp]
        public void Setup()
        {
            _mainPage = new MainPage(Driver);
            _Page = new SalePage();
        }

        [Test]
        public void Test()
        {
            _mainPage.Open();
            _mainPage.OpenSale();
            _Page.CreateNewPasteTest();
        }

        [TestCleanup]
        public void Cleanup()
        {
            QuitDriver();
        }

    }
}
