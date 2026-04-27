#include "pch.h"
#include "CppUnitTest.h"
#include "D:\Project\OOP_6.1\OOP_6.1\Array.h"
#include "D:\Project\OOP_6.1\OOP_6.1\Task.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab61Test
{
    TEST_CLASS(ArrayVariant7Test)
    {
    public:
        TEST_METHOD(ProcessArray_CorrectCalculations)
        {
            // Arrange (Підготовка)
            double input[] = { 1.0, -2.0, 3.0, 4.0, -5.0, 6.0 };
            int n = 6;

            // Act (Виконання)
            Array result = processArray(input, n);

            // Assert (Перевірка)
            Assert::AreEqual(static_cast<size_t>(8), result.size());
            Assert::AreEqual(1.0, result[0]);
            Assert::AreEqual(-2.0, result[1]);
            Assert::AreEqual(-42.0, result[2]); // 3.0 * (-14.0)
            Assert::AreEqual(4.0, result[3]);
            Assert::AreEqual(-5.0, result[4]);
            Assert::AreEqual(-84.0, result[5]); // 6.0 * (-14.0)
            Assert::AreEqual(-128.0, result[6]); // Перевірка суми
            Assert::AreEqual(23.0, result[7]);   // Перевірка середнього за модулем
        }
    };
}