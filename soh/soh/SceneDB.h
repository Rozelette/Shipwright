#pragma once
#include <libultraship/libultra.h>
#include "z64scene.h"

enum SceneType {
    SCENETYPE_OVERWORLD,
    SCENETYPE_DUNGEON,
    SCENETYPE_BOSS,
    SCENETYPE_OTHER
};

typedef struct {
    const char* name;
    const char* desc;
    u32 valid;
    s32 id;
    const char* titleCard;
    u32 sceneDrawConfig;
    u32 eponaAllowed;
    SceneType type;
    struct {
        u8 bButton;
        u8 bottles;
        u8 tradeItems;
        u8 hookshot;
        u8 ocarina;
        u8 warpSongs;
        u8 sunsSong;
        u8 farores;
        u8 dinsNayrus;
        u8 all;
    } restrictions;
} SceneDBEntry;

#ifdef __cplusplus

#include <string>
#include <unordered_map>
#include <vector>

struct SceneDBInit {
    std::string name;
    std::string desc;
    std::string titleCard; // TODO copy
    u32 sceneDrawConfig = 0; // TODO default
    bool eponaAllowed = false;
    SceneType type = SCENETYPE_OTHER;
    struct {
        bool bButton = false;
        bool bottles = false;
        bool tradeItems = false;
        bool hookshot = false;
        bool ocarina = false;
        bool warpSongs = false;
        bool sunsSong = false;
        bool farores = false;
        bool dinsNayrus = false;
        bool all = false;
    } restrictions;
};

class SceneDB {
  public:
    static SceneDB* Instance;

    SceneDB();

    // Wrapper around SceneDBEntry so we get C++isms for the entries
    struct Entry {
        Entry();
        Entry(const Entry& other);
        Entry& operator=(const Entry& other);

        void SetName(const std::string& newName);
        void SetDesc(const std::string& newDesc);

        std::string name;
        std::string desc;
        SceneDBEntry entry;
    };
    Entry& AddEntry(const SceneDBInit& init);

    Entry& RetrieveEntry(const int id);
    int RetrieveId(const std::string& name);

  private:
    Entry& AddEntry(const std::string& name, const std::string& desc, size_t index);

    std::vector<Entry> db;
    std::unordered_map<std::string, int> nameTable;
    size_t nextFreeId = 0;
};

#else

SceneDBEntry* SceneDB_Retrieve(const int id);
int SceneDB_RetrieveId(const char* name);

#endif
