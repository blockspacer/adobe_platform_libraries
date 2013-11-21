/*
    Copyright 2013 Adobe
    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*/
/*************************************************************************************************/

#ifndef ADOBE_MENU_SYSTEM_HPP
#define ADOBE_MENU_SYSTEM_HPP

/*************************************************************************************************/

#include <adobe/config.hpp>

#include <adobe/name.hpp>
#include <adobe/future/enum_ops.hpp>

#include <boost/function.hpp>
#include <boost/noncopyable.hpp>
#include <boost/signals2.hpp>
#include <boost/cstdint.hpp>

/****************************************************************************************************/

namespace adobe {

/****************************************************************************************************/

class menu_system_t : boost::noncopyable
{
public:
    enum modifier_set_t
    {
        modifier_none_k     = 0,
        modifier_option_k   = 1L << 0,
        modifier_alt_k      = modifier_option_k,
        modifier_control_k  = 1L << 1,
        modifier_shift_k    = 1L << 3
    };

    typedef boost::function<void ()>    item_callback_t;
    typedef boost::signals2::connection connection_t;

    menu_system_t();

    ~menu_system_t();

    void            insert_menu(name_t name);
    void            insert_item(name_t          parent_name,
                                name_t          name,
                                boost::uint16_t cmd_key = 0,
                                modifier_set_t  modifier_set = modifier_none_k);
    void            insert_separator(name_t parent_name);
    void            remove(name_t name);

    void            enable_menu_item(name_t name, bool enabled);
    void            mark_menu_item(name_t name, bool marked);

    connection_t    monitor_menu_item(name_t name, const item_callback_t& callback);

    struct implementation_t;

private:
    implementation_t* object_m;
};

/****************************************************************************************************/

ADOBE_DEFINE_BITSET_OPS(menu_system_t::modifier_set_t)

/****************************************************************************************************/

} // namespace adobe

/****************************************************************************************************/

#endif

/****************************************************************************************************/
