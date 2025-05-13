#include "crow.h"
#include "cors.h"  // include the CORS handler

int main() {
    crow::App<CORSHandler> app;  // inject CORSHandler as middleware

    CROW_ROUTE(app, "/<string>")([](std::string name){
        crow::json::wvalue response;
        response["message"] = "Hello, " + name + "!";
        return response;
    }); 

    app.port(18080).multithreaded().run();
}
