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
    public class Blog
    {
        private MainPage _mainPage;
        private BlogPage _blogPage;


        [SetUp]
        public void Setup()
        {
            _mainPage = new MainPage(Driver);
            _blogPage = new BlogPage();
        }

        [Test]
        public void Test()
        {
            _mainPage.Open();
            _mainPage.OpenBlog();
            _blogPage.BlogPageTest();  
        }

        [TestCleanup]
        public void Cleanup()
        {
            QuitDriver();
        }

    }
}
