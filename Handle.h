//
// Created by user on 28/6/18.
//

#ifndef LEARN_CPP_PLURALSIGHT_HANDLE_H
#define LEARN_CPP_PLURALSIGHT_HANDLE_H

#endif //LEARN_CPP_PLURALSIGHT_HANDLE_H

#pragma once

#ifdef _DEBUG
    #include <crtdbg.h>
    #define ASSERT _ASSERTE
#else
    #define ASSERT __noop
#endif

template <typename T>
struct HandleTraits{
    using Type = T;

    static Type Invalid() noexcept {
        return nullptr;
    }
};

