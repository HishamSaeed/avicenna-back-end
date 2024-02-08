#include "avicenaServiceSettingFactory.hpp"

AvicenaServiceSettingsFactory::AvicenaServiceSettingsFactory() {
    _settings = make_shared<restbed::Settings>();
    _settings->set_port(8080);
    _settings->set_default_header("Connection", "close");
    _settings->set_default_header( "Access-Control-Allow-Origin", "*");
}

shared_ptr<restbed::Settings> AvicenaServiceSettingsFactory::get_settings() const {
    return _settings;
}