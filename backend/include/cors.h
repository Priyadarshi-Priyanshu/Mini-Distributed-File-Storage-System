// cors.h
#pragma once
#include "crow.h"

struct CORSHandler {
    struct context {};

    void before_handle(crow::request& req, crow::response& res, context&) {
        res.add_header("Access-Control-Allow-Origin", "*");
        res.add_header("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
        res.add_header("Access-Control-Allow-Headers", "Content-Type");
        
        if (req.method == "OPTIONS"_method) {
            res.code = 204; // No Content
            res.end();
        }
    }

    void after_handle(crow::request& /*req*/, crow::response& res, context&) {
        res.add_header("Access-Control-Allow-Origin", "*");
    }
};
