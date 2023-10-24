using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.Windows.Forms;

namespace lab7.Tests
{
    public class Tests
    {
        [Test]
        public void TestAdd()
        {
            Calculator calculator = new Calculator();
            double result = calculator.Add(5, 3);
            Microsoft.VisualStudio.TestTools.UnitTesting.Assert.AreEqual(8, result);
        }
        [Test]
        public void TestSubtract()
        {
            Calculator calculator = new Calculator();
            double result = calculator.Subtract(10, 3);
            Microsoft.VisualStudio.TestTools.UnitTesting.Assert.AreEqual(7, result);
        }

        [Test]
        public void TestMultiply()
        {
            Calculator calculator = new Calculator();
            double result = calculator.Multiply(4, 5);
            Microsoft.VisualStudio.TestTools.UnitTesting.Assert.AreEqual(20, result);
        }

        [Test]
        public void TestDivide()
        {
            Calculator calculator = new Calculator();
            double result = calculator.Divide(15, 3);
            Microsoft.VisualStudio.TestTools.UnitTesting.Assert.AreEqual(5, result);
        }

        [Test]
        [ExpectedException(typeof(ArgumentException))]
        public void TestDivideByZero()
        {
            Calculator calculator = new Calculator();
            calculator.Divide(5, 0);
        }

        [Test]
        public void TestAddNegativeNumbers()
        {
            Calculator calculator = new Calculator();
            double result = calculator.Add(-5, -3);
            Microsoft.VisualStudio.TestTools.UnitTesting.Assert.AreEqual(-8, result);
        }

        [Test]
        public void TestSubtractNegativeNumbers()
        {
            Calculator calculator = new Calculator();
            double result = calculator.Subtract(-10, -3);
             Microsoft.VisualStudio.TestTools.UnitTesting.Assert.AreEqual(-7, result);
        }

        [Test]
        public void TestMultiplyNegativeNumbers()
        {
            Calculator calculator = new Calculator();
            double result = calculator.Multiply(-4, -5);
            Microsoft.VisualStudio.TestTools.UnitTesting.Assert.AreEqual(20, result); // При умножении отрицательных чисел результат положителен
        }

        [Test]
        public void TestDivideNegativeNumbers()
        {
            Calculator calculator = new Calculator();
            double result = calculator.Divide(-15, -3);
             Microsoft.VisualStudio.TestTools.UnitTesting.Assert.AreEqual(5, result);
        }
        [Test]
        public void TestDivideByNegativeNumber()
        {
            Calculator calculator = new Calculator();
            double result = calculator.Divide(10, -2);
            Microsoft.VisualStudio.TestTools.UnitTesting.Assert.AreEqual(-5, result);
        }

        [Test]
        public void TestMultiplyZero()
        {
            Calculator calculator = new Calculator();
            double result = calculator.Multiply(5, 0);
            Microsoft.VisualStudio.TestTools.UnitTesting.Assert.AreEqual(0, result);
        }


    }
}