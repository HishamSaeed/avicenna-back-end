
#pragma once

#include "IService.hpp"

#include "IResourceFactory.hpp"
#include "IServiceSettingsFactory.hpp"

class AvicenaService : public IService {

public:

    AvicenaService(
        shared_ptr<IResourceFactory> resourceFactory, 
        shared_ptr<IServiceSettingsFactory> settingsFactory);
    void start() final;
    void addResource(shared_ptr<IResourceFactory> resourceFactory);

private:

    restbed::Service _service;
    shared_ptr<IServiceSettingsFactory> _settings_factory;

};