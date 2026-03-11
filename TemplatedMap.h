#ifndef TEMPLATEDMAP_H
#define TEMPLATEDMAP_H

#include <map>


/**
 * @brief TemplatedMap
 *  TemplatedMap provides a general interface for management of key value pairs using std::map
 *  Enables efficient data retrieval and storage for a range of data types
 *  Furthermore the templated map acts as a wrapper around std::map, providing the specific map functionality
 *  This class follows the solid principles as it only role is to generate an std::map key value pair
 *
 * @date   June 2024
 * @author William Halling
 */
template<class Key, class Value>
class TemplatedMap
{
    public:

            /**
             * @brief getData()
             * Used to obtain the value linked to the given key from the map
             * @param Key the key value to look up in the map
             * @return const Value& the value that is linked to the given key
             */
        const Value& getData(const Key& key) const;


            /**
             * @brief setMappedData()
             * sets the value associated with the given key in the map
             * @param key the key value to look up in the map
             * @param value the value to be linked / associated with the key
             */
        void setMappedData(const Key& key, const Value& value);


            /**
             * @brief contains()
             * Checks if the map contains the given key
             * @param key the key to check if it exists in the current templated map
             * @return ture if the key exists in the map, false otherwise
             */
        bool contains(const Key& key) const;


    private:
        std::map<Key, Value> m_MappedData; /// The map of key value data
};



template<class Key, class Value>
const Value& TemplatedMap<Key, Value>::getData(const Key& key) const
{
    typename std::map<Key, Value>::const_iterator mapIterator = m_MappedData.find(key);

    if(mapIterator != m_MappedData.end())
    {
        return mapIterator->second;
    }
}


template<class Key, class Value>
void TemplatedMap<Key, Value>::setMappedData(const Key& key, const Value& value)
{
    m_MappedData[key] = value;
}


template<class Key, class Value>
bool TemplatedMap<Key, Value>::contains(const Key& key) const
{
    return m_MappedData.find(key) != m_MappedData.end();
}


#endif // TEMPLATEDMAP_H
