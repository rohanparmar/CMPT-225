#include "BinaryHeap.h"
#include "dsexceptions.h"
#include <utility>
#include <iostream>

using namespace std;

template <typename Object>

class ItemPriority
{
public:

    pair<Object, int> COMP(Object item, int priority)
    {
        return make_pair(item, priority);
    }

    int compPriority(pair<Object, int> P1, pair<Object, int> P2)
    {
        if (P1.second > P2.first)
        {
            return P1.second;
        }
        else
        {
            return P2.second;
        }
    }


};

template <typename Object>

class PQ
{

public:

    void insert(Object& item, int priority)
    {
        pair<Object, int> P1 = COMP(item, priority);
        insert(P1);
    }

    Object& extractMin()
    {
        Object min = findMin();
        deleteMin();
        return min;
    }
};

int main()
{
    cout << "Hello World";
}