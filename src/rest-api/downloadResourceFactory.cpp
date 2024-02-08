#include "downloadResourceFactory.hpp"
#include "json.hpp"
#include "../solver/dummySolver.hpp"

#include <iostream>
#include <fstream>
DownloadResourceFactory::DownloadResourceFactory() {
    _resource = make_shared<restbed::Resource>();
    _resource->set_path(
        "/resources/item"
    );
    _resource->set_method_handler("GET", 
        [&](const shared_ptr<restbed::Session> session) {
            get_handler(session);
        });

}

shared_ptr<restbed::Resource> DownloadResourceFactory::get_resource() const {
        return _resource;
}

void DownloadResourceFactory::get_handler(const shared_ptr<restbed::Session> session) {
    const std::string file_path = "test.txt";
    // Open the file
    std::ifstream file(file_path);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << file_path << std::endl;
        return;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string file_content = buffer.str();
    // Close the file
    file.close();

    std::stringstream sizeStream;
    sizeStream << std::hex << file_content.size();
    session->yield(restbed::OK, sizeStream.str() + "\r\n" + file_content + "\r\n", { { "Transfer-Encoding", "chunked" } }, [ ]( const shared_ptr<restbed::Session> session )
        {
            session->close( "0\r\n\r\n" );
        }
    );
}