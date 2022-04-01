#include <unordered_map>
#include <list>
#include <iostream>

namespace cppcode { namespace common {

template <class Key, class Value>
class LRUCache {
public:
    typedef typename std::pair<Key, std::shared_ptr<Value>> CacheEntry;
    typedef typename std::list<CacheEntry> Container;
    typedef typename std::list<CacheEntry>::iterator Iterator;
    
    LRUCache(size_t capacity)
        : m_capacity(capacity)
    {
    }
    
    std::shared_ptr<Value> get(const Key& key)
    {
        auto it = m_keys.find(key);
        if (it != m_keys.end())
        {
            visit(it->second);
            return m_values.back().second;
        }
        
        return std::shared_ptr<Value>{};
    }
    
    void put(const Key& key, std::shared_ptr<Value> value)
    {
        auto it = m_keys.find(key);
        if (it != m_keys.end())
        {
            visit(it->second);
            m_values.back().second = std::move(value);
        }
        else if (m_values.size() >= m_capacity)
        {
            auto entryToReplaceIt = m_values.begin();
            m_keys.erase(entryToReplaceIt->first);
            entryToReplaceIt->first = key;
            entryToReplaceIt->second = std::move(value);
            visit(entryToReplaceIt);
            m_keys[key] = entryToReplaceIt;
        }
        else
        {
            auto newIt = m_values.emplace(m_values.end(), key, std::move(value));
            m_keys[key] = newIt;
        }
    }
private:
    void visit(Iterator& it)
    {
        if (it != m_values.end())
        {
            m_values.splice(m_values.end(), m_values, it);
        }
    }

    void printValues() const
    {
        for (const auto& entry : m_values)
        {
            std::cout << entry.second << " ";
        }
        std::cout << &std::endl;
    }

    std::unordered_map<Key, Iterator> m_keys;
    Container m_values;
    size_t m_capacity;
};

}}
