#include "SceneDB.h"

#include <assert.h>

SceneDB* SceneDB::Instance;

SceneDB::SceneDB() {
    //db.reserve(ACTOR_NUMBER_MAX); // reserve size for all initial entries so we don't do it for each
    //for (const AddPair& pair : initialActorTable) {
    //    Entry& entry = AddEntry(pair.name, actorDescriptions[pair.init.id], pair.init);
    //}
}

// Adds an scene at the given index. The name must be unique.
SceneDB::Entry& SceneDB::AddEntry(const std::string& name, const std::string& desc, size_t index) {
    assert(!nameTable.contains(name)); // TODO this should maybe throw instead. We'll need to think about error handling
                                       // for mods that try to declare the same scene.

    if (db.size() < (index + 1)) {
        db.resize(index + 1);
    }
    Entry& newEntry = db.at(index);
    newEntry.entry.id = index;

    assert(!newEntry.entry.valid);

    nextFreeId = std::max(nextFreeId, index + 1);

    nameTable[name] = newEntry.entry.id;
    newEntry.SetName(name);
    newEntry.SetDesc(desc);

    newEntry.entry.valid = true;

    return newEntry;
}

// Adds an scene with the new SceneDBInit struct. The id assigned to the scene is dynamic. Use the return Entry or
// RetrieveId to get it.
SceneDB::Entry& SceneDB::AddEntry(const SceneDBInit& init) {
    Entry& entry = AddEntry(init.name, init.desc, nextFreeId);

    //entry.entry.category = init.category;

    return entry;
}

// Get the SceneDB::Entry for the given scene id.
SceneDB::Entry& SceneDB::RetrieveEntry(const int id) {
    static Entry invalid;
    if ((id < 0) || (id >= db.size())) {
        return invalid;
    }
    return db[id];
}

// Get the id for a given scene by name.
int SceneDB::RetrieveId(const std::string& name) {
    auto entry = nameTable.find(name);
    if (entry == nameTable.end()) {
        return -1;
    }

    return entry->second;
}

SceneDB::Entry::Entry() {
    entry.name = nullptr;
    entry.desc = nullptr;
}

SceneDB::Entry::Entry(const Entry& other) {
    entry = other.entry;
    SetName(other.name);
    SetDesc(other.desc);
}

SceneDB::Entry& SceneDB::Entry::operator=(const Entry& other) {
    entry = other.entry;
    SetName(other.name);
    SetDesc(other.desc);
    return *this;
}

void SceneDB::Entry::SetName(const std::string& newName) {
    name = newName;
    entry.name = name.c_str();
}

void SceneDB::Entry::SetDesc(const std::string& newDesc) {
    desc = newDesc;
    entry.desc = desc.c_str();
}

extern "C" SceneDBEntry* SceneDB_Retrieve(const int id) {
    return &SceneDB::Instance->RetrieveEntry(id).entry;
}

extern "C" int SceneDB_RetrieveId(const char* name) {
    return SceneDB::Instance->RetrieveId(name);
}
