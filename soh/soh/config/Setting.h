#pragma once

#include "libultraship/color.h"
#include <functional>
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

namespace Ship {

class Setting final {
public:
    using ValueType = std::variant<bool, int32_t, float, std::string, Color_RGBA8, Color_RGB8>;
    using HookFuncType = std::function<void()>;

    Setting(const std::string& name, const ValueType defaultValue);
    ~Setting();

    bool Bool() const;
    int32_t Integer() const;
    float Float() const;
    std::string String() const;
    Color_RGBA8 Color() const;
    Color_RGB8 Color24() const;

    const std::string& GetName() const { return Name; }

    bool operator=(const bool newValue);
    int32_t operator=(const int32_t newValue);
    float operator=(const float newValue);
    std::string operator=(const std::string newValue);
    Color_RGBA8 operator=(const Color_RGBA8 newValue);
    Color_RGB8 operator=(const Color_RGB8 newValue);

    void AddHook(HookFuncType hook);
    void CallHooks() const;

private:
    std::string Name;
    ValueType Value;
    ValueType DefaultValue;
    std::vector<HookFuncType> Hooks;
};

class SettingCollection final {
public:
    static SettingCollection* GetInstance();

    Setting* GetSetting(const std::string& name);
    bool AddSetting(Setting* setting);
    bool RemoveSetting(const std::string& name);

    bool Contains(const std::string& name);

    using ForAllFunc = std::function<void(Setting&)>;
    void ForAll(ForAllFunc func) const;

    void Save(); // TODO
    void Load(); // TODO

private:
    SettingCollection() = default;

    std::unordered_map<std::string, Setting*> Settings;
};

}