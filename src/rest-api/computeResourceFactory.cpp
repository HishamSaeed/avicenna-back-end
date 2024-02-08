#include "computeResourceFactory.hpp"
#include "json.hpp"
#include "../solver/dummySolver.hpp"

#include <iostream>
ComputeResourceFactory::ComputeResourceFactory() {
    _resource = make_shared<restbed::Resource>();
    _resource->set_path(
        "/{problem: -l|-psf|-fs}"
    );
    _resource->set_method_handler("GET", 
        [&](const shared_ptr<restbed::Session> session) {
            get_handler(session);
        });

}

string ComputeResourceFactory::to_json(string result) {
    ostringstream str_stream;
    str_stream << result;
    nlohmann::json jsonResult = {
        {"result", str_stream.str()}
    };
    return jsonResult.dump();
}

string ComputeResourceFactory::get_path_parameters 
(const shared_ptr<restbed::Session> session) {

    const auto& request = session->get_request();
    const auto problem = request->get_path_parameter("problem");
    return problem;
}

shared_ptr<restbed::Resource> ComputeResourceFactory::get_resource() const {
        return _resource;
}

void ComputeResourceFactory::get_handler(const shared_ptr<restbed::Session> session) {
    const auto problem = get_path_parameters(session);
    auto problemName =  DummySolver::getProblemName(problem);
    auto content = to_json(problemName);
    session->close(restbed::OK, content, 
        {{"Content-Length", to_string(content.size())}});
}