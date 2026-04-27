#include "Array.h"
#include <cmath>
using namespace std;

// Конструктор із заданою ємністю (за замовчуванням – minsize)
Array::Array(const size_type& n) throw(bad_alloc, invalid_argument)
{
    if (n == 0)
        throw invalid_argument("Розмір масиву має бути > 0");

    First = 0;
    Count = Size = n;
    elems = new value_type[Size];
    for (UINT i = 0; i < Size; i++)
        elems[i] = 0.0;
}

// Конструктор з ітераторами (діапазон вказівників)
Array::Array(const iterator first, const iterator last)
throw(bad_alloc, invalid_argument)
{
    if (first > last)
        throw invalid_argument("Невірний діапазон ітераторів");

    First = 0;
    Count = Size = static_cast<size_type>(last - first) + 1;
    elems = new value_type[Size];
    for (UINT i = 0; i < Size; i++)
        elems[i] = first[i];
}

// Конструктор з індексами першого та останнього елемента
Array::Array(const size_type first, const size_type last)
throw(bad_alloc, invalid_argument)
{
    if (first > last)
        throw invalid_argument("first має бути <= last");

    First = first;
    Count = Size = (last - first) + 1;
    elems = new value_type[Size];
    for (UINT i = 0; i < Size; i++)
        elems[i] = 0.0;
}

// Конструктор копіювання
Array::Array(const Array& t) throw(bad_alloc)
    : Size(t.Size), Count(t.Count), First(t.First),
    elems(new value_type[t.Size])
{
    for (UINT i = 0; i < Size; i++)
        elems[i] = t.elems[i];
}

Array::~Array()
{
    delete[] elems;
    elems = nullptr;
}

// Оператор присвоєння (через swap із тимчасовим об'єктом)
Array& Array::operator=(const Array& t)
{
    Array tmp(t);
    swap(tmp);
    return *this;
}

Array::size_type Array::size() const { return Count; }
bool             Array::empty() const { return Count == 0; }
Array::size_type Array::capacity() const { return Size; }

// Збільшити ємність до newsize (якщо newsize > поточна)
void Array::resize(size_type newsize) throw(bad_alloc)
{
    if (newsize <= Size) return;

    value_type* data = new value_type[newsize];
    for (size_type i = 0; i < Count; i++)
        data[i] = elems[i];
    // нові слоти ініціалізуємо нулем
    for (size_type i = Count; i < newsize; i++)
        data[i] = 0.0;

    delete[] elems;
    elems = data;
    Size = newsize;
}

Array::reference Array::operator[](size_type index) throw(out_of_range)
{
    if (index < First || index >= First + Count)
        throw out_of_range("Індекс виходить за межі масиву");
    return elems[index - First];
}

Array::const_reference Array::operator[](size_type index) const throw(out_of_range)
{
    if (index < First || index >= First + Count)
        throw out_of_range("Індекс виходить за межі масиву");
    return elems[index - First];
}

// Додати елемент в кінець
void Array::push_back(const value_type& v)
{
    if (Count == Size)
        resize(Size * 2);   // подвоїти ємність
    elems[Count++] = v;
}

// Видалити останній елемент
void Array::pop_back()
{
    if (Count > 0)
        --Count;
}

// Обмін з іншим масивом
void Array::swap(Array& other)
{
    std::swap(elems, other.elems);
    std::swap(Size, other.Size);
    std::swap(Count, other.Count);
    std::swap(First, other.First);
}

// Заповнити всі наявні елементи значенням v
void Array::assign(const value_type& v)
{
    for (size_type i = 0; i < Count; i++)
        elems[i] = v;
}

ostream& operator<<(ostream& out, const Array& a)
{
    for (Array::size_type i = 0; i < a.Count; i++)
        out << a.elems[i] << "  ";
    out << endl;
    return out;
}

istream& operator>>(istream& in, Array& a)
{
    for (Array::size_type i = 0; i < a.Count; i++)
        in >> a.elems[i];
    return in;
}