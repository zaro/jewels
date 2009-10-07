#ifndef PYTHON_HELPER_H
#define PYTHON_HELPER_H

template<typename T_>
inline T_ * get_pointer(std::tr1::shared_ptr<T_> const & p)
{
    return p.get();
}

//Make Boost.Python work with std::tr1::shared_ptr<const>
template<typename T_>
inline T_ * get_pointer(std::tr1::shared_ptr<const T_> const & p)
{
    return const_cast<T_*>(p.get());
}


#endif // PYTHON_HELPER_H