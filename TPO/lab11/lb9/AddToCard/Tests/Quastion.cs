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
    public class Quastion
    {
        private MainPage _mainPage;
        private QuastionPage _Page;


        [SetUp]
        public void Setup()
        {
            _mainPage = new MainPage(Driver);
            _Page = new QuastionPage();
        }

        [Test]
        public void Test()
        {
            _mainPage.Open();
            _mainPage.OpenQuastion();
            _Page.CreateNewPasteTest();
        }

        [TestCleanup]
        public void Cleanup()
        {
            QuitDriver();
        }

    }
}
