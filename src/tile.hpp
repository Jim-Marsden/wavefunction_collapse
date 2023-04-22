//
// Created by jim on 4/22/23.
//

#pragma once
namespace wfc{
    template<class Data_T>
    struct tile{
        tile *up{}, *down{}, *left{}, *right{};
        Data_T data{};
    };
}