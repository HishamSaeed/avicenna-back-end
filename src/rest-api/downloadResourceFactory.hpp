#pragma once

#include "IResourceFactory.hpp"
#include <string>
#include <tuple>

class DownloadResourceFactory : public IResourceFactory {
    public: 
        DownloadResourceFactory();
        std::shared_ptr<restbed::Resource> get_resource() const final;
    
    private:

        string get_path_parameters(const shared_ptr<restbed::Session> session);
        void get_handler(const shared_ptr<restbed::Session>);
        
        shared_ptr<restbed::Resource> _resource;

};