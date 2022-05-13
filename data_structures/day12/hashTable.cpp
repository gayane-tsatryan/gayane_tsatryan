#include <iostream>
#include <list>
using namespace std;

template <class TKey, class TValue>
class HashTableNodePair
{
public:
  TKey _key;
  TValue _value;

  HashTableNodePair(TKey key, TValue value)
  {
    _key = key;
    _value = value;
  }
};
template <class TKey, class TValue>
class HashTableArrayNode
{
public:
  list<HashTableNodePair<TKey, TValue>> *_items;

  void Add(TKey key, TValue value)
  {
    if (_items == NULL)
    {
      _items = new list<HashTableNodePair<TKey, TValue>>();
    }
    else
    {

      for (HashTableNodePair<TKey, TValue> pair : _items)
      {
        if (pair->_key == key)
        {
          cout << "key exists!";
          return;
        }
      }
    }

    _items->push_back(new HashTableNodePair<TKey, TValue>(key, value));
  }

  void Update(TKey key, TValue value)
  {
    bool updated = false;

    if (_items != NULL)
    {

      for (HashTableNodePair<TKey, TValue> pair : _items)
      {
        if (pair->_key == key)
        {

          pair->_value = value;
          updated = true;
          break;
        }
      }
    }

    if (!updated)
    {
      cout << "key not found!";
      return;
    }
  }

  bool TryGetValue(TKey key, TValue value)
  {
    // TValue value;
    bool found = false;

    if (_items != NULL)
    {
      for (HashTableNodePair<TKey, TValue> pair : _items)
      {
        if (pair->_key == key && value == pair->_value)
        {

          found = true;
          break;
        }
      }
    }
    return found;
  }

public:
  bool Remove(TKey key)
  {
    bool removed = false;
    if (_items != NULL)
    {
      list<HashTableNodePair<TKey, TValue>> *current = _items->front();

      while (current != NULL)
      {
        if (current->_value->_key == key)
        {
          _items->Remove(current);
          removed = true;
          break;
        }
        current = current.Next;
      }
    }
    return removed;
  }

  void Clear()
  {
    if (_items != NULL)
    {
      _items->Clear();
    }
  }
};

template <class TKey, class TValue>
class HashTableArray
{
public:
  HashTableArrayNode<TKey, TValue> *_array;

  HashTableArray(int capacity)
  {
    _array = new HashTableArrayNode<TKey, TValue>[capacity];
  }

private:
  int GetIndex(TKey key)
  {
    int a = rand() % 10000 + 1;
    return abs((a) % Capacity);
  }

public:
  int Capacity = sizeof(_array) / sizeof(_array[0]);

  void Add(TKey key, TValue value)
  {
    int index = GetIndex(key);
    HashTableArrayNode<TKey, TValue> *nodes = _array[index];

    if (nodes == NULL)
    {
      nodes = new HashTableArrayNode<TKey, TValue>;
      _array[index] = nodes;
    }

    nodes->Add(key, value);
  }
};
template <class TKey, class TValue>
class HashTable
{

public:
  const double _fillFactor = 0.7;

  int _maxItemsAtCurrentSize;

  int _count;

  HashTableArray<TKey, TValue> *_array;

public:
  HashTable(int initialCapacity)
  {
    if (initialCapacity < 1)
    {
      cout << "initialCapacity is smaller than  1";
      return;
    }

    _array = new HashTableArray<TKey, TValue>(initialCapacity);

    _maxItemsAtCurrentSize = (int)(initialCapacity * _fillFactor) + 1;
  }

  void Add(TKey key, TValue value)
  {

    if (_count >= _maxItemsAtCurrentSize)
    {

      HashTableArray<TKey, TValue> *largerArray = new HashTableArray<TKey, TValue>(_array->Capacity * 2);
      
      for (HashTableNodePair<TKey, TValue> node : _array->Items)
      {
        largerArray->Add(node->_key, node->_value);
      }

      _array = largerArray;

      _maxItemsAtCurrentSize = (int)((_array->Capacity * _fillFactor) + 1);
    }

    _array.Add(key, value);
    _count++;
  }
};

int main()
{

  HashTable<int, string> *instance = new HashTable<int, string>(5);

  instance->Add(0, "i");
  instance->Add(1, "n");
  instance->Add(2, "s");
  instance->Add(3, "t");
  instance->Add(4, "g");

  /* for (int item=0; item<instance->_array->Capacity; item++) {
       //cout << instance->_array->_array->_items->
   }*/
  return 0;
}
