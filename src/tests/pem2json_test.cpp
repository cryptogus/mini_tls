#include "base64.hpp"
#include "get_info.hpp"
#include "der2json.hpp"
#include <fstream>

int main()
{
    std::ifstream f("sample_cert.pem");
    std::string cert = PEM::get_certificate_core(f);
    auto v = base64::decode(cert);
    std::stringstream ss(std::string(v.begin(), v.end()));
    Json::Value jv = json::der2json(ss);
    std::cout << jv.toStyledString() << std::endl;

    return 0;
}
