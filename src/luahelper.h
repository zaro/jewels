#ifndef LUAHELPER_H
#define LUAHELPER_H

extern "C" {

struct lua_State;

}

namespace luabind {

    template<class T>
    T* get_pointer(std::tr1::shared_ptr<T>& p)
    {
        return p.get();
    }

    template<class A>
    std::tr1::shared_ptr<const A>*
    get_const_holder(std::tr1::shared_ptr<A>*)
    {
        return 0;
    }
}


#endif // LUAHELPER_H