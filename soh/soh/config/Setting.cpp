#include "Setting.h"

#include <assert.h>
#include <algorithm>

namespace Ship {

Setting::Setting(const std::string& name, const ValueType defaultValue) :
    Name(name),
    Value(defaultValue),
    DefaultValue(defaultValue)
{
    SettingCollection::GetInstance()->AddSetting(this);
    CallHooks();
}

Setting::~Setting() {
    SettingCollection::GetInstance()->RemoveSetting(Name);
}

bool Setting::Bool() const {
    assert(std::holds_alternative<bool>(Value));
    return *std::get_if<bool>(&Value);
}

int32_t Setting::Integer() const {
    assert(std::holds_alternative<int32_t>(Value));
    return *std::get_if<int32_t>(&Value);
}

float Setting::Float() const {
    assert(std::holds_alternative<float>(Value));
    return *std::get_if<float>(&Value);
}

std::string Setting::String() const {
    assert(std::holds_alternative<std::string>(Value));
    return *std::get_if<std::string>(&Value);
}

Color_RGBA8 Setting::Color() const {
    assert(std::holds_alternative<Color_RGBA8>(Value));
    return *std::get_if<Color_RGBA8>(&Value);
}

Color_RGB8 Setting::Color24() const {
    assert(std::holds_alternative<Color_RGB8>(Value));
    return *std::get_if<Color_RGB8>(&Value);
}

bool Setting::operator=(const bool newValue) {
    Value = newValue;
    CallHooks();
    return newValue;
}

int32_t Setting::operator=(const int32_t newValue) {
    Value = newValue;
    CallHooks();
    return newValue;
}

float Setting::operator=(const float newValue) {
    Value = newValue;
    CallHooks();
    return newValue;
}

std::string Setting::operator=(const std::string newValue) {
    Value = newValue;
    CallHooks();
    return newValue;
}

Color_RGBA8 Setting::operator=(const Color_RGBA8 newValue) {
    Value = newValue;
    CallHooks();
    return newValue;
}

Color_RGB8 Setting::operator=(const Color_RGB8 newValue) {
    Value = newValue;
    CallHooks();
    return newValue;
}

void Setting::AddHook(HookFuncType hook) {
    Hooks.push_back(hook);
}

void Setting::CallHooks() const {
    std::for_each(Hooks.begin(), Hooks.end(), [](const HookFuncType& hook) {
        hook();
    });
}

SettingCollection* SettingCollection::GetInstance() {
    static SettingCollection* instance = new SettingCollection();
    return instance;
}

Setting* SettingCollection::GetSetting(const std::string& name) {
    auto iter = Settings.find(name);
    if (iter != Settings.end()) {
        return iter->second;
    }

    // TODO warning
    return nullptr;
}

bool SettingCollection::AddSetting(Setting* setting) {
    if (Settings.contains(setting->GetName())) {
        return false;
    }

    Settings[setting->GetName()] = setting;

    return true;
}

bool SettingCollection::RemoveSetting(const std::string& name) {
    return Settings.erase(name) > 0;
}

bool SettingCollection::Contains(const std::string& name) {
    return Settings.find(name) != Settings.end();
}

void SettingCollection::ForAll(ForAllFunc func) const {
    std::for_each(Settings.begin(), Settings.end(), [&func](auto& iter) {
        func(*iter.second);
    });
}

//void SettingCollection::Save();
//void SettingCollection::Load();

//SettingCollection::SettingCollection() {}

namespace {

static std::unordered_map<std::string, Setting*> SettingsAddedViaC;

}

extern "C" void Setting_Add(const char* name) {
    SettingsAddedViaC[name] = new Setting(name, false);
}

extern "C" void Setting_Remove(const char* name) {
    auto iter = SettingsAddedViaC.find(name);
    if (iter == SettingsAddedViaC.end()) {
        // TODO warn
        return;
    }

    Setting* toRemove = iter->second;
    SettingsAddedViaC.erase(iter);
    delete toRemove;
}

}