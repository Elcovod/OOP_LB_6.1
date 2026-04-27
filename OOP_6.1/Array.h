#pragma once
#include <iostream>
#include <stdexcept>
#include <exception>
using namespace std;

// Числовий контейнер змінної довжини (за зразком Лістинг 2)
class Array
{
public:
    typedef unsigned int        UINT;
    typedef double              value_type;
    typedef double* iterator;
    typedef const double* const_iterator;
    typedef double& reference;
    typedef const double& const_reference;
    typedef std::size_t         size_type;

private:
    static const size_type minsize = 10; // мінімальний початковий розмір
    size_type   Size;   // виділено пам'яті (ємність)
    size_type   Count;  // фактична кількість елементів
    size_type   First;  // значення індексу першого елемента
    value_type* elems;  // вказівник на масив елементів

public:
    explicit Array(const size_type& n = minsize)
        throw(bad_alloc, invalid_argument);

    Array(const Array&)
        throw(bad_alloc);

    Array(const iterator first, const iterator last)
        throw(bad_alloc, invalid_argument);

    Array(const size_type first, const size_type last)
        throw(bad_alloc, invalid_argument);

    ~Array();

    Array& operator=(const Array&);

    // --- ітератори ---
    iterator        begin() { return elems; }
    const_iterator  begin() const { return elems; }
    iterator        end() { return elems + Count; }
    const_iterator  end()   const { return elems + Count; }

    // --- розміри ---
    size_type   size()     const;   // поточна кількість елементів
    bool        empty()    const;   // чи порожній масив
    size_type   capacity() const;   // ємність (виділена пам'ять)
    void        resize(size_type newsize) throw(bad_alloc);

    // --- доступ до елементів ---
    reference       operator[](size_type i) throw(out_of_range);
    const_reference operator[](size_type i) const throw(out_of_range);

    reference       front() { return elems[0]; }
    const_reference front() const { return elems[0]; }
    reference       back() { return elems[Count - 1]; }
    const_reference back()  const { return elems[Count - 1]; }

    // --- модифікатори ---
    void push_back(const value_type& v);    // додати елемент в кінець
    void pop_back();                        // видалити останній елемент
    void clear() { Count = 0; } // очистити (не звільняти пам'ять)
    void swap(Array& other);               // обмін з іншим масивом
    void assign(const value_type& v);      // заповнити всі елементи значенням v

    friend ostream& operator<<(ostream& out, const Array& a);
    friend istream& operator>>(istream& in, Array& a);
};