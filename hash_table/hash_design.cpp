
// put collision items into a list
// linear probing design: https://www.geeksforgeeks.org/implementing-hash-table-open-addressing-linear-probing-cpp/

#include <iostream>
#include <vector>
#include <list>

using namespace std;

template <typename K, typename V>
class Node {
    K key;
    V val;
public:
    Node(K k, V v) {
        key = k;
        val = v;
    }
    bool operator==(const Node &n) {
        return n.getKey() == key;
    }
    K getKey() {
        return key;
    }
    V getVal() {
        return val;
    }
};

template <typename K, typename V>
class Hash {
    static const int capacity = 10;
    vector<list<Node<K,V>>> items;
public:
    Hash() : items(capacity) {}
    int hashFun(K k) {
        return k % capacity;
    }
    void put(K k, V v) {
        int key = hashFun(k);
        list<Node<K,V>> &tmp = items[key];
        for (auto it = tmp.begin(); it != tmp.end(); it++) {
            if (it->getKey() == k) {
                tmp.erase(it);
                break;
            }
        }

        Node<K,V> n(k,v);
        tmp.push_front(n);
    }

    V get(K k) {
        int key = hashFun(k);
        list<Node<K,V>> &tmp = items[key];
        for (auto n : tmp) {
            if (n.getKey() == k)
                return n.getVal();
        }
        return (V)NULL;
    }
};

int main() {
    Hash<string,string> h;
    h.put(1,"one");
    h.put(2,"two");
    h.put(3,"three");
    cout << h.get(2) << endl;
    h.put(2,"wow");
    cout << h.get(2) << endl;
    return 0;
}