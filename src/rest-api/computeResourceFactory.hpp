#pragma once

#include "IResourceFactory.hpp"
#include <string>
#include <tuple>

class ComputeResourceFactory : public IResourceFactory {
    public: 
        ComputeResourceFactory();
        std::shared_ptr<restbed::Resource> get_resource() const final;
    
    private:

        string get_path_parameters(const shared_ptr<restbed::Session> session);
        string to_json(string result);
        void get_handler(const shared_ptr<restbed::Session>);
        
        shared_ptr<restbed::Resource> _resource;

};