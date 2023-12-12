﻿using OpenQA.Selenium;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lb9.PageBase
{
    internal class PageBase
    {
        protected IWebDriver Driver;

        public PageBase(IWebDriver driver)
        {
            this.Driver = driver;
        }
    }
}
