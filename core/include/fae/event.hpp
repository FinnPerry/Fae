#ifndef FAE_EVENT_GUARD
#define FAE_EVENT_GUARD

#include <functional>
#include <unordered_map>

namespace fae
{

template<class ... arg_types>
class event
{
public:
    using callback = std::function<void(arg_types...)>;

    event() = default;

    ~event() = default;

    void operator ()(arg_types ... args);

    int add_callback(callback func);

    void remove_callback(int id);

private:
    int next_id();

    std::unordered_map<int, callback> m_listners;
    int m_id_counter;
};

template<class ... arg_types>
void event<arg_types...>::operator ()(arg_types ... args)
{
    for (auto i{m_listners.begin()}; i != m_listners.end(); ++i)
    {
        i->second(args...);
    }
}

template<class ... arg_types>
int event<arg_types...>::add_callback(callback func)
{
    m_listners[next_id()] = func;
    return m_id_counter;
}

template<class ... arg_types>
void event<arg_types...>::remove_callback(int id)
{
    auto i{m_listners.find(id)};
    if (i != m_listners.end())
    {
        m_listners.erase(i);
    }
}

template<class ... arg_types>
int event<arg_types...>::next_id()
{
    do
    {
        ++m_id_counter;
    } while (m_listners.contains(m_id_counter));
    return m_id_counter;
}

}

#endif
