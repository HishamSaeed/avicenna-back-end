#pragma once

#include "IServiceSettingsFactory.hpp"

class AvicenaServiceSettingsFactory : public IServiceSettingsFactory {

public:

    AvicenaServiceSettingsFactory();
    shared_ptr<restbed::Settings> get_settings() const final;

private:

    std::shared_ptr<restbed::Settings> _settings;

};
