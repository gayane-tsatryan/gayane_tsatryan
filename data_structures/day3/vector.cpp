#include <iostream>
using namespace std;
template <typename T>

class vectorClass {
    T* _arr;
    int _capacity;
    int _size;

public:
    vectorClass()
    {
        _arr = new T[32];
        _capacity = 32;
        _size = 0;
    }
    void add(T data)
    {

        if (_size == _capacity) {
            T* temp = new T[2 * _capacity];
            for (int i = 0; i < _capacity; i++) {
                temp[i] = _arr[i];
            }

            delete[] _arr;
            _capacity *= 2;
            _arr = temp;
        }
        _arr[_size] = data;
        _size++;
    }

    void addAt(T data, int index)
    {

        if (_size == _capacity) {
            T* temp = new T[2 * _capacity];
            for (int i = 0; i < _capacity; i++) {
                temp[i] = _arr[i];
            }

            delete[] _arr;
            _capacity *= 2;
            _arr = temp;
        }

        for (int i = _size; i > index; i--) {
            _arr[i] = _arr[i - 1];
        }
        _arr[index] = data;
        _size++;
    }

    T get(int index)
    {
        if (index < _size)
            return _arr[index];
    }

    void remove()
    {
        _size--;
    }
    void removeAll()
    {
        while (_size) {
            remove();
        }
    }

    void removeAt(int index)
    {
        if (index <= _size) {
            for (int i = index; i < _size - 1; i++) {
                _arr[i] = _arr[i + 1];
            }
        }
        remove();
    }
    int size() const
    {
        return _size;
    }
    int getCapacity() const
    {
        return _capacity;
    }
    void print()
    {
        for (int i = 0; i < _size; i++) {
            cout << _arr[i] << " ";
        }
        cout << endl;
    }
    template <typename Type>
    friend ostream& operator<<(ostream& out, const vectorClass<Type>& instance)
    {
        for (int i = 0; i < instance.size(); i++) {
            out << instance._arr[i] << " ";
        }

        return out;
    }

    const T operator[](int index);
};

template <typename T>
const T vectorClass<T>::operator[](int index)
{
    return _arr[index];
}

int main()
{
    vectorClass<int> v;
    v.add(10);
    v.add(20);
    v.add(30);
    v.add(40);
    v.add(50);
    cout << v[1] << endl;
    cout << v;
    cout << "Vector size : " << v.size() << endl;
    cout << "Vector capacity : " << v.getCapacity() << endl;
    cout << v;
    cout << "Vector elements : ";
    v.print();
    v.addAt(100, 3);
    cout << "vector update" << endl;
    v.print();
    cout << "Remove" << endl;
    v.removeAll();
    v.print();
    return 0;
}
