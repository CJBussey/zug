//
// zug: transducers for C++
// Copyright (C) 2019 Juan Pedro Bolivar Puente
//
// This software is distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://boost.org/LICENSE_1_0.txt
//

#pragma once

#include <zug/skip.hpp>

namespace zug {

auto filter = [](auto predicate) {
    return [=](auto step) mutable {
        return [=](auto&& s, auto&&... is) mutable {
            return invoke(predicate, is...)
                       ? call(step, ZUG_FWD(s), ZUG_FWD(is)...)
                       : skip(step, ZUG_FWD(s), ZUG_FWD(is)...);
        };
    };
};

}
