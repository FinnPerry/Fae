#ifndef FAE_EVENT_GUARD
#define FAE_EVENT_GUARD

#include <algorithm>
#include <vector>

namespace fae
{

template<class ... arg_types>
class event
{
public:
    using callback = void(*)(arg_types...);

    event() = default;

    ~event() = default;

    void invoke(arg_types ... args);

    void add_callback(callback func);

    void remove_callback(callback func);

private:
    std::vector<callback> listners_;
};

template<class ... arg_types>
void event<arg_types...>::invoke(arg_types ... args)
{
    for (auto i : listners_)
    {
        i(args...);
    }
}

template<class ... arg_types>
void event<arg_types...>::add_callback(callback func)
{
    listners_.push_back(func);
}

template<class ... arg_types>
void event<arg_types...>::remove_callback(callback func)
{
    auto i{std::find(listners_.begin(), listners_.end(), func)};
    if (i != listners_.end())
    {
        listners_.erase(i);
    }
}

}

#endif
