#include "./rest-api/avicenaService.hpp"
#include "./rest-api/avicenaServiceSettingFactory.hpp"
#include "./rest-api/computeResourceFactory.hpp"
#include "./rest-api/downloadResourceFactory.hpp"

int main(int argn, char **args) {

    auto computeResourceFactory = make_shared<ComputeResourceFactory>();
    auto downloadResourceFactory = make_shared<DownloadResourceFactory>();
    auto avicenaServiceSettingsFactory = 
        make_shared<AvicenaServiceSettingsFactory>();
    
    AvicenaService avicenaService {
        computeResourceFactory, avicenaServiceSettingsFactory};
    avicenaService.addResource(downloadResourceFactory);
    avicenaService.start();

    return EXIT_SUCCESS;
}