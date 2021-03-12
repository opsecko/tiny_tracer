#pragma once

#include <cctype>
#include <string>
#include <iostream>
#include <cstring>
#include <cstdio>

const size_t g_WatchedMax = 300;

class WFuncInfo 
{
public:
    WFuncInfo() : paramCount(0)
    {
    }

    WFuncInfo(const WFuncInfo& a)
    {
        this->dllName = a.dllName;
        this->funcName = a.funcName;
        this->paramCount = a.paramCount;
    }

    bool load(const std::string &line, char demiliter);

    bool isValid()
    {
        if (dllName.length() > 0 && funcName.length() > 0 && paramCount > 0) {
            return true;
        }
        return false;
    }

    std::string dllName;
    std::string funcName;
    size_t paramCount;
};

class FuncWatchList {
public:
    FuncWatchList()
        : funcs(0), funcsCount(NULL)
    {
        funcs = new WFuncInfo[g_WatchedMax];
    }

    ~FuncWatchList()
    {
        funcs = 0;
        delete []funcs;
    }

    size_t loadList(const char* filename);

    bool appendFunc(std::string& dllname, std::string& fname, size_t count);
    bool appendFunc(WFuncInfo &info);

    WFuncInfo *funcs;
    size_t funcsCount;
};

