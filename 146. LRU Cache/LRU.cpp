#include <unordered_map>
#include <list>
#include <iostream>
using namespace std;

class LRUCache
{
private:
    int remain;
    unordered_map<int, list<pair<int, int>>::iterator> key2note;
    // 因为这是需要通过数值再找到节点所在的位置，所以需要一个key值对应，列表中的一个迭代器，列表中存放的是key-value对。
    list<pair<int, int>> cache;

public:
    LRUCache(int capacity)
    {
        remain = capacity;
    }

    void put(int key, int value)
    {
        pair<int, int> newNode = make_pair(key, value);
        if (key2note.find(key) != key2note.end()) // 如果在哈希表中已经存在这个节点，那么就将原节点删除
            cache.erase(key2note[key]);
        else
        {                    // 如果哈希表中还没有这个节点，这是一个新节点，那么分两种情况讨论
            if (remain == 0) // 已经没有剩余空间
            // 此时排在队尾的就是最久没有使用的节点
            {
                key2note.erase(cache.back().first); // 先在哈希表中将这个key抹去
                cache.pop_back();                   // 链表中删除最后一个节点
            }
        }

        // 剩下的步骤与if无关，也就是说无论什么操作都要将这个节点插到链表的头部
        cache.push_front(newNode);
        key2note[key] = cache.begin();
        remain = (remain == 0 ? 0 : remain - 1);
    }

    int get(int key)
    {
        if (key2note.find(key) == key2note.end())
            return -1;
        else
        {
            pair<int, int> node = *key2note[key]; // 先要取出保存在key2node中的节点指针
            cache.erase(key2note[key]);           // 因为哈希表中存放了key所对应的在list中的指针，所以才得以删除
            cache.push_front(node);               // 放在list头
            key2note[key] = cache.begin();        // 还是将这个迭代器指针再更新进哈希表
            return node.second;                   // 返回哈希表中存放的这个key对应的value
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {}