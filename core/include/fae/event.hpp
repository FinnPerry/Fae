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

    std::unordered_map<int, callback> listners_;
    int id_counter_;
};

template<class ... arg_types>
void event<arg_types...>::operator ()(arg_types ... args)
{
    for (auto i{listners_.begin()}; i != listners_.end(); ++i)
    {
        i->second(args...);
    }
}

template<class ... arg_types>
int event<arg_types...>::add_callback(callback func)
{
    listners_[next_id()] = func;
    return id_counter_;
}

template<class ... arg_types>
void event<arg_types...>::remove_callback(int id)
{
    auto i{listners_.find(id)};
    if (i != listners_.end())
    {
        listners_.erase(i);
    }
}

template<class ... arg_types>
int event<arg_types...>::next_id()
{
    do
    {
        ++id_counter_;
    } while (listners_.contains(id_counter_));
    return id_counter_;
}

}

#endif
