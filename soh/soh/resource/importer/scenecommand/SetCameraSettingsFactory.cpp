#include "soh/resource/importer/scenecommand/SetCameraSettingsFactory.h"
#include "soh/resource/type/scenecommand/SetCameraSettings.h"
#include "spdlog/spdlog.h"

namespace Ship {
std::shared_ptr<Resource> SetCameraSettingsFactory::ReadResource(uint32_t version, std::shared_ptr<BinaryReader> reader)
{
	auto resource = std::make_shared<SetCameraSettings>();
	std::shared_ptr<ResourceVersionFactory> factory = nullptr;

	switch (version)
	{
	case 0:
		factory = std::make_shared<SetCameraSettingsFactoryV0>();
		break;
	}

	if (factory == nullptr)
	{
		SPDLOG_ERROR("Failed to load SetCameraSettings with version {}", version);
		return nullptr;
	}

	factory->ParseFileBinary(reader, resource);

	return resource;
}

void Ship::SetCameraSettingsFactoryV0::ParseFileBinary(std::shared_ptr<BinaryReader> reader,
                                        std::shared_ptr<Resource> resource)
{
	std::shared_ptr<SetCameraSettings> setCameraSettings = std::static_pointer_cast<SetCameraSettings>(resource);
	ResourceVersionFactory::ParseFileBinary(reader, setCameraSettings);

	ReadCommandId(setCameraSettings, reader);
	
    setCameraSettings->settings.cameraMovement = reader->ReadInt8();
    setCameraSettings->settings.worldMapArea = reader->ReadInt32();
}

} // namespace Ship