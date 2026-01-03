#include "base64.hpp"
#include "get_info.hpp"
#include "der2json.hpp"
#include <fstream>

int main()
{
    std::ifstream f("sample_cert.pem");
    if (!f.is_open())
    {
        std::cerr << "Failed to open PEM file." << std::endl;
        return 1;
    }
    std::string cert = PEM::get_certificate_core(f);
    auto v = base64::decode(cert);
    std::cout << "DER bytes size: " << v.size() << std::endl;
    std::stringstream ss(std::string(v.begin(), v.end()));
    Json::Value jv = json::der2json(ss);
    // std::cout << jv << std::endl;

    // Save JSON to file
    std::ofstream json_out("cert.json");
    if (!json_out.is_open())
    {
        std::cerr << "Failed to open cert.json for writing." << std::endl;
        return 1;
    }

    Json::StreamWriterBuilder writer;
    writer["indentation"] = "  "; // Pretty print with 2 spaces
    std::unique_ptr<Json::StreamWriter> jsonWriter(writer.newStreamWriter());
    jsonWriter->write(jv, &json_out);

    std::cout << "JSON saved to cert.json" << std::endl;


    return 0;
}
