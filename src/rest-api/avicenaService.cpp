#include "avicenaService.hpp"

AvicenaService::AvicenaService(
        shared_ptr<IResourceFactory> resourceFactory, 
        shared_ptr<IServiceSettingsFactory> settingsFactory) {
    _settings_factory = settingsFactory;
    _service.publish(resourceFactory->get_resource());
}

void AvicenaService::start() {
    _service.start(_settings_factory->get_settings());
}

void AvicenaService::addResource(shared_ptr<IResourceFactory> resourceFactory) {
    _service.publish(resourceFactory->get_resource());
}